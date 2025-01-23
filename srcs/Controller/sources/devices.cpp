
#include <iostream>
#include "devices.hpp"


// toggle variables
bool isLightsLowOn = false;
bool isLightsHighOn = false;
bool isLightsLeftOn = false;
bool isLightsRightOn = false;
bool isLightsEmergencyOn = false;

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


void emergencyOnLights(zmq::socket_t& pub, int value) {
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

void indicationLightsRight(zmq::socket_t& pub) {
    // Toggle da luz direita
    isLightsRightOn = !isLightsRightOn;

    // Configure o estado como string para enviar via ZMQ
    std::string state = isLightsRightOn ? "true" : "false";
    std::string message = "lightsright " + state;

    // Alterne o estado do GPIO26 com base no isLightsRightOn
    if (isLightsRightOn) {
        gpioWrite(GPIO_PIN_RIGHT_LIGHTS, 1); // Liga o GPIO26
    } else {
        gpioWrite(GPIO_PIN_RIGHT_LIGHTS, 0); // Desliga o GPIO26
    }

    // Envie a mensagem usando ZeroMQ
    auto result = pub.send(zmq::buffer(message), zmq::send_flags::none);
    if (result.has_value()) {
        std::cout << "Message sent: " << message << std::endl;
    } else {
        std::cerr << "Failed to send message: " << message << std::endl;
    }
}