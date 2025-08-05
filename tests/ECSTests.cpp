#include <catch_amalgamated.hpp>
#include "SimpleECS.h"

struct Position {
    int x;
    int y;
    Position() = default;
    Position(int x_, int y_) : x(x_), y(y_) {}
};

TEST_CASE("SimpleECS stores and retrieves components") {
    SimpleECS ecs;
    auto e = ecs.CreateEntity();
    ecs.AddComponent<Position>(e, 1, 2);
    auto* p = ecs.GetComponent<Position>(e);
    REQUIRE(p);
    REQUIRE(p->x == 1);
    REQUIRE(p->y == 2);
    ecs.RemoveComponent<Position>(e);
    REQUIRE(ecs.GetComponent<Position>(e) == nullptr);
}

TEST_CASE("SimpleECS updates registered systems") {
    SimpleECS ecs;
    double acc = 0.0;
    ecs.RegisterSystem([&](double dt) { acc += dt; });
    ecs.Update(0.5);
    ecs.Update(0.5);
    REQUIRE(acc == Catch::Approx(1.0));
}

