
#pragma once
#include "vehicle/generated/api/vehicle.h"
#include "vehicle/generated/api/common.h"
#include "vehicle/generated/core/vehiclebodylightslicenseplate.data.h"
#include <memory>

namespace Cpp {
namespace Vehicle {

/**
* The Vehicle_Body_Lights_LicensePlate implementation.
*/
class CPP_VEHICLE_EXPORT VehicleBodyLightsLicensePlate : public IVehicleBodyLightsLicensePlate
{
public:
    explicit VehicleBodyLightsLicensePlate();
    ~VehicleBodyLightsLicensePlate();
public:
    /**
    * IsOn Indicates if light is on or off. True = On. False = Off.
    */
    void setIsOn(bool IsOn) override;
    bool getIsOn() const override;
    
    /**
    * IsDefect Indicates if light is defect. True = Light is defect. False = Light has no defect.
    */
    void setIsDefect(bool IsDefect) override;
    bool getIsDefect() const override;
    
    /**
    * Access to a publisher, use it to subscribe for Vehicle_Body_Lights_LicensePlate changes and signal emission.
    * @return The publisher for Vehicle_Body_Lights_LicensePlate.
    */
    IVehicleBodyLightsLicensePlatePublisher& _getPublisher() const override;
private:
    /** The publisher for the Vehicle_Body_Lights_LicensePlate. */
    std::unique_ptr<IVehicleBodyLightsLicensePlatePublisher> m_publisher;
    /** The helper structure to store all the properties for Vehicle_Body_Lights_LicensePlate. */
    VehicleBodyLightsLicensePlateData m_data;
};
} // namespace Vehicle
} // namespace Cpp
