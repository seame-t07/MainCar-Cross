#pragma once

#include <future>
#include "vehicle/generated/api/common.h"
#include "vehicle/generated/api/datastructs.api.h"

namespace Cpp {
namespace Vehicle {

class IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber;
class IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher;

/**
*
* IVehicleMotionManagementBrakeAxleRow2WheelLeft provides an interface for
 *  - methods defined for your Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left 
 *  - property setters and getters for defined properties
 * The IVehicleMotionManagementBrakeAxleRow2WheelLeft also provides an interface to access a publisher IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher, a class used by IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber clients.
 * The implementation should notify the publisher IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher about emitted signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber, IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher
 * and the example implementation Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left  or the
 */
class CPP_VEHICLE_EXPORT IVehicleMotionManagementBrakeAxleRow2WheelLeft
{
public:
    virtual ~IVehicleMotionManagementBrakeAxleRow2WheelLeft() = default;

    /**
    * Sets the value of the Torque property.
    * @param Torque Estimated friction brake torque. Brake Torque < 0Nm.
    */
    virtual void setTorque(int32_t Torque) = 0;
    /**
    * Gets the value of the Torque property.
    * @return Estimated friction brake torque. Brake Torque < 0Nm.
    */
    virtual int32_t getTorque() const = 0;

    /**
    * Sets the value of the TorqueArbitrated property.
    * @param TorqueArbitrated Brake system internally calculated friction brake torque target. Brake Torque < 0Nm.
    */
    virtual void setTorqueArbitrated(int32_t TorqueArbitrated) = 0;
    /**
    * Gets the value of the TorqueArbitrated property.
    * @return Brake system internally calculated friction brake torque target. Brake Torque < 0Nm.
    */
    virtual int32_t getTorqueArbitrated() const = 0;

    /**
    * Sets the value of the TorqueFrictionMaximum property.
    * @param TorqueFrictionMaximum Maximum wheel torque request for friction brake. Brake Torque < 0Nm.
    */
    virtual void setTorqueFrictionMaximum(int32_t TorqueFrictionMaximum) = 0;
    /**
    * Gets the value of the TorqueFrictionMaximum property.
    * @return Maximum wheel torque request for friction brake. Brake Torque < 0Nm.
    */
    virtual int32_t getTorqueFrictionMaximum() const = 0;

    /**
    * Sets the value of the TorqueFrictionMinimum property.
    * @param TorqueFrictionMinimum Minimum wheel torque request for friction brake. Brake Torque < 0Nm.
    */
    virtual void setTorqueFrictionMinimum(int32_t TorqueFrictionMinimum) = 0;
    /**
    * Gets the value of the TorqueFrictionMinimum property.
    * @return Minimum wheel torque request for friction brake. Brake Torque < 0Nm.
    */
    virtual int32_t getTorqueFrictionMinimum() const = 0;

    /**
    * Sets the value of the OmegaUpper property.
    * @param OmegaUpper Upper wheel speed limit request controlled by friction brake. ISO 8855 wheel-spin velocity.
    */
    virtual void setOmegaUpper(int32_t OmegaUpper) = 0;
    /**
    * Gets the value of the OmegaUpper property.
    * @return Upper wheel speed limit request controlled by friction brake. ISO 8855 wheel-spin velocity.
    */
    virtual int32_t getOmegaUpper() const = 0;

    /**
    * Sets the value of the OmegaLower property.
    * @param OmegaLower Lower wheel speed limit request controlled by friction brake. ISO 8855 wheel-spin velocity.
    */
    virtual void setOmegaLower(int32_t OmegaLower) = 0;
    /**
    * Gets the value of the OmegaLower property.
    * @return Lower wheel speed limit request controlled by friction brake. ISO 8855 wheel-spin velocity.
    */
    virtual int32_t getOmegaLower() const = 0;

    /**
    * Access to a publisher, use it to subscribe for Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left changes and signal emission.
    * This function name doesn't follow the convention, because it is added to user defined interface,
    * to avoid potentially name clashes, it has the trailing underscore in the name.
    * @return The publisher for Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left.
    */
    virtual IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher& _getPublisher() const = 0;
};


/**
 * The IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber contains functions to allow informing about signals or property changes of the IVehicleMotionManagementBrakeAxleRow2WheelLeft implementation.
 * The implementation for IVehicleMotionManagementBrakeAxleRow2WheelLeft should provide mechanism for subscription of the IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber clients.
 * See IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher, which provides facilitation for this purpose.
 * The implementation for IVehicleMotionManagementBrakeAxleRow2WheelLeft should call the IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface functions on either signal emit or property change.
 * You can use IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber class to implement clients of the IVehicleMotionManagementBrakeAxleRow2WheelLeft or the network adapter - see Olink Server and Client example.
 */
class CPP_VEHICLE_EXPORT IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber
{
public:
    virtual ~IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber() = default;
    /**
    * Called by the IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher when Torque value has changed if subscribed for the Torque change.
    * @param Torque Estimated friction brake torque. Brake Torque < 0Nm.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void onTorqueChanged(int32_t Torque) = 0;
    /**
    * Called by the IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher when TorqueArbitrated value has changed if subscribed for the TorqueArbitrated change.
    * @param TorqueArbitrated Brake system internally calculated friction brake torque target. Brake Torque < 0Nm.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void onTorqueArbitratedChanged(int32_t TorqueArbitrated) = 0;
    /**
    * Called by the IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher when TorqueFrictionMaximum value has changed if subscribed for the TorqueFrictionMaximum change.
    * @param TorqueFrictionMaximum Maximum wheel torque request for friction brake. Brake Torque < 0Nm.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void onTorqueFrictionMaximumChanged(int32_t TorqueFrictionMaximum) = 0;
    /**
    * Called by the IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher when TorqueFrictionMinimum value has changed if subscribed for the TorqueFrictionMinimum change.
    * @param TorqueFrictionMinimum Minimum wheel torque request for friction brake. Brake Torque < 0Nm.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void onTorqueFrictionMinimumChanged(int32_t TorqueFrictionMinimum) = 0;
    /**
    * Called by the IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher when OmegaUpper value has changed if subscribed for the OmegaUpper change.
    * @param OmegaUpper Upper wheel speed limit request controlled by friction brake. ISO 8855 wheel-spin velocity.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void onOmegaUpperChanged(int32_t OmegaUpper) = 0;
    /**
    * Called by the IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher when OmegaLower value has changed if subscribed for the OmegaLower change.
    * @param OmegaLower Lower wheel speed limit request controlled by friction brake. ISO 8855 wheel-spin velocity.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void onOmegaLowerChanged(int32_t OmegaLower) = 0;
};

/** Callback for changes of Torque */
using VehicleMotionManagementBrakeAxleRow2WheelLeftTorquePropertyCb = std::function<void(int32_t Torque)>;
/** Callback for changes of TorqueArbitrated */
using VehicleMotionManagementBrakeAxleRow2WheelLeftTorqueArbitratedPropertyCb = std::function<void(int32_t TorqueArbitrated)>;
/** Callback for changes of TorqueFrictionMaximum */
using VehicleMotionManagementBrakeAxleRow2WheelLeftTorqueFrictionMaximumPropertyCb = std::function<void(int32_t TorqueFrictionMaximum)>;
/** Callback for changes of TorqueFrictionMinimum */
using VehicleMotionManagementBrakeAxleRow2WheelLeftTorqueFrictionMinimumPropertyCb = std::function<void(int32_t TorqueFrictionMinimum)>;
/** Callback for changes of OmegaUpper */
using VehicleMotionManagementBrakeAxleRow2WheelLeftOmegaUpperPropertyCb = std::function<void(int32_t OmegaUpper)>;
/** Callback for changes of OmegaLower */
using VehicleMotionManagementBrakeAxleRow2WheelLeftOmegaLowerPropertyCb = std::function<void(int32_t OmegaLower)>;


/**
 * The IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher provides an api for clients to subscribe to or unsubscribe from a signal emission 
 * or a property change.
 * Implement this interface to keep track of clients of your IVehicleMotionManagementBrakeAxleRow2WheelLeft implementation.
 * The publisher provides two independent methods of subscription
 *  - subscribing with a IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber objects - for all of the changes
 *  - subscribing any object for single type of change property or a signal
 * The publish functions needs to be called by implementation of the IIVehicleMotionManagementBrakeAxleRow2WheelLeft on each state changed or signal emitted
 * to notify all the subscribers about this change.
 */
class CPP_VEHICLE_EXPORT IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher
{
public:
    virtual ~IVehicleMotionManagementBrakeAxleRow2WheelLeftPublisher() = default;

