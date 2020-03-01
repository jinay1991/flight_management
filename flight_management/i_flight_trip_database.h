///
/// @file i_flight_trip_database.h
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#ifndef FLIGHT_MANAGEMENT_I_FLIGHT_TRIP_DATABASE_H_
#define FLIGHT_MANAGEMENT_I_FLIGHT_TRIP_DATABASE_H_

#include "flight_management/flight_trip.h"

#include <cstdint>
#include <string>
#include <vector>

namespace fms
{
/// @brief Flight Trip Database Interface
class IFlightTripDatabase
{
  public:
    virtual ~IFlightTripDatabase() = default;

    virtual void AddTrip(const std::string& name, const std::string& operated_by, const std::string& origin,
                         const std::string& destination, const double& fare) = 0;

    virtual void RemoveTrip(const std::string& name) = 0;

    virtual void UpdateFareByTrip(const std::string& name, const double& fare) = 0;

    virtual void UpdateFareByOperator(const std::string& operated_by, const double& fare) = 0;

    virtual void DisplayAllTrips() const = 0;

    virtual std::vector<FlightTrip> FindFlightByNumber(const std::string& name) const = 0;

    virtual std::vector<FlightTrip> FindFlightsByOriginCity(const std::string& origin_city) const = 0;

    virtual double FindAverageCostOfAllTrips() const = 0;

    virtual double FindMinFareBetweenCities(const std::string& origin_city,
                                            const std::string& destination_city) const = 0;

    virtual double FindMaxFareByOperator(const std::string& operated_by) const = 0;

    virtual std::size_t GetTotalTrips(void) const = 0;
};

}  // namespace fms

#endif  /// FLIGHT_MANAGEMENT_FLIGHT_TRIP_DATABASE_H_