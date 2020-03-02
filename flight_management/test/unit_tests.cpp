///
/// @file unit_tests.cpp
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
/// @brief Unit Test Specification
class UnitTestSpec : public ::testing::Test
{
  protected:
    /// @brief Setup Test Case Environment
    virtual void SetUp() override
    {
        unit_ = std::make_unique<FlightTripDatabase>();
        unit_->AddTrip("6E-509", "Indigo", "Pune", "Delhi", 4000);
        unit_->AddTrip("AI-238", "AirIndia", "Mumbai", "Delhi", 3000);
        ASSERT_EQ(2U, unit_->GetTotalTrips());
    }

    /// @brief Unit under Test
    std::unique_ptr<IFlightTripDatabase> unit_;
};

/// @test Test Addition of trip
TEST_F(UnitTestSpec, AddTrip)
{
    unit_ = std::make_unique<FlightTripDatabase>();
    ASSERT_EQ(0U, unit_->GetTotalTrips());

    unit_->AddTrip("6E-509", "Indigo", "Pune", "Delhi", 4000);
    EXPECT_EQ(1U, unit_->GetTotalTrips());
}

/// @test Test Removal of trip
TEST_F(UnitTestSpec, RemoveTrip)
{
    unit_->RemoveTrip("AI-238");
    EXPECT_EQ(1U, unit_->GetTotalTrips());
    EXPECT_TRUE(unit_->FindFlightByNumber("AI-238").empty());
    EXPECT_FALSE(unit_->FindFlightByNumber("6E-509").empty());
}

/// @test Test Update of fare by trip
TEST_F(UnitTestSpec, UpdateFareByTrip)
{
    unit_->UpdateFareByTrip("AI-238", 3800);
    EXPECT_EQ(2U, unit_->GetTotalTrips());
    EXPECT_DOUBLE_EQ(3800.0, unit_->FindFlightByNumber("AI-238")[0].fare);
    EXPECT_DOUBLE_EQ(4000.0, unit_->FindFlightByNumber("6E-509")[0].fare);
}

/// @test Test Update of fare by operator
TEST_F(UnitTestSpec, UpdateFareByOperator)
{
    unit_->UpdateFareByOperator("Indigo", 3800);
    EXPECT_EQ(2U, unit_->GetTotalTrips());
    EXPECT_DOUBLE_EQ(3800.0, unit_->FindFlightByNumber("6E-509")[0].fare);
    EXPECT_DOUBLE_EQ(3000.0, unit_->FindFlightByNumber("AI-238")[0].fare);
}

/// @test Test Display All Trips results
TEST_F(UnitTestSpec, DisplayAllTrips)
{
    ::testing::internal::CaptureStdout();
    unit_->DisplayAllTrips();

    auto log = ::testing::internal::GetCapturedStdout();
    EXPECT_FALSE(log.empty());
}

/// @test Test finding flight by flight number
TEST_F(UnitTestSpec, FindFlightByNumber)
{
    auto flight_trips = unit_->FindFlightByNumber("6E-509");
    EXPECT_EQ(2U, unit_->GetTotalTrips());
    EXPECT_FALSE(flight_trips.empty());
    EXPECT_EQ(flight_trips[0].name, "6E-509");
    EXPECT_EQ(flight_trips[0].operated_by, "Indigo");
}

/// @test Test finding flight by origin city
TEST_F(UnitTestSpec, FindFlightsByOriginCity)
{
    const auto flight_trips = unit_->FindFlightsByOriginCity("Pune");
    EXPECT_EQ(2U, unit_->GetTotalTrips());
    EXPECT_FALSE(flight_trips.empty());
    EXPECT_EQ(flight_trips[0].name, "6E-509");
    EXPECT_EQ(flight_trips[0].origin_city, "Pune");
}

/// @test Test finding flight average cost for all the trips
TEST_F(UnitTestSpec, FindAverageCostOfAllTrips)
{
    const auto average = unit_->FindAverageCostOfAllTrips();
    EXPECT_EQ(2U, unit_->GetTotalTrips());
    EXPECT_DOUBLE_EQ(3500, average);
}

/// @test Test finding minimum fare between cities
TEST_F(UnitTestSpec, FindMinFareBetweenCities)
{
    unit_->AddTrip("AI-529", "AirIndia", "Pune", "Delhi", 8000);
    EXPECT_EQ(3U, unit_->GetTotalTrips());

    const auto min_fare = unit_->FindMinFareBetweenCities("Pune", "Delhi");
    EXPECT_DOUBLE_EQ(4000, min_fare);
}

/// @test Test finding maximum fare by the operator
TEST_F(UnitTestSpec, FindMaxFareByOperator)
{
    unit_->AddTrip("AI-529", "AirIndia", "Pune", "Delhi", 8000);
    EXPECT_EQ(3U, unit_->GetTotalTrips());

    const auto max_fare = unit_->FindMaxFareByOperator("AirIndia");
    EXPECT_DOUBLE_EQ(8000, max_fare);
}

/// @test Test number of trips in the database
TEST_F(UnitTestSpec, GetTotalTrips) { EXPECT_EQ(2U, unit_->GetTotalTrips()); }

}  // namespace
}  // namespace fms
