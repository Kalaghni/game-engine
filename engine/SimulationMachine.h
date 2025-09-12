#pragma once

#include <functional>

//------------------------------------------------------------------------------
// SimulationMachine
//------------------------------------------------------------------------------
// Executes simulation steps at a fixed timestep. Accumulates variable frame
// times and invokes the provided update callback as many times as necessary to
// catch up.
class SimulationMachine {
public:
    using UpdateFunc = std::function<void(double)>;

    // Constructs the machine with a fixed timestep and update callback.
    SimulationMachine(double fixed_delta, UpdateFunc update);

    // Advances the simulation by the given frame time. The update callback is
    // invoked zero or more times with the fixed timestep until the accumulated
    // time is less than one step.
    void Advance(double frame_time);

    // Returns the remaining unprocessed time in the accumulator.
    double GetLag() const;

private:
    double fixed_delta_;
    UpdateFunc update_;
    double lag_;
};

