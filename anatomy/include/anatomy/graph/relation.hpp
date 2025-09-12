#pragma once
#include <string>

namespace anatomy::graph {
template <class FromId, class ToId> struct Relation {
  FromId from;
  ToId to;
  std::string note;
};
} // namespace anatomy::graph
