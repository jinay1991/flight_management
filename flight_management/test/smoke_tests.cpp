///
/// @file smoke_tests.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/flight_trip_database.h"
#include "flight_management/i_flight_trip_database.h"

#include <gtest/gtest.h>
#include <cstdint>
#include <iomanip>
#include <memory>

namespace fms
{
namespace
{
/// @brief Smoke Test Fixture
class SmokeTestSpec : public ::testing::Test
{
  protected:
    virtual void SetUp() override { unit_ = std::make_unique<FlightTripDatabase>(); }
    virtual void TearDown() override {}

    /// @brief Unit under Test
    std::unique_ptr<IFlightTripDatabase> unit_;

    const std::uint32_t smoke_iteration_{999U};
};

TEST_F(SmokeTestSpec, GivenTypicalTrip_WhenAddTrip_ExpectNoException)
{
    for (auto idx = 0U; idx < smoke_iteration_; ++idx)
    {
        std::stringstream flight_number{"AI-"};
        flight_number << "AI-" << std::to_string(idx + 1);
        unit_->AddTrip(flight_number.str(), "AirIndia", "Pune", "Delhi", 4000);
        ASSERT_EQ(idx + 1, unit_->GetTotalTrips());
    }
    EXPECT_EQ(smoke_iteration_, unit_->GetTotalTrips());
    EXPECT_EQ(smoke_iteration_, unit_->FindFlightsByOriginCity("Pune").size());
}

}  // namespace
}  // namespace fms
