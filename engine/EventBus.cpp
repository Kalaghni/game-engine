#include "EventBus.h"

//------------------------------------------------------------------------------
// EventBus Implementation
//------------------------------------------------------------------------------

void EventBus::SubscribeImpl(std::type_index type, HandlerFunc handler) {
    std::lock_guard<std::mutex> lock(mutex_);
    handlers_[type].push_back(std::move(handler));
}

void EventBus::PublishImpl(std::type_index type, const Event& event) {
    std::vector<HandlerFunc> listeners;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = handlers_.find(type);
        if (it != handlers_.end()) {
            listeners = it->second; // Copy to avoid holding lock while invoking.
        }
    }
    for (const auto& listener : listeners) {
        listener(event);
    }
}

