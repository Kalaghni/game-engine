#pragma once
#include "anatomy/core/metadata.hpp"

#include <string_view>

namespace anatomy::core {
class Entity {
public:
  virtual ~Entity() = default;
  virtual std::string_view kind() const noexcept = 0;
  virtual Name const &name() const noexcept = 0;
  virtual Laterality laterality() const noexcept {
    return Laterality::None;
  }
};
} // namespace anatomy::core
