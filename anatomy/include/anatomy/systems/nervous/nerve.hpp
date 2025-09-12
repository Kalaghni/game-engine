#pragma once
#include "anatomy/core/entity.hpp"
#include "anatomy/core/id.hpp"

namespace anatomy::systems::nervous {
struct Nerve : public anatomy::core::Entity {
  anatomy::core::NerveId id{};
  anatomy::core::Name nm{.english = "Unnamed nerve", .latin = "", .synonyms = {}};
  std::string_view kind() const noexcept override {
    return "Nerve";
  }
  anatomy::core::Name const &name() const noexcept override {
    return nm;
  }
};
} // namespace anatomy::systems::nervous
