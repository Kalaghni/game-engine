#pragma once

#include <mutex>
#include <unordered_map>
#include <vector>

#include "IEventBus.h"

//------------------------------------------------------------------------------
// EventBus
//------------------------------------------------------------------------------
// Concrete thread-safe implementation of IEventBus. Handlers are stored in a
// map keyed by event type. Publish operations copy handlers outside the lock to
// keep critical sections short and avoid deadlocks.
class EventBus : public IEventBus {
public:
    EventBus() = default;
    ~EventBus() override = default;

protected:
    void SubscribeImpl(std::type_index type, HandlerFunc handler) override;
    void PublishImpl(std::type_index type, const Event& event) override;

private:
    std::unordered_map<std::type_index, std::vector<HandlerFunc>> handlers_;
    std::mutex mutex_;
};

