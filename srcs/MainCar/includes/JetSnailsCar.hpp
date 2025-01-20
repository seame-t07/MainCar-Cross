#pragma once

#include "ACar.hpp"
#include "ISensor.hpp"
#include "SpeedSensor.hpp"
#include "ParkSensor.hpp"
#include "vehicle.h"
//#include "CANBus.hpp"

#include <vector>
#include <iostream>

using namespace Cpp::Vehicle;

class JetSnailsCar : public ACar {
    private:
        int _maxSpeed;
        SpeedSensor *_speedSensor;
        ParkSensor *_parkSensor;
        
        // std::unique_ptr<IVehicle> vehicle = std::make_unique<Vehicle>();
        // std::unique_ptr<IVehicleVehicleIdentification> vehicleIdentification = std::make_unique<VehicleVehicleIdentification>();
        

    public:
        JetSnailsCar();
        JetSnailsCar(const JetSnailsCar& other);
        JetSnailsCar& operator=(const JetSnailsCar& other);
        ~JetSnailsCar();


        std::unique_ptr<IVehicle> vehicle;
        std::unique_ptr<IVehicleVehicleIdentification> vehicleIdentification;

        void drive() const;
        void printParts() const;
        void printSensors() const;

	    void setSpeedSensor(SpeedSensor *speedSensor);
        void setParkSensor(ParkSensor *parkSensor);

        float getSpeed() const;
        float getDistance() const;
};

std::ostream &  operator<<( std::ostream & o, JetSnailsCar & i );
