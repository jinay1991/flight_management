///
/// @file component_tests.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/i_flight_trip_database.h"

#include <gtest/gtest.h>
#include <memory>

namespace fms
{
namespace
{
/// @brief Component Test Fixture
class ComponentTestSpec : public ::testing::Test
{
  protected:
    virtual void SetUp() override {}
    virtual void TearDown() override {}

    /// @brief Unit under Test
    std::unique_ptr<IFlightTripDatabase> unit_;
};

}  // namespace
}  // namespace fms
