#include "JetSnailsCar.hpp"
#include "vehicle/implementation/vehiclevehicleidentification.h"

// Constructors
JetSnailsCar::JetSnailsCar() : ACar(), _maxSpeed(0) {
    std::cout << "Default constructor called for JetSnailsCar" << std::endl;

    vehicle = std::make_unique<Vehicle>();
    vehicleIdentification = std::make_unique<VehicleVehicleIdentification>();

    vehicleIdentification->setVin("CD010XXX");
    vehicleIdentification->setWmi("Europe");
    vehicleIdentification->setBrand("Delorean Motor Company");
    vehicleIdentification->setModel("BTF Delorean");
    vehicleIdentification->setYear(1981);
    vehicleIdentification->setBodyType("hatchback");
    vehicleIdentification->setLicensePlate("00-XX-00");
    vehicleIdentification->setVehicleSeatingCapacity(2);
    vehicleIdentification->setVehicleSpecialUsage("Travel in time");
    vehicleIdentification->setVehicleExteriorColor("Gray");
    // vehicleIdentification->setOptionalExtras({"Flux capacitor",""});
}

JetSnailsCar::JetSnailsCar(const JetSnailsCar& original) : ACar(original), _maxSpeed(original._maxSpeed) {
    std::cout << "Copy constructor called for JetSnailsCar" << std::endl;
}

// Destructor
JetSnailsCar::~JetSnailsCar() {
    std::cout << "Destructor called for JetSnailsCar" << std::endl;
}

// Member function
void JetSnailsCar::drive() const {
    ;
}

void JetSnailsCar::printParts(void) const {
    std::cout << "Print parts goes here!" << std::endl;
}

void JetSnailsCar::printSensors(void) const {
    std::cout << "Print Sensors goes here!" << std::endl;
}


void JetSnailsCar::setSpeedSensor(SpeedSensor *speedSensor) {
     _speedSensor = speedSensor;
}

void JetSnailsCar::setParkSensor(ParkSensor *parkSensor) {
     _parkSensor = parkSensor;
}

float JetSnailsCar::getSpeed() const {
    return _speedSensor->getValue();
}

float JetSnailsCar::getDistance() const {
    return _parkSensor->getValue();
}

// Operator overload
JetSnailsCar& JetSnailsCar::operator=(const JetSnailsCar& original) {
    if (this != &original) {
        ACar::operator=(original);
        _maxSpeed = original._maxSpeed;
    }
    std::cout << "Copy assignment operator called for JetSnailsCar" << std::endl;
    return *this;
}
