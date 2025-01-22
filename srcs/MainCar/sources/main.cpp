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
    while (true) {
        speedSensor.readData();
        float currentSpeed = speedSensor.getValue();

        delorean.vehicle->setSpeed(currentSpeed);
        vehicle_sensors.onSpeedChanged(currentSpeed);
        vehicle_sensors.onIsMovingChanged(delorean.vehicle->getSpeed() > 0);

        publishControllerState(controllerSubscriber, publisher_sensors);

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Sleep mais curto
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
// #include <pigpio.h>
// #include <thread>
// #include "ControllerSubscriber.hpp"
// #include "zmq.hpp"

// // Função para publicar o estado do controlador
// void publishControllerState(ControllerSubscriber& controllerSubscriber, zmq::socket_t& publisher) {
//     const std::vector<std::string> controls = {
//         "horn", "lightslow", "lightshigh", "break",
//         "lightsleft", "lightsright", "lightsemergency", "lightspark"
//     };

//     for (const auto& control : controls) {
//         std::string state = controllerSubscriber.getControlState(control);

//         if (!state.empty()) {
//             zmq::message_t message(control.size() + state.size() + 1);
//             snprintf(static_cast<char*>(message.data()), message.size() + 1, "%s %s", control.c_str(), state.c_str());
//             publisher.send(message, zmq::send_flags::none);
//             std::cout << "Published control state: " << control << " - " << state << std::endl;
//         }
//     }
// }

// // Função para testar o controle (somente a parte dos controles)
// void testControllerState(ControllerSubscriber& controllerSubscriber, zmq::socket_t& publisher_sensors) {
//     while (true) {
//         publishControllerState(controllerSubscriber, publisher_sensors);
//         std::this_thread::sleep_for(std::chrono::milliseconds(500)); // sleep de 500ms entre publicações
//     }
// }

// int main() {
//     zmq::context_t context(1);
//     zmq::socket_t publisher_sensors(context, zmq::socket_type::pub);
//     publisher_sensors.bind("tcp://*:5555");

//     // Criação do ControllerSubscriber e início da escuta
//     ControllerSubscriber controllerSubscriber("tcp://localhost:5556");
//     controllerSubscriber.startListening();

//     // Inicia a thread que ficará publicando os estados dos controles
//     std::thread controllerThread(testControllerState, std::ref(controllerSubscriber), std::ref(publisher_sensors));

//     // Aguardar a thread
//     controllerThread.join();

//     return 0;
// }
