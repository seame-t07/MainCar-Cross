
#pragma once
#include "vehicle/generated/api/vehicle.h"
#include "vehicle/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Cpp {
namespace Vehicle {

/** 
* @brief The VehiclePowertrainTractionBatteryChargingThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the Vehicle_Powertrain_TractionBattery_Charging interface.
* @see Vehicle_Powertrain_TractionBattery_Charging
*
\code{.cpp}
using namespace Cpp::Vehicle;

std::unique_ptr<IVehiclePowertrainTractionBatteryCharging> testVehiclePowertrainTractionBatteryCharging = std::make_unique<VehiclePowertrainTractionBatteryChargingThreadSafeDecorator>(std::make_shared<VehiclePowertrainTractionBatteryCharging>());

// Thread safe access
auto chargeLimit = testVehiclePowertrainTractionBatteryCharging->getChargeLimit();
testVehiclePowertrainTractionBatteryCharging->setChargeLimit(0);
auto isCharging = testVehiclePowertrainTractionBatteryCharging->getIsCharging();
testVehiclePowertrainTractionBatteryCharging->setIsCharging(false);
auto isDischarging = testVehiclePowertrainTractionBatteryCharging->getIsDischarging();
testVehiclePowertrainTractionBatteryCharging->setIsDischarging(false);
auto startStopCharging = testVehiclePowertrainTractionBatteryCharging->getStartStopCharging();
testVehiclePowertrainTractionBatteryCharging->setStartStopCharging(Vehicle_Powertrain_TractionBattery_Charging_StartStopCharging_ValueEnum::START);
auto averagePower = testVehiclePowertrainTractionBatteryCharging->getAveragePower();
testVehiclePowertrainTractionBatteryCharging->setAveragePower(0.0f);
auto maxPower = testVehiclePowertrainTractionBatteryCharging->getMaxPower();
testVehiclePowertrainTractionBatteryCharging->setMaxPower(0.0f);
auto evseId = testVehiclePowertrainTractionBatteryCharging->getEvseId();
testVehiclePowertrainTractionBatteryCharging->setEvseId(std::string());
auto powerLoss = testVehiclePowertrainTractionBatteryCharging->getPowerLoss();
testVehiclePowertrainTractionBatteryCharging->setPowerLoss(0.0f);
auto temperature = testVehiclePowertrainTractionBatteryCharging->getTemperature();
testVehiclePowertrainTractionBatteryCharging->setTemperature(0.0f);
auto chargeRate = testVehiclePowertrainTractionBatteryCharging->getChargeRate();
testVehiclePowertrainTractionBatteryCharging->setChargeRate(0.0f);
auto timeToComplete = testVehiclePowertrainTractionBatteryCharging->getTimeToComplete();
testVehiclePowertrainTractionBatteryCharging->setTimeToComplete(0);
\endcode
*/
class CPP_VEHICLE_EXPORT VehiclePowertrainTractionBatteryChargingThreadSafeDecorator : public IVehiclePowertrainTractionBatteryCharging
{
public:
    /** 
    * ctor
    * @param impl The Vehicle_Powertrain_TractionBattery_Charging object to make thread safe.
    */
    explicit VehiclePowertrainTractionBatteryChargingThreadSafeDecorator(std::shared_ptr<IVehiclePowertrainTractionBatteryCharging> impl);

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setChargeLimit(int32_t ChargeLimit) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    int32_t getChargeLimit() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setIsCharging(bool IsCharging) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    bool getIsCharging() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setIsDischarging(bool IsDischarging) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    bool getIsDischarging() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setStartStopCharging(Vehicle_Powertrain_TractionBattery_Charging_StartStopCharging_ValueEnum StartStopCharging) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    Vehicle_Powertrain_TractionBattery_Charging_StartStopCharging_ValueEnum getStartStopCharging() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setAveragePower(float AveragePower) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    float getAveragePower() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setMaxPower(float MaxPower) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    float getMaxPower() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setEvseId(const std::string& EvseId) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    const std::string& getEvseId() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setPowerLoss(float PowerLoss) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    float getPowerLoss() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setTemperature(float Temperature) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    float getTemperature() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setChargeRate(float ChargeRate) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    float getChargeRate() const override;

    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    void setTimeToComplete(int32_t TimeToComplete) override;
    /** Guards and forwards call to Vehicle_Powertrain_TractionBattery_Charging implementation. */
    int32_t getTimeToComplete() const override;

    /**
    * Access to a publisher, use it to subscribe for Vehicle_Powertrain_TractionBattery_Charging changes and signal emission.
    * This call is thread safe.
    * @return The publisher for Vehicle_Powertrain_TractionBattery_Charging.
    */
    IVehiclePowertrainTractionBatteryChargingPublisher& _getPublisher() const override;
private:
    /** The Vehicle_Powertrain_TractionBattery_Charging object which is guarded */
    std::shared_ptr<IVehiclePowertrainTractionBatteryCharging> m_impl;
    // Mutex for chargeLimit property
    mutable std::shared_timed_mutex m_chargeLimitMutex;
    // Mutex for isCharging property
    mutable std::shared_timed_mutex m_isChargingMutex;
    // Mutex for isDischarging property
    mutable std::shared_timed_mutex m_isDischargingMutex;
    // Mutex for startStopCharging property
    mutable std::shared_timed_mutex m_startStopChargingMutex;
    // Mutex for averagePower property
    mutable std::shared_timed_mutex m_averagePowerMutex;
    // Mutex for maxPower property
    mutable std::shared_timed_mutex m_maxPowerMutex;
    // Mutex for evseId property
    mutable std::shared_timed_mutex m_evseIdMutex;
    // Mutex for powerLoss property
    mutable std::shared_timed_mutex m_powerLossMutex;
    // Mutex for temperature property
    mutable std::shared_timed_mutex m_temperatureMutex;
    // Mutex for chargeRate property
    mutable std::shared_timed_mutex m_chargeRateMutex;
    // Mutex for timeToComplete property
    mutable std::shared_timed_mutex m_timeToCompleteMutex;
};
} // namespace Vehicle
} // namespace Cpp
