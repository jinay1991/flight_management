///
/// @file flight_info_test.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include <gtest/gtest.h>

#include "flight_management/flight_info.h"

namespace fms
{
namespace
{
/// @brief Test Fixture for Flight Info
class FlightInfoFixture : public ::testing::Test
{
  protected:
    virtual void SetUp() override {}
    virtual void TearDown() override {}

    FlightInfo unit_;
};

/// @test Construct Flight Info with Default constructor
TEST_F(FlightInfoFixture, DefaultConstructor) {}

}  // namespace
}  // namespace fms