#pragma once
#include "anatomy/core/entity.hpp"

#include <memory>
#include <vector>

namespace anatomy::core {
class CompositeEntity : public Entity {
public:
  using ptr = std::unique_ptr<Entity>;
  void add_child(ptr e) {
    children_.push_back(std::move(e));
  }
  auto const &children() const noexcept {
    return children_;
  }

private:
  std::vector<ptr> children_{};
};
} // namespace anatomy::core
