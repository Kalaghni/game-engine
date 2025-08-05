#pragma once

#include <functional>
#include <typeindex>

#include "IEvent.h"

//------------------------------------------------------------------------------
// IEventBus
//------------------------------------------------------------------------------
// Interface describing a type-safe publish/subscribe event bus. Templated
// wrappers forward to a type-erased core so subsystems remain decoupled while
// allowing the bus to store handlers generically.
class IEventBus {
public:
    virtual ~IEventBus() = default;

    // Registers a callback for a specific event type. Handlers are invoked on
    // the thread that publishes the event.
    template <typename EventT>
    void Subscribe(std::function<void(const EventT&)> handler) {
        SubscribeImpl(typeid(EventT), [fn = std::move(handler)](const Event& e) {
            fn(static_cast<const EventT&>(e));
        });
    }

    // Broadcasts an event instance to all listeners of its type.
    template <typename EventT>
    void Publish(const EventT& event) {
        PublishImpl(typeid(EventT), event);
    }

protected:
    using HandlerFunc = std::function<void(const Event&)>;

    // Implemented by concrete buses to store handlers and dispatch events.
    virtual void SubscribeImpl(std::type_index type, HandlerFunc handler) = 0;
    virtual void PublishImpl(std::type_index type, const Event& event) = 0;
};

