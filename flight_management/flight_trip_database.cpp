///
/// @file flight_trip_database.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/flight_trip_database.h"
#include "flight_management/logging.h"

#include <algorithm>
#include <iostream>
#include <numeric>

namespace fms
{
void FlightTripDatabase::AddTrip(const std::string& name, const std::string& operated_by, const std::string& origin,
                                 const std::string& destination, const double& fare)
{
    LOG(INFO) << "Adding Trip {" << name << "}";
    trips_.push_back(FlightTrip{name, operated_by, origin, destination, fare});
}

void FlightTripDatabase::RemoveTrip(const std::string& name)
{
    LOG(INFO) << "Removing Trip {" << name << "}";
    trips_.erase(std::remove_if(trips_.begin(), trips_.end(), [&name](const auto& trip) { return trip.name == name; }),
                 trips_.end());
}

void FlightTripDatabase::UpdateFareByTrip(const std::string& name, const double& fare)
{
    LOG(INFO) << "Updating Fare for Trip {" << name << "}";
    std::transform(trips_.begin(), trips_.end(), trips_.begin(), [&](auto& trip) {
        if (trip.name == name)
        {
            trip.fare = fare;
        }
        return trip;
    });
}

void FlightTripDatabase::UpdateFareByOperator(const std::string& operated_by, const double& fare)
{
    LOG(INFO) << "Updating Fare for Operator {" << operated_by << "}";
    std::transform(trips_.begin(), trips_.end(), trips_.begin(), [&](auto& trip) {
        if (trip.operated_by == operated_by)
        {
            trip.fare = fare;
        }
        return trip;
    });
}

void FlightTripDatabase::DisplayAllTrips() const
{
    LOG(INFO) << "Current available trips: " << std::endl << trips_;
}

std::vector<FlightTrip> FlightTripDatabase::FindFlightByNumber(const std::string& name) const
{
    std::vector<FlightTrip> matches;
    std::copy_if(trips_.begin(), trips_.end(), std::back_inserter(matches),
                 [&name](const auto& trip) { return trip.name == name; });
    return matches;
}

std::vector<FlightTrip> FlightTripDatabase::FindFlightsByOriginCity(const std::string& origin_city) const
{
    std::vector<FlightTrip> matches;
    std::copy_if(trips_.begin(), trips_.end(), std::back_inserter(matches),
                 [&origin_city](const auto& trip) { return trip.origin_city == origin_city; });
    return matches;
}

double FlightTripDatabase::FindAverageCostOfAllTrips() const
{
    double sum = 0.0;
    std::for_each(trips_.begin(), trips_.end(), [&sum](const auto& trip) { return sum += trip.fare; });
    return sum / static_cast<double>(GetTotalTrips());
}

double FlightTripDatabase::FindMinFareBetweenCities(const std::string& origin_city,
                                                    const std::string& destination_city) const
{
    double min_fare = std::numeric_limits<double>::max();
    std::for_each(trips_.begin(), trips_.end(), [&](const auto& trip) {
        if (trip.origin_city == origin_city && trip.destination_city == destination_city)
        {
            min_fare = std::min(min_fare, trip.fare);
        }
    });
    return min_fare;
}

double FlightTripDatabase::FindMaxFareByOperator(const std::string& operated_by) const
{
    double max_fare = std::numeric_limits<double>::min();
    std::for_each(trips_.begin(), trips_.end(), [&](const auto& trip) {
        if (trip.operated_by == operated_by)
        {
            max_fare = std::max(max_fare, trip.fare);
        }
    });
    return max_fare;
}
}  // namespace fms