    /**
    * Use this function to subscribe for any change of the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left.
    * Subscriber will be informed of any emitted signal and any property changes.
    * This is parallel notification system to single subscription. If you will subscribe also for a single change
    * your subscriber will be informed twice about that change, one for each subscription mechanism.
    * @param IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber which is subscribed in this function to any change of the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left.
    */
    virtual void subscribeToAllChanges(IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left.
    * Not all subscriptions will be removed, the ones made separately for single signal or property change stay intact.
    * Make sure to remove them.
    * @param IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber which subscription for any change of the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left is removed.
    */
    virtual void unsubscribeFromAllChanges(IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for Torque value changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param VehicleMotionManagementBrakeAxleRow2WheelLeftTorquePropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToTorqueChanged(VehicleMotionManagementBrakeAxleRow2WheelLeftTorquePropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from Torque property changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromTorqueChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for TorqueArbitrated value changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param VehicleMotionManagementBrakeAxleRow2WheelLeftTorqueArbitratedPropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToTorqueArbitratedChanged(VehicleMotionManagementBrakeAxleRow2WheelLeftTorqueArbitratedPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from TorqueArbitrated property changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromTorqueArbitratedChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for TorqueFrictionMaximum value changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param VehicleMotionManagementBrakeAxleRow2WheelLeftTorqueFrictionMaximumPropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToTorqueFrictionMaximumChanged(VehicleMotionManagementBrakeAxleRow2WheelLeftTorqueFrictionMaximumPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from TorqueFrictionMaximum property changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromTorqueFrictionMaximumChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for TorqueFrictionMinimum value changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param VehicleMotionManagementBrakeAxleRow2WheelLeftTorqueFrictionMinimumPropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToTorqueFrictionMinimumChanged(VehicleMotionManagementBrakeAxleRow2WheelLeftTorqueFrictionMinimumPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from TorqueFrictionMinimum property changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromTorqueFrictionMinimumChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for OmegaUpper value changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param VehicleMotionManagementBrakeAxleRow2WheelLeftOmegaUpperPropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToOmegaUpperChanged(VehicleMotionManagementBrakeAxleRow2WheelLeftOmegaUpperPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from OmegaUpper property changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromOmegaUpperChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for OmegaLower value changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param VehicleMotionManagementBrakeAxleRow2WheelLeftOmegaLowerPropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToOmegaLowerChanged(VehicleMotionManagementBrakeAxleRow2WheelLeftOmegaLowerPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from OmegaLower property changes.
    * If your subscriber uses subscription with IVehicleMotionManagementBrakeAxleRow2WheelLeftSubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromOmegaLowerChanged(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left implementation when property Torque changes.
    * @param The new value of Torque.
    * Estimated friction brake torque. Brake Torque < 0Nm.
    */
    virtual void publishTorqueChanged(int32_t Torque) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left implementation when property TorqueArbitrated changes.
    * @param The new value of TorqueArbitrated.
    * Brake system internally calculated friction brake torque target. Brake Torque < 0Nm.
    */
    virtual void publishTorqueArbitratedChanged(int32_t TorqueArbitrated) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left implementation when property TorqueFrictionMaximum changes.
    * @param The new value of TorqueFrictionMaximum.
    * Maximum wheel torque request for friction brake. Brake Torque < 0Nm.
    */
    virtual void publishTorqueFrictionMaximumChanged(int32_t TorqueFrictionMaximum) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left implementation when property TorqueFrictionMinimum changes.
    * @param The new value of TorqueFrictionMinimum.
    * Minimum wheel torque request for friction brake. Brake Torque < 0Nm.
    */
    virtual void publishTorqueFrictionMinimumChanged(int32_t TorqueFrictionMinimum) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left implementation when property OmegaUpper changes.
    * @param The new value of OmegaUpper.
    * Upper wheel speed limit request controlled by friction brake. ISO 8855 wheel-spin velocity.
    */
    virtual void publishOmegaUpperChanged(int32_t OmegaUpper) const = 0;
    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the Vehicle_MotionManagement_Brake_Axle_Row2_Wheel_Left implementation when property OmegaLower changes.
    * @param The new value of OmegaLower.
    * Lower wheel speed limit request controlled by friction brake. ISO 8855 wheel-spin velocity.
    */
    virtual void publishOmegaLowerChanged(int32_t OmegaLower) const = 0;
};


} // namespace Vehicle
} // namespace Cpp
