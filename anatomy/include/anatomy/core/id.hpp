#pragma once
#include <cstdint>
#include <functional>

namespace anatomy::core {
template <class Tag> struct StrongId {
  using value_type = std::uint64_t;
  value_type value{};
  constexpr explicit StrongId(value_type v = 0) : value(v) {}
  friend constexpr bool operator==(StrongId a, StrongId b) {
    return a.value == b.value;
  }
  friend constexpr bool operator!=(StrongId a, StrongId b) {
    return !(a == b);
  }
  friend constexpr bool operator<(StrongId a, StrongId b) {
    return a.value < b.value;
  }
};

struct RegionTag {};
using RegionId = StrongId<RegionTag>;
struct SystemTag {};
using SystemId = StrongId<SystemTag>;
struct OrganTag {};
using OrganId = StrongId<OrganTag>;
struct TissueTag {};
using TissueId = StrongId<TissueTag>;
struct CellTag {};
using CellId = StrongId<CellTag>;
struct NerveTag {};
using NerveId = StrongId<NerveTag>;
struct MuscleTag {};
using MuscleId = StrongId<MuscleTag>;
} // namespace anatomy::core

namespace std {
template <class Tag> struct hash<anatomy::core::StrongId<Tag>> {
  size_t operator()(anatomy::core::StrongId<Tag> s) const noexcept {
    return hash<std::uint64_t>{}(s.value);
  }
};
} // namespace std
