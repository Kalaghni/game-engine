#include "Engine.h"
#include "Platform.h" // Interface; implementation provided by platform module.

#include <iostream>

Engine::Engine(std::unique_ptr<Platform> platform)
    : platform_(std::move(platform)) {}

Engine::~Engine() = default;

bool Engine::Initialize() {
    if (!platform_ || !platform_->Initialize()) {
        std::cerr << "Engine failed to initialize platform." << std::endl;
        return false;
    }
    running_ = true;
    return true;
}

void Engine::Run() {
    // Basic stub loop. In the future this will host a fixed timestep update,
    // rendering, and subsystem coordination.
    while (running_) {
        platform_->PollEvents();
        // Placeholder for game and engine updates.
        running_ = false; // Run one iteration for demonstration purposes.
    }
}

void Engine::Shutdown() {
    if (platform_) {
        platform_->Shutdown();
    }
    running_ = false;
}

EventBus& Engine::GetEventBus() {
    return event_bus_;
}
