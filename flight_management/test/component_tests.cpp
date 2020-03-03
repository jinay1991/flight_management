///
/// @file component_tests.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/flight_trip_database.h"
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
    virtual void SetUp() override
    {
        unit_ = std::make_unique<FlightTripDatabase>();
        unit_->AddTrip("AI-439", "AirIndia", "Pune", "Dubai", 10000);
        ASSERT_EQ(1U, unit_->GetTotalTrips());
    }

    /// @brief Unit under Test
    std::unique_ptr<IFlightTripDatabase> unit_;
};

TEST_F(ComponentTestSpec, GivenTypicalTrip_WhenAddTrip_ExpectUpdatedDatabase)
{
    EXPECT_EQ(1U, unit_->GetTotalTrips());
    EXPECT_FALSE(unit_->FindFlightByNumber("AI-439").empty());
}

TEST_F(ComponentTestSpec, GivenTypicalDatabase_WhenRemoveAllTrips_ExpectEmptyDatabase)
{
    unit_->RemoveTrip("AI-439");

    EXPECT_EQ(0U, unit_->GetTotalTrips());
    EXPECT_TRUE(unit_->FindFlightByNumber("AI-439").empty());
}

}  // namespace
}  // namespace fms
