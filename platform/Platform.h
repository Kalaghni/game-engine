#pragma once

//------------------------------------------------------------------------------
// Platform
//------------------------------------------------------------------------------
// Abstract interface isolating OS-specific services (windowing, input, timing).
// Engine code communicates through this API only, allowing platform modules to
// provide their own implementations for different targets (desktop, web, etc.).
class Platform {
public:
    virtual ~Platform() = default;

    // Performs platform initialization (window creation, context setup).
    virtual bool Initialize() = 0;

    // Polls system events (input, window messages).
    virtual void PollEvents() = 0;

    // Cleans up all platform resources.
    virtual void Shutdown() = 0;
};
