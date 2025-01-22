#pragma once

#include <zmq.hpp>
#include <sstream>

void    hornOnPressed(zmq::socket_t& pub);
void    hornOnReleased(zmq::socket_t& pub);

void    breakOnReleased(zmq::socket_t& pub);
void    breakOnPressed(zmq::socket_t& pub);

void    lightsLowToggle(zmq::socket_t& pub);
void    lightsHighToggle(zmq::socket_t& pub);

void    moveLeftandRight(zmq::socket_t& pub, int value);
void    moveForwardandBackward(zmq::socket_t& pub, int value);

void    lightsLeftToggle(zmq::socket_t& pub);
void    lightsRightToggle(zmq::socket_t& pub);

void    lightsEmergencyToggle(zmq::socket_t& pub);