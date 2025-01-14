#pragma once

#include "ACar.hpp"
#include "ISensor.hpp"
#include "SpeedSensor.hpp"
#include "ParkSensor.hpp"
//#include "CANBus.hpp"

#include <vector>
#include <iostream>

class JetSnailsCar : public ACar {
    private:
        int _maxSpeed;
	SpeedSensor *_speedSensor;
	ParkSensor *_parkSensor;

    public:
        JetSnailsCar();
        JetSnailsCar(const std::string& make, const std::string& model, const unsigned int year, const unsigned int maxSpeed);
        JetSnailsCar(const JetSnailsCar& other);
        JetSnailsCar& operator=(const JetSnailsCar& other);
        ~JetSnailsCar();

        void drive() const;
        void printParts() const;
        void printSensors() const;

	    void setSpeedSensor(SpeedSensor *speedSensor);
        void setParkSensor(ParkSensor *parkSensor);

        float getSpeed() const;
        float getDistance() const;
};

std::ostream &  operator<<( std::ostream & o, JetSnailsCar & i );
