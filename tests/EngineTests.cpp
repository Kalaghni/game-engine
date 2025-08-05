#define CATCH_CONFIG_MAIN
#include <catch_amalgamated.hpp>
#include "Engine.h"
#include "Platform.h"
#include "EventBus.h"

// Test-specific platform that tracks calls to verify Engine lifecycle.
class TestPlatform : public Platform {
public:
    bool initialize_called = false;
    int poll_count = 0;
    bool shutdown_called = false;

    bool Initialize() override {
        initialize_called = true;
        return true;
    }

    void PollEvents() override { poll_count++; }

    void Shutdown() override { shutdown_called = true; }
};

TEST_CASE("Engine initializes, runs once, and shuts down") {
    auto platform = std::make_unique<TestPlatform>();
    TestPlatform* raw = platform.get();
    Engine engine(std::move(platform));

    REQUIRE(engine.Initialize());
    engine.Run();
    engine.Shutdown();

    REQUIRE(raw->initialize_called);
    REQUIRE(raw->poll_count == 1);
    REQUIRE(raw->shutdown_called);
}

struct TestEvent : public Event {
    explicit TestEvent(int v) : value(v) {}
    int value;
};

TEST_CASE("EventBus dispatches subscribed events") {
    EventBus bus;
    int received = 0;
    bus.Subscribe<TestEvent>([&](const TestEvent& e) { received = e.value; });
    bus.Publish(TestEvent{42});
    REQUIRE(received == 42);
}
