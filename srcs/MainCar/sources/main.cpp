#include <pigpio.h>
#include <thread>
#include "JetSnailsCar.hpp"
#include "vehicle.h"
#include "VehicleInfoSubscriber.hpp"
#include "VehicleSubscriber.hpp"
#include "ControllerSubscriber.hpp"
#include "HornSubscriber.hpp"

// Função para publicar o estado do controlador
void publishControllerState(ControllerSubscriber& controllerSubscriber, zmq::socket_t& publisher) {
    const std::vector<std::string> controls = {
        "horn", "lightslow", "lightshigh", "break",
        "lightsleft", "lightsright", "lightsemergency", "lightspark"
    };

    for (const auto& control : controls) {
        std::string state = controllerSubscriber.getControlState(control);

        if (!state.empty()) {
            zmq::message_t message(control.size() + state.size() + 1);
            snprintf(static_cast<char*>(message.data()), message.size() + 1, "%s %s", control.c_str(), state.c_str());
            publisher.send(message, zmq::send_flags::none);
        }
    }
}

// Função que será executada em uma thread para leitura dos sensores
void readAndPublishSensorData(SpeedSensor& speedSensor, JetSnailsCar& delorean, vehicleSensors& vehicle_sensors, ControllerSubscriber& controllerSubscriber, zmq::socket_t& publisher_sensors) {
    float smoothedSpeed = 0.0f;  // Velocidade suavizada inicial
    const float minStep = 10.0f; // Incremento mínimo por iteração (aumentado para mais rapidez)
    const float maxStep = 100.0f; // Incremento máximo por iteração (aumentado para grandes diferenças)
    const float stepScale = 0.2f; // Fator dinâmico aumentado (20% da diferença)
    const int updateInterval = 30; // Intervalo de atualização reduzido para 30ms

    while (true) {
        // Leia a velocidade do sensor
        speedSensor.readData();
        float currentSpeed = speedSensor.getValue();  // Velocidade real do sensor
        std::cout << "read from sensor arduino: " << currentSpeed << std::endl;

        // Calcular a diferença entre a velocidade suavizada e a velocidade atual
        float speedDiff = currentSpeed - smoothedSpeed;

        // Determinar o passo com base em um fator dinâmico (mais rápido para grandes diferenças)
        float step = std::max(minStep, std::min(maxStep, std::abs(speedDiff) * stepScale));

        // Ajustar a velocidade suavizada mais rapidamente
        if (smoothedSpeed < currentSpeed) {
            smoothedSpeed += step;
            if (smoothedSpeed > currentSpeed) {
                smoothedSpeed = currentSpeed;  // Evitar ultrapassar
            }
        } else if (smoothedSpeed > currentSpeed) {
            smoothedSpeed -= step;
            if (smoothedSpeed < currentSpeed) {
                smoothedSpeed = currentSpeed;  // Evitar ultrapassar
            }
        }

        // Atualize o estado no veículo
        float old_speed = delorean.vehicle->getSpeed();
        delorean.vehicle->setSpeed(smoothedSpeed);

        // Notifique somente se houve alteração significativa
        if (old_speed != smoothedSpeed) {
            vehicle_sensors.onSpeedChanged(smoothedSpeed);
            vehicle_sensors.onIsMovingChanged(smoothedSpeed > 0);
        }

        // Publicar estados do controlador
        publishControllerState(controllerSubscriber, publisher_sensors);

        // Atraso mais curto antes da próxima iteração
        std::this_thread::sleep_for(std::chrono::milliseconds(updateInterval));
    }
}



int main() {
    zmq::context_t context(1);
    zmq::socket_t publisher_sensors(context, zmq::socket_type::pub);
    publisher_sensors.bind("tcp://*:5555");

    ControllerSubscriber controllerSubscriber("tcp://localhost:5556");
    controllerSubscriber.startListening();

    CANBus canBus("can0", 500000);
    JetSnailsCar delorean;

    SpeedSensor speedSensor(canBus, 0x100); // Definindo o sensor de velocidade
    
    vehicleSensors vehicle_sensors(publisher_sensors);
    vehicleInformation vehicle_info(publisher_sensors);
    
    vehicle_info.publishVehicleInfo(delorean.vehicleIdentification.get());

    // Criar e iniciar a thread para leitura e publicação de dados
    std::thread sensorThread(readAndPublishSensorData, std::ref(speedSensor), std::ref(delorean), std::ref(vehicle_sensors), std::ref(controllerSubscriber), std::ref(publisher_sensors));

    // Aguardar a thread
    sensorThread.join();

    return 0;
}
