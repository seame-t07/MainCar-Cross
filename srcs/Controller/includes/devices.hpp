#pragma once

#include <zmq.hpp>
#include <sstream>
#include <pigpio.h>

#define GPIO_PIN_RIGHT_LIGHTS 26  // Define o pino GPIO26

void    hornOnPressed(zmq::socket_t& pub);
void    hornOnReleased(zmq::socket_t& pub);

void    breakOnReleased(zmq::socket_t& pub);
void    breakOnPressed(zmq::socket_t& pub);

void    lightsLowToggle(zmq::socket_t& pub);
void    lightsHighToggle(zmq::socket_t& pub);


void    lightsLeftToggle(zmq::socket_t& pub);
void    indicationLightsRight(zmq::socket_t& pub);

void    emergencyOnLights(zmq::socket_t& pub);