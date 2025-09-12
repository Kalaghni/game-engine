#include "SimulationMachine.h"

SimulationMachine::SimulationMachine(double fixed_delta, UpdateFunc update)
    : fixed_delta_(fixed_delta), update_(std::move(update)), lag_(0.0) {}

void SimulationMachine::Advance(double frame_time) {
    lag_ += frame_time;
    while (lag_ >= fixed_delta_) {
        update_(fixed_delta_);
        lag_ -= fixed_delta_;
    }
}

double SimulationMachine::GetLag() const {
    return lag_;
}

