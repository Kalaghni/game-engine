#include "anatomy/core/id.hpp"

#include <gtest/gtest.h>

TEST(CoreIds, StrongIdEquality) {
  anatomy::core::NerveId a{1}, b{1}, c{2};
  EXPECT_EQ(a, b);
  EXPECT_NE(a, c);
  anatomy::core::MuscleId m{1};
  EXPECT_EQ(m.value, 1u);
}
