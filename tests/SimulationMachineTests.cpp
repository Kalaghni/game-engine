#include <catch_amalgamated.hpp>
#include "SimulationMachine.h"

TEST_CASE("SimulationMachine processes fixed steps") {
    int steps = 0;
    double total = 0.0;
    SimulationMachine sim(0.1, [&](double dt) {
        steps++;
        total += dt;
    });

    sim.Advance(0.35);

    REQUIRE(steps == 3);
    REQUIRE(total == Catch::Approx(0.3));
    REQUIRE(sim.GetLag() == Catch::Approx(0.05));
}

