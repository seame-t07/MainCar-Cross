

#include "vehicle/generated/core/vehiclepowertraintractionbatterychargingchargingportanyposition.publisher.h"
#include <algorithm>


using namespace Cpp::Vehicle;

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::subscribeToAllChanges(IVehiclePowertrainTractionBatteryChargingChargingPortAnyPositionSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IVehiclePowertrainTractionBatteryChargingChargingPortAnyPositionSubscriber>(subscriber));
    }
}

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::unsubscribeFromAllChanges(IVehiclePowertrainTractionBatteryChargingChargingPortAnyPositionSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::subscribeToSupportedInletTypesChanged(VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionSupportedInletTypesPropertyCb callback)
{
    auto handleId = m_supportedInletTypesChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_supportedInletTypesCallbacksMutex);
    m_supportedInletTypesCallbacks[handleId] = callback;
    return handleId;
}

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::unsubscribeFromSupportedInletTypesChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_supportedInletTypesCallbacksMutex);
    m_supportedInletTypesCallbacks.erase(handleId);
}

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::publishSupportedInletTypesChanged(Vehicle_Powertrain_TractionBattery_Charging_ChargingPort_AnyPosition_SupportedInletTypes_ValueEnum SupportedInletTypes) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onSupportedInletTypesChanged(SupportedInletTypes);
    }
    std::shared_lock<std::shared_timed_mutex> supportedInletTypesCallbacksLock(m_supportedInletTypesCallbacksMutex);
    const auto supportedInletTypesCallbacks = m_supportedInletTypesCallbacks;
    supportedInletTypesCallbacksLock.unlock();
    for(const auto& callbackEntry: supportedInletTypesCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(SupportedInletTypes);
        }
    }
}

long VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::subscribeToIsFlapOpenChanged(VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionIsFlapOpenPropertyCb callback)
{
    auto handleId = m_isFlapOpenChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_isFlapOpenCallbacksMutex);
    m_isFlapOpenCallbacks[handleId] = callback;
    return handleId;
}

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::unsubscribeFromIsFlapOpenChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_isFlapOpenCallbacksMutex);
    m_isFlapOpenCallbacks.erase(handleId);
}

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::publishIsFlapOpenChanged(bool IsFlapOpen) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onIsFlapOpenChanged(IsFlapOpen);
    }
    std::shared_lock<std::shared_timed_mutex> isFlapOpenCallbacksLock(m_isFlapOpenCallbacksMutex);
    const auto isFlapOpenCallbacks = m_isFlapOpenCallbacks;
    isFlapOpenCallbacksLock.unlock();
    for(const auto& callbackEntry: isFlapOpenCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(IsFlapOpen);
        }
    }
}

long VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::subscribeToIsChargingCableConnectedChanged(VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionIsChargingCableConnectedPropertyCb callback)
{
    auto handleId = m_isChargingCableConnectedChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_isChargingCableConnectedCallbacksMutex);
    m_isChargingCableConnectedCallbacks[handleId] = callback;
    return handleId;
}

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::unsubscribeFromIsChargingCableConnectedChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_isChargingCableConnectedCallbacksMutex);
    m_isChargingCableConnectedCallbacks.erase(handleId);
}

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::publishIsChargingCableConnectedChanged(bool IsChargingCableConnected) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onIsChargingCableConnectedChanged(IsChargingCableConnected);
    }
    std::shared_lock<std::shared_timed_mutex> isChargingCableConnectedCallbacksLock(m_isChargingCableConnectedCallbacksMutex);
    const auto isChargingCableConnectedCallbacks = m_isChargingCableConnectedCallbacks;
    isChargingCableConnectedCallbacksLock.unlock();
    for(const auto& callbackEntry: isChargingCableConnectedCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(IsChargingCableConnected);
        }
    }
}

long VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::subscribeToIsChargingCableLockedChanged(VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionIsChargingCableLockedPropertyCb callback)
{
    auto handleId = m_isChargingCableLockedChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_isChargingCableLockedCallbacksMutex);
    m_isChargingCableLockedCallbacks[handleId] = callback;
    return handleId;
}

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::unsubscribeFromIsChargingCableLockedChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_isChargingCableLockedCallbacksMutex);
    m_isChargingCableLockedCallbacks.erase(handleId);
}

void VehiclePowertrainTractionBatteryChargingChargingPortAnyPositionPublisher::publishIsChargingCableLockedChanged(bool IsChargingCableLocked) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onIsChargingCableLockedChanged(IsChargingCableLocked);
    }
    std::shared_lock<std::shared_timed_mutex> isChargingCableLockedCallbacksLock(m_isChargingCableLockedCallbacksMutex);
    const auto isChargingCableLockedCallbacks = m_isChargingCableLockedCallbacks;
    isChargingCableLockedCallbacksLock.unlock();
    for(const auto& callbackEntry: isChargingCableLockedCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(IsChargingCableLocked);
        }
    }
}

