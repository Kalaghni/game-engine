#pragma once

//------------------------------------------------------------------------------
// IEvent
//------------------------------------------------------------------------------
// Base type for all events dispatched through the engine's event system. A
// virtual destructor enables safe polymorphic destruction and downcasting.
// Keeping the interface minimal encourages lightweight, POD-like event types
// for cache-friendly broadcasting.
struct Event {
    virtual ~Event() = default;
};

