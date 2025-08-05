#pragma once

#include <memory>

// Forward declaration to avoid coupling engine to specific platform implementations.
class Platform;

#include "EventBus.h"

//------------------------------------------------------------------------------
// Engine
//------------------------------------------------------------------------------
// Core orchestrator of the Titan Engine. Owns the main game loop and bridges
// platform-specific services through the abstract Platform interface. Designed
// for extensibility and high-performance cross-platform support.
class Engine {
public:
    // Accepts ownership of a platform abstraction to decouple engine logic
    // from OS-specific implementations.
    explicit Engine(std::unique_ptr<Platform> platform);
    ~Engine();

    // Initializes subsystems. Returns false if initialization fails.
    bool Initialize();

    // Runs the main game loop. For now, this is a simple stub demonstrating
    // engine/platform separation.
    void Run();

    // Shuts down all subsystems gracefully.
    void Shutdown();

    // Access the global event bus for decoupled communication.
    EventBus& GetEventBus();

private:
    std::unique_ptr<Platform> platform_;
    bool running_ = false;
    EventBus event_bus_;
};
