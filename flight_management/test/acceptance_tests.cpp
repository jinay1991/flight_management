///
/// @file acceptance_tests.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/flight_trip_database.h"
#include "flight_management/i_flight_trip_database.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>

namespace fms
{
namespace
{
/// @brief Acceptance Test Fixture
class AcceptanceTestSpec : public ::testing::Test
{
  protected:
    virtual void SetUp() override { unit_ = std::make_unique<FlightTripDatabase>(); }
    virtual void TearDown() override {}

    /// @brief Unit under Test
    std::unique_ptr<IFlightTripDatabase> unit_;
};

/// @test
TEST_F(AcceptanceTestSpec, GivenFlightTripDatabase_WhenUpdated_ExpectDatabaseUpdates) {}

/// @test
/// @unittest
TEST_F(AcceptanceTestSpec, GivenEmptyFlightTripDatabase_WhenSearchedForTrips_ExpectNoResults)
{
    unit_->AddTrip("AI-345", "AirIndia", "Chennai", "Pune", 4000);

    EXPECT_FALSE(unit_->FindFlightByNumber("AI-345").empty());
    EXPECT_LT(0U, unit_->GetTotalTrips());
}

}  // namespace
}  // namespace fms
