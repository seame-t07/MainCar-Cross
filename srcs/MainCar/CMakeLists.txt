cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MainCarServer VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify include directories for MainCar
include_directories(includes)

# Define the source files for MainCar
set(MAINCAR_SOURCES
    sources/Car/ACar.cpp
    sources/Car/JetSnailsCar.cpp
    sources/CANBus/CANBus.cpp
    sources/Sensors/ParkSensor.cpp
    sources/Sensors/SpeedSensor.cpp
    sources/main.cpp
)

# Create the executable for the project
add_executable(${PROJECT_NAME} ${MAINCAR_SOURCES})

