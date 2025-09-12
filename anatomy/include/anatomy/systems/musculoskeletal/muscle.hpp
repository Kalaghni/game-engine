#pragma once
#include "anatomy/core/entity.hpp"
#include "anatomy/core/id.hpp"

namespace anatomy::systems::musculoskeletal {
struct Muscle : public anatomy::core::Entity {
  anatomy::core::MuscleId id{};
  anatomy::core::Name nm{.english = "Unnamed muscle", .latin = "", .synonyms = {}};
  std::string_view kind() const noexcept override {
    return "Muscle";
  }
  anatomy::core::Name const &name() const noexcept override {
    return nm;
  }
};
} // namespace anatomy::systems::musculoskeletal
