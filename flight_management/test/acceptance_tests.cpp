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
    virtual void SetUp() override
    {
        unit_ = std::make_unique<FlightTripDatabase>();
        unit_->AddTrip("AI-854", "AirIndia", "Pune", "Delhi", 5000);
        unit_->AddTrip("6E-702", "Indigo", "Pune", "Bengaluru", 3000);
        unit_->AddTrip("6E-302", "Indigo", "Mumbai", "Bengaluru", 3230);
        ASSERT_EQ(3U, unit_->GetTotalTrips());
    }
    virtual void TearDown() override {}

    /// @brief Unit under Test
    std::unique_ptr<IFlightTripDatabase> unit_;
};

/// @test Test Flight Trip Database for acceptance
TEST_F(AcceptanceTestSpec, GivenEmptyFlightTripDatabase_WhenSearchedForTrips_ExpectNoResults)
{
    unit_->AddTrip("SJ-512", "SpiceJet", "Bengaluru", "Ahmedabad", 5000);
    ASSERT_EQ(4U, unit_->GetTotalTrips());

    unit_->RemoveTrip("SJ-512");
    ASSERT_EQ(3U, unit_->GetTotalTrips());
    EXPECT_TRUE(unit_->FindFlightByNumber("SJ-512").empty());

    unit_->UpdateFareByTrip("6E-702", 5000);
    ASSERT_EQ(1U, unit_->FindFlightByNumber("6E-702").size());
    EXPECT_DOUBLE_EQ(5000, unit_->FindFlightByNumber("6E-702")[0].fare);

    EXPECT_EQ(1U, unit_->FindFlightByNumber("6E-302").size());
    EXPECT_EQ("6E-302", unit_->FindFlightByNumber("6E-302")[0].name);
    EXPECT_EQ(2U, unit_->FindFlightsByOriginCity("Pune").size());
    EXPECT_EQ("Pune", unit_->FindFlightsByOriginCity("Pune")[0].origin_city);
    EXPECT_EQ("Pune", unit_->FindFlightsByOriginCity("Pune")[1].origin_city);

    EXPECT_DOUBLE_EQ(4410.0, unit_->FindAverageCostOfAllTrips());

    EXPECT_DOUBLE_EQ(5000.0, unit_->FindMinFareBetweenCities("Pune", "Bengaluru"));

    EXPECT_DOUBLE_EQ(5000.0, unit_->FindMaxFareByOperator("Indigo"));

    unit_->UpdateFareByOperator("AirIndia", 4500);
    EXPECT_EQ(1U, unit_->FindFlightByNumber("AI-854").size());
    EXPECT_DOUBLE_EQ(4500.0, unit_->FindFlightByNumber("AI-854")[0].fare);
}

}  // namespace
}  // namespace fms
