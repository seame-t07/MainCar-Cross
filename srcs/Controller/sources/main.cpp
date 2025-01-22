#include "Controller.hpp"
#include "JetCar.hpp"
#include "devices.hpp"
#include <iostream>

JetCar car;



int main() {
    std::cout << "Team07 Controller App" << std::endl;
    zmq::context_t context(1);
    zmq::socket_t publisher_controls(context, zmq::socket_type::pub);
    publisher_controls.bind("tcp://*:5556");

    Actions horn;
    horn.onPress = [&publisher_controls]() {
        hornOnPressed(publisher_controls);
    };
    horn.onRelease = [&publisher_controls]() {
        hornOnReleased(publisher_controls);
    };

    Actions car_break;
    car_break.onPress = [&publisher_controls]() {
        breakOnPressed(publisher_controls);
    };
    car_break.onRelease = [&publisher_controls]() {
        breakOnReleased(publisher_controls);
    };

    // For toggle actions just use the onPress
    Actions lowLights;
    lowLights.onPress = [&publisher_controls]() {
        lightsLowToggle(publisher_controls);
    };

    Actions highLights;
    highLights.onPress = [&publisher_controls]() {
        lightsHighToggle(publisher_controls);
    };

    Actions leftLights;
    leftLights.onPress = [&publisher_controls]() {
        lightsLeftToggle(publisher_controls);
    };

    Actions rightLights;
    rightLights.onPress = [&publisher_controls]() {
        lightsRightToggle(publisher_controls);
    };

    Actions emergencyLights;
    emergencyLights.onPress = [&publisher_controls]() {
        lightsEmergencyToggle(publisher_controls);
    };


    try {
        Controller controller;
        // Start listening for gamepad events

        controller.setButtonAction(1, horn);
        controller.setButtonAction(3, car_break);
        
        controller.setButtonAction(2, lowLights);
        controller.setButtonAction(0, highLights);

        controller.setButtonAction(0, highLights);
        controller.setButtonAction(0, highLights);
    
        controller.setAxisAction(SDL_CONTROLLER_AXIS_LEFTX, moveLeftandRight);
        controller.setAxisAction(5, moveForwardandBackward);

        controller.listen();

    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

