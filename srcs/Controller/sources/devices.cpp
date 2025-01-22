
#include <iostream>
#include "devices.hpp"


// toggle variables
bool isLightsLowOn = false;
bool isLightsHighOn = false;
bool isLightsLeftOn = false;
// bool isLightsRightOn = false;
// bool isLightsEmergencyOn = false;

void hornOnPressed(zmq::socket_t& pub)
{
    std::cout << "horn on\n";
    std::string message = "horn true";

    auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
    if (result.has_value()) {
        std::cout << "Message sent: " << message << std::endl;
    } else {
        std::cerr << "Failed to send message: " << message << std::endl;
    }
}

void hornOnReleased(zmq::socket_t& pub)
{
    std::cout << "horn off\n";
    std::string message = "horn false";

    auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
    if (result.has_value()) {
        std::cout << "Message sent: " << message << std::endl;
    } else {
        std::cerr << "Failed to send message: " << message << std::endl;
    }
}

void breakOnPressed(zmq::socket_t& pub)
{
    std::cout << "break on\n";
    std::string message = "break true";

    auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
    if (result.has_value()) {
        std::cout << "Message sent: " << message << std::endl;
    } else {
        std::cerr << "Failed to send message: " << message << std::endl;
    }
}

void breakOnReleased(zmq::socket_t& pub)
{
    std::cout << "break off\n";
    std::string message = "break false";

    auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
    if (result.has_value()) {
        std::cout << "Message sent: " << message << std::endl;
    } else {
        std::cerr << "Failed to send message: " << message << std::endl;
    }
}

void lightsLowToggle(zmq::socket_t& pub)
{
    // Change state
    isLightsLowOn = !isLightsLowOn;

    std::string state = isLightsLowOn ? "true" : "false";
    std::string message = "lightslow " + state;

    auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
    if (result.has_value()) {
        std::cout << "Message sent: " << message << std::endl;
    } else {
        std::cerr << "Failed to send message: " << message << std::endl;
    }
}

void lightsHighToggle(zmq::socket_t& pub)
{
    // Change state
    isLightsHighOn = !isLightsHighOn;

    std::string state = isLightsHighOn ? "true" : "false";
    std::string message = "lightshigh " + state;

    auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
    if (result.has_value()) {
        std::cout << "Message sent: " << message << std::endl;
    } else {
        std::cerr << "Failed to send message: " << message << std::endl;
    }
}

// void lightsLeftToggle(zmq::socket_t& pub)
// {
//     // Change state
//     isLightsLeftOn = !isLightsLeftOn;

//     std::string state = isLightsLeftOn ? "true" : "false";
//     std::string message = "lightsleft " + state;

//     auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
//     if (result.has_value()) {
//         std::cout << "Message sent: " << message << std::endl;
//     } else {
//         std::cerr << "Failed to send message: " << message << std::endl;
//     }
// }

// void lightsRightToggle(zmq::socket_t& pub)
// {
//     // Change state
//     isLightsRightOn = !isLightsRightOn;

//     std::string state = isLightsRightOn ? "true" : "false";
//     std::string message = "lightsright " + state;

//     auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
//     if (result.has_value()) {
//         std::cout << "Message sent: " << message << std::endl;
//     } else {
//         std::cerr << "Failed to send message: " << message << std::endl;
//     }
// }

// void lightsEmergencyToggle(zmq::socket_t& pub)
// {
//     // Change state
//     isLightsEmergencyOn = !isLightsEmergencyOn;

//     std::string state = isLightsEmergencyOn ? "true" : "false";
//     std::string message = "lightsemergency " + state;

//     auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
//     if (result.has_value()) {
//         std::cout << "Message sent: " << message << std::endl;
//     } else {
//         std::cerr << "Failed to send message: " << message << std::endl;
//     }
// }


void moveLeftandRight(zmq::socket_t& pub, int value) {
     
    float fvalue = value * 1.0;// + 6900;
  //  fvalue -= -129.0;
    std::cout << "Before: " << fvalue << std::endl;
    fvalue = fvalue / 32000.0 * 45;
    std::cout << "Axis moved to " << fvalue << std::endl;
    car.setServoAngle(fvalue);
}

void moveForwardandBackward(zmq::socket_t& pub, int value) {
    
    value -= 16319;

    value = (value / 165) * -1;
    
    std::cout << "Axis moved to " << value << std::endl;
    car.setMotorSpeed(value);
}

void emergencyLights(zmq::socket_t& pub, int value) {
    isLightsEmergencyOn = !isLightsEmergencyOn;

    std::string state = isLightsLowOn ? "true" : "false";
    std::string message = "lightslow " + state;

    auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
    if (result.has_value()) {
        std::cout << "Message sent: " << message << std::endl;
    } else {
        std::cerr << "Failed to send message: " << message << std::endl;
    }
}

void indicationLights(zmq::socket_t& pub, int value) {
    isLightsLowOn = !isLightsLowOn;

    std::string state = isLightsLowOn ? "true" : "false";
    std::string message = "lightslow " + state;

    auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
    if (result.has_value()) {
        std::cout << "Message sent: " << message << std::endl;
    } else {
        std::cerr << "Failed to send message: " << message << std::endl;
    }
}