#include "Engine.h"
#include "PlatformStub.h"
#include "IEvent.h"

#include <iostream>

//------------------------------------------------------------------------------
// Entry point demonstrating engine and platform separation.
//------------------------------------------------------------------------------
// Simple custom event demonstrating the event system in action.
struct TickEvent : public Event {
    explicit TickEvent(int f) : frame(f) {}
    int frame = 0;
};

int main() {
    auto platform = std::make_unique<PlatformStub>();
    Engine engine(std::move(platform));

    // Subscribe to TickEvent before initialization to illustrate decoupled
    // communication between game code and engine subsystems.
    engine.GetEventBus().Subscribe<TickEvent>([](const TickEvent& e) {
        std::cout << "Tick event received for frame " << e.frame << std::endl;
    });

    if (!engine.Initialize()) {
        return -1;
    }

    // Emit a single TickEvent for demonstration.
    engine.GetEventBus().Publish(TickEvent{1});

    engine.Run();
    engine.Shutdown();
    return 0;
}
