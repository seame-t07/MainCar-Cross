

#include "vehicle/generated/core/vehiclebodylightshazard.publisher.h"
#include <algorithm>


using namespace Cpp::Vehicle;

void VehicleBodyLightsHazardPublisher::subscribeToAllChanges(IVehicleBodyLightsHazardSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found == m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.push_back(std::reference_wrapper<IVehicleBodyLightsHazardSubscriber>(subscriber));
    }
}

void VehicleBodyLightsHazardPublisher::unsubscribeFromAllChanges(IVehicleBodyLightsHazardSubscriber& subscriber)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_allChangesSubscribersMutex);
    auto found = std::find_if(m_allChangesSubscribers.begin(), m_allChangesSubscribers.end(),
                        [&subscriber](const auto element){return &(element.get()) == &subscriber;});
    if (found != m_allChangesSubscribers.end())
    {
        m_allChangesSubscribers.erase(found);
    }
}

long VehicleBodyLightsHazardPublisher::subscribeToIsSignalingChanged(VehicleBodyLightsHazardIsSignalingPropertyCb callback)
{
    auto handleId = m_isSignalingChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_isSignalingCallbacksMutex);
    m_isSignalingCallbacks[handleId] = callback;
    return handleId;
}

void VehicleBodyLightsHazardPublisher::unsubscribeFromIsSignalingChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_isSignalingCallbacksMutex);
    m_isSignalingCallbacks.erase(handleId);
}

void VehicleBodyLightsHazardPublisher::publishIsSignalingChanged(bool IsSignaling) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onIsSignalingChanged(IsSignaling);
    }
    std::shared_lock<std::shared_timed_mutex> isSignalingCallbacksLock(m_isSignalingCallbacksMutex);
    const auto isSignalingCallbacks = m_isSignalingCallbacks;
    isSignalingCallbacksLock.unlock();
    for(const auto& callbackEntry: isSignalingCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(IsSignaling);
        }
    }
}

long VehicleBodyLightsHazardPublisher::subscribeToIsDefectChanged(VehicleBodyLightsHazardIsDefectPropertyCb callback)
{
    auto handleId = m_isDefectChangedCallbackNextId++;
    std::unique_lock<std::shared_timed_mutex> lock(m_isDefectCallbacksMutex);
    m_isDefectCallbacks[handleId] = callback;
    return handleId;
}

void VehicleBodyLightsHazardPublisher::unsubscribeFromIsDefectChanged(long handleId)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_isDefectCallbacksMutex);
    m_isDefectCallbacks.erase(handleId);
}

void VehicleBodyLightsHazardPublisher::publishIsDefectChanged(bool IsDefect) const
{
    std::shared_lock<std::shared_timed_mutex> allChangesSubscribersLock(m_allChangesSubscribersMutex);
    const auto allChangesSubscribers = m_allChangesSubscribers;
    allChangesSubscribersLock.unlock();
    for(const auto& subscriber: allChangesSubscribers)
    {
        subscriber.get().onIsDefectChanged(IsDefect);
    }
    std::shared_lock<std::shared_timed_mutex> isDefectCallbacksLock(m_isDefectCallbacksMutex);
    const auto isDefectCallbacks = m_isDefectCallbacks;
    isDefectCallbacksLock.unlock();
    for(const auto& callbackEntry: isDefectCallbacks)
    {
        if(callbackEntry.second)
        {
            callbackEntry.second(IsDefect);
        }
    }
}

