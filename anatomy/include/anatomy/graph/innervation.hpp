#pragma once
#include "anatomy/core/id.hpp"

#include <unordered_map>
#include <vector>

namespace anatomy::graph {
enum class Modality { SomaticMotor, SomaticSensory, Preganglionic, Postganglionic };

struct InnervationEdge {
  anatomy::core::NerveId nerve;
  anatomy::core::MuscleId effector; // placeholder for more effectors
  Modality modality{Modality::SomaticMotor};
};

class InnervationIndex {
public:
  void add(InnervationEdge e) {
    by_nerve_[e.nerve].push_back(e);
    by_effector_[e.effector].push_back(e);
  }
  std::vector<InnervationEdge> const &by_nerve(anatomy::core::NerveId n) const {
    static const std::vector<InnervationEdge> empty;
    auto it = by_nerve_.find(n);
    return it == by_nerve_.end() ? empty : it->second;
  }
  std::vector<InnervationEdge> const &by_effector(anatomy::core::MuscleId m) const {
    static const std::vector<InnervationEdge> empty;
    auto it = by_effector_.find(m);
    return it == by_effector_.end() ? empty : it->second;
  }

private:
  std::unordered_map<anatomy::core::NerveId, std::vector<InnervationEdge>> by_nerve_;
  std::unordered_map<anatomy::core::MuscleId, std::vector<InnervationEdge>> by_effector_;
};
} // namespace anatomy::graph
