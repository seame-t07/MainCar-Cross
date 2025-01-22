#include <pigpio.h>
#include <thread>
#include "JetSnailsCar.hpp"
#include "vehicle.h"
#include "VehicleInfoSubscriber.hpp"
#include "VehicleSubscriber.hpp"
#include "ControllerSubscriber.hpp"
#include "HornSubscriber.hpp"


void publishControllerState(ControllerSubscriber& controllerSubscriber, zmq::socket_t& publisher) {
    const std::vector<std::string> controls = {
        "horn", "lightslow", "lightshigh", "break",
        "lightsleft", "lightsright", "lightsemergency", "lightspark"
    };

    for (const auto& control : controls) {
        std::string state = controllerSubscriber.getControlState(control);

        // Publica o estado do controle para os subscritores
        if (!state.empty()) {
            zmq::message_t message(control.size() + state.size() + 1);
            snprintf(static_cast<char*>(message.data()), message.size() + 1, "%s %s", control.c_str(), state.c_str()); //space
            std::cout << "Message from controller zmq: "<< message.data() << std::endl;
            publisher.send(message, zmq::send_flags::none);
        }
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

    ISensor* speedSensor = new SpeedSensor(canBus, 0x100);
    
    vehicleSensors vehicle_sensors(publisher_sensors);
    vehicleInformation vehicle_info(publisher_sensors);

    vehicle_info.publishVehicleInfo(delorean.vehicleIdentification.get());

    while (1) {
        speedSensor->readData();
        float currentSpeed = speedSensor->getValue();

        delorean.vehicle->setSpeed(currentSpeed);
        vehicle_sensors.onSpeedChanged(currentSpeed);

        (delorean.vehicle->getSpeed()) 
            ? vehicle_sensors.onIsMovingChanged(true)
            : vehicle_sensors.onIsMovingChanged(false);

        publishControllerState(controllerSubscriber, publisher_sensors);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}