#include "JetSnailsCar.hpp"
#include <pigpio.h>
#include <thread>
#include "vehicle.h"
#include <zmq.hpp>
#include <sstream>
#include <iomanip>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;
using namespace Cpp::Vehicle;

class vehicleInformation : public IVehicleVehicleIdentificationSubscriber {
private:
    zmq::socket_t& publisher; // Referência para o socket do ZeroMQ
    std::unordered_map<std::string, std::string> currentValues; // Armazena os valores atuais dos atributos
    std::string jsonFilePath = "vehicle_info.json"; // Caminho para o arquivo JSON

    // Helper to send message via ZeroMQ
    void sendMessage(const std::string& key, const std::string& value) {
        std::ostringstream message;
        message << key << " " << value;

        zmq::message_t zmqMessage(message.str().size());
        memcpy(zmqMessage.data(), message.str().c_str(), message.str().size());
        publisher.send(zmqMessage, zmq::send_flags::none);
    }

    // update json
    void updateJsonFile() {
        json j;
        for (const auto& [key, value] : currentValues) {
            j[key] = value;
        }
        std::ofstream file(jsonFilePath);
        if (file.is_open()) {
            file << j.dump(4);
            file.close();
        } else {
            std::cerr << "Erro to open json file" << std::endl;
        }
    }

public:
    explicit vehicleInformation(zmq::socket_t& pub) : publisher(pub) {}

    void publishVehicleInfo(const IVehicleVehicleIdentification* vehicleInfo) {
        currentValues["vin"] = vehicleInfo->getVin();
        currentValues["wmi"] = vehicleInfo->getWmi();
        currentValues["brand"] = vehicleInfo->getBrand();
        currentValues["model"] = vehicleInfo->getModel();
        currentValues["year"] = std::to_string(vehicleInfo->getYear());
        currentValues["body_type"] = vehicleInfo->getBodyType();
        currentValues["license_plate"] = vehicleInfo->getLicensePlate();
        currentValues["seating_capacity"] = std::to_string(vehicleInfo->getVehicleSeatingCapacity());
        currentValues["special_usage"] = vehicleInfo->getVehicleSpecialUsage();
        currentValues["exterior_color"] = vehicleInfo->getVehicleExteriorColor();

        const auto& extras = vehicleInfo->getOptionalExtras();
        std::ostringstream extrasStream;
        for (const auto& extra : extras) {
            extrasStream << extra << ",";
        }
        currentValues["optional_extras"] = extrasStream.str();

        updateJsonFile();
    }

    // on changed methods
    void onVinChanged(const std::string& VIN) override {
        currentValues["vin"] = VIN;
        updateJsonFile();
        sendMessage("vin", VIN);
    }

    void onWmiChanged(const std::string& WMI) override {
        currentValues["wmi"] = WMI;
        updateJsonFile();
        sendMessage("wmi", WMI);
    }

    void onBrandChanged(const std::string& Brand) override {
        currentValues["brand"] = Brand;
        updateJsonFile();
        sendMessage("brand", Brand);
    }

    void onModelChanged(const std::string& Model) override {
        currentValues["model"] = Model;
        updateJsonFile();
        sendMessage("model", Model);
    }

    void onYearChanged(int32_t Year) override {
        currentValues["year"] = std::to_string(Year);
        updateJsonFile();
        sendMessage("year", std::to_string(Year));
    }

    void onBodyTypeChanged(const std::string& BodyType) override {
        currentValues["body_type"] = BodyType;
        updateJsonFile();
        sendMessage("body_type", BodyType);
    }

    void onLicensePlateChanged(const std::string& LicensePlate) override {
        currentValues["license_plate"] = LicensePlate;
        updateJsonFile();
        sendMessage("license_plate", LicensePlate);
    }

    void onVehicleSeatingCapacityChanged(int32_t VehicleSeatingCapacity) override {
        currentValues["seating_capacity"] = std::to_string(VehicleSeatingCapacity);
        updateJsonFile();
        sendMessage("seating_capacity", std::to_string(VehicleSeatingCapacity));
    }

    void onVehicleSpecialUsageChanged(const std::string& VehicleSpecialUsage) override {
        currentValues["special_usage"] = VehicleSpecialUsage;
        updateJsonFile();
        sendMessage("special_usage", VehicleSpecialUsage);
    }

    void onVehicleExteriorColorChanged(const std::string& VehicleExteriorColor) override {
        currentValues["exterior_color"] = VehicleExteriorColor;
        updateJsonFile();
        sendMessage("exterior_color", VehicleExteriorColor);
    }

    void onOptionalExtrasChanged(const std::list<std::string>& OptionalExtras) override {
        std::ostringstream extrasStream;
        for (const auto& extra : OptionalExtras) {
            extrasStream << extra << ",";
        }
        currentValues["optional_extras"] = extrasStream.str();
        updateJsonFile();
        sendMessage("optional_extras", extrasStream.str());
    }
    void onAcrissCodeChanged(const std::string& AcrissCode) {}
    void onDateVehicleFirstRegisteredChanged(const std::string& DateVehicleFirstRegistered) {}
    void onMeetsEmissionStandardChanged(const std::string& MeetsEmissionStandard) {}
    void onProductionDateChanged(const std::string& ProductionDate) {}
    void onPurchaseDateChanged(const std::string& PurchaseDate) {}
    void onVehicleModelDateChanged(const std::string& VehicleModelDate) {}
    void onVehicleConfigurationChanged(const std::string& VehicleConfiguration) {}
    void onVehicleInteriorColorChanged(const std::string& VehicleInteriorColor) {}
    void onVehicleInteriorTypeChanged(const std::string& VehicleInteriorType) {}
    void onKnownVehicleDamagesChanged(const std::string& KnownVehicleDamages) {}

};

class vehicleSensors : public IVehicleSubscriber {
private:
    zmq::socket_t& publisher; // Referência para o socket do ZeroMQ

    // Helper para enviar mensagens via ZeroMQ
    void sendMessage(const std::string& key, const std::string& value) {
        std::ostringstream message;
        message << key << " " << value;

        zmq::message_t zmqMessage(message.str().size());
        memcpy(zmqMessage.data(), message.str().c_str(), message.str().size());
        publisher.send(zmqMessage, zmq::send_flags::none);
    }

public:
    explicit vehicleSensors(zmq::socket_t& pub) : publisher(pub) {}

    void onSpeedChanged(float speed) override {
        std::cout << "Speed updated on Cluster Display: " << speed << " m/h" << std::endl;
        sendMessage("speed", std::to_string(speed));
        //sendMessage("speed", std::to_string(speed));
    }

    void onLowVoltageSystemStateChanged(Vehicle_LowVoltageSystemState_ValueEnum LowVoltageSystemState) override {
        sendMessage("low_voltage_system_state", std::to_string(static_cast<int>(LowVoltageSystemState)));
    }

    void onTraveledDistanceChanged(float TraveledDistance) override {
        sendMessage("traveled_distance", std::to_string(TraveledDistance));
    }

    void onTraveledDistanceSinceStartChanged(float TraveledDistanceSinceStart) override {
        sendMessage("traveled_distance_since_start", std::to_string(TraveledDistanceSinceStart));
    }

    void onStartTimeChanged(const std::string& StartTime) override {
        sendMessage("start_time", StartTime);
    }

    void onTripDurationChanged(float TripDuration) override {
        sendMessage("trip_duration", std::to_string(TripDuration));
    }

    void onTripMeterReadingChanged(float TripMeterReading) override {
        sendMessage("trip_meter_reading", std::to_string(TripMeterReading));
    }

    void onIsBrokenDownChanged(bool IsBrokenDown) override {
        sendMessage("is_broken_down", IsBrokenDown ? "true" : "false");
    }

    void onIsMovingChanged(bool IsMoving) override {
        sendMessage("is_moving", IsMoving ? "true" : "false");
    }

    void onAverageSpeedChanged(float AverageSpeed) override {
        sendMessage("average_speed", std::to_string(AverageSpeed));
    }

    void onPowerOptimizeLevelChanged(int32_t PowerOptimizeLevel) override {
        sendMessage("power_optimize_level", std::to_string(PowerOptimizeLevel));
    }

    void onIsAutoPowerOptimizeChanged(bool IsAutoPowerOptimize) override {
        sendMessage("is_auto_power_optimize", IsAutoPowerOptimize ? "true" : "false");
    }
};

int main() {
    zmq::context_t context(1);
    zmq::socket_t publisher_sensors(context, zmq::socket_type::pub);
    publisher_sensors.bind("tcp://*:5555");

    CANBus canBus("can0", 500000);

    JetSnailsCar delorean;
    delorean.vehicle->setSpeed(0.0);
    delorean.vehicle->setTraveledDistance(0.0);
    delorean.vehicle->setTraveledDistanceSinceStart(0.0); // trip
    delorean.vehicle->setIsMoving("false");
    delorean.vehicle->setAverageSpeed(0.0);

    ISensor* speedSensor = new SpeedSensor(canBus, 0x100);
    
    vehicleSensors vehicle_sensors(publisher_sensors);

    vehicleInformation vehicle_info(publisher_sensors);

    vehicle_info.publishVehicleInfo(delorean.vehicleIdentification.get());

    while (1) {
        speedSensor->readData();
        float currentSpeed = speedSensor->getValue();

        delorean.vehicle->setSpeed(currentSpeed);
        vehicle_sensors.onSpeedChanged(currentSpeed);

        (delorean.vehicle->getSpeed()) 
            ? vehicle_sensors.onIsMovingChanged(true)
            : vehicle_sensors.onIsMovingChanged(false);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}