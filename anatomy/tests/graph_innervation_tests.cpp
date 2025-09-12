#include "anatomy/core/id.hpp"
#include "anatomy/graph/innervation.hpp"

#include <gtest/gtest.h>

using namespace anatomy;

TEST(Innervation, AddAndLookup) {
  graph::InnervationIndex idx;
  core::NerveId femoral{10};
  core::MuscleId quadriceps{200};
  idx.add({femoral, quadriceps, graph::Modality::SomaticMotor});
  auto &byN = idx.by_nerve(femoral);
  ASSERT_EQ(byN.size(), 1u);
  EXPECT_EQ(byN[0].effector.value, quadriceps.value);
  auto &byE = idx.by_effector(quadriceps);
  ASSERT_EQ(byE.size(), 1u);
  EXPECT_EQ(byE[0].nerve.value, femoral.value);
}
