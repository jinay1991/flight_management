///
/// @file smoke_tests.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/i_flight_trip_database.h"

#include <gtest/gtest.h>

namespace fms
{
namespace
{
/// @brief Smoke Test Fixture
class SmokeTestSpec : public ::testing::Test
{
  protected:
    virtual void SetUp() override {}
    virtual void TearDown() override {}

    std::unique_ptr<IFlightTripDatabase> unit_;
};

}  // namespace
}  // namespace fms