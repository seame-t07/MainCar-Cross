#pragma once

#include <zmq.hpp>
#include <sstream>
#include <pigpio.h>

#define GPIO_PIN_RIGHT_LIGHTS 19
#define GPIO_PIN_LEFT_LIGHTS 26
#define GPIO_PIN_LOW_LIGHTS 6
#define GPIO_PIN_HIGH_LIGHTS 13
#define GPIO_PIN_BREAK_LIGHTS 5
#define GPIO_PIN_HORN 16



void    hornOnPressed(zmq::socket_t& pub);
void    hornOnReleased(zmq::socket_t& pub);

void    breakOnReleased(zmq::socket_t& pub);
void    breakOnPressed(zmq::socket_t& pub);

void    lightsLowToggle(zmq::socket_t& pub);
void    lightsHighToggle(zmq::socket_t& pub);


void    indicationLightsLeft(zmq::socket_t& pub);
void    indicationLightsRight(zmq::socket_t& pub);

void    emergencyOnLights(zmq::socket_t& pub);
