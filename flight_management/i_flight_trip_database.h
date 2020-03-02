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
    /// @brief Destructor
    virtual ~IFlightTripDatabase() = default;

    /// @brief Add Flight Trip to the Database
    ///
    /// @param name[in] - Flight number/name
    /// @param operated_by[in] - Flight Operator
    /// @param origin[in] - Flight Origin City
    /// @param destination[in] - Flight Destination City
    /// @param fare[in] - Flight Airfare
    ///
    virtual void AddTrip(const std::string& name, const std::string& operated_by, const std::string& origin,
                         const std::string& destination, const double& fare) = 0;

    /// @brief Remove Trip from the database
    ///
    /// @param name[in] - Flight Number/name to be deleted from Database
    ///                   If trip does not exist, function does nothing.
    ///
    virtual void RemoveTrip(const std::string& name) = 0;

    /// @brief Update Flight Fare for the provided Trip
    /// @param name[in] - Flight Number/name to be updated in Database
    ///                   If trip does not exist, function does nothing.
    virtual void UpdateFareByTrip(const std::string& name, const double& fare) = 0;

    /// @brief Update Flight Fare for the provided Trip
    /// @param operated_by[in] - Flight operator to be updated in Database
    ///                          If trip does not exist, function does nothing.
    /// @param fare[in] - Flight fare
    virtual void UpdateFareByOperator(const std::string& operated_by, const double& fare) = 0;

    /// @brief Display all trips in database
    virtual void DisplayAllTrips() const = 0;

    /// @brief Find flight trips by flight number/name
    ///
    /// @param name[in] - Flight Number/name to search
    ///
    /// @return flight_trips - list of flight trips
    virtual std::vector<FlightTrip> FindFlightByNumber(const std::string& name) const = 0;

    /// @brief Find flight trips by flight origin city
    ///
    /// @param origin_city[in] - Flight origin city to search
    ///
    /// @return flight_trips - list of flight trips
    virtual std::vector<FlightTrip> FindFlightsByOriginCity(const std::string& origin_city) const = 0;

    /// @brief Find average cost of all the trips
    ///
    /// @return min_fare - average fare cost of flight trips
    virtual double FindAverageCostOfAllTrips() const = 0;

    /// @brief Find minimum fare cost flight between provided cities
    ///
    /// @param origin_city[in] - Flight origin city
    /// @param destination_city[in] - Flight destination city
    ///
    /// @return min_fare - minimum fare cost of flight trips between provided cities
    virtual double FindMinFareBetweenCities(const std::string& origin_city,
                                            const std::string& destination_city) const = 0;

    /// @brief Find maximum fare cost flight trip from provided operator
    ///
    /// @param operated_by[in] - Flight operator
    ///
    /// @return max_fare - maximum fare cost of flight trips from provided operator
    virtual double FindMaxFareByOperator(const std::string& operated_by) const = 0;

    /// @brief Get Total number of trips in database
    ///
    /// @return length - total number of trips in database
    virtual std::size_t GetTotalTrips(void) const = 0;
};

}  // namespace fms

#endif  /// FLIGHT_MANAGEMENT_FLIGHT_TRIP_DATABASE_H_
