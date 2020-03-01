///
/// @file flight_trip_database.h
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#ifndef FLIGHT_MANAGEMENT_FLIGHT_TRIP_DATABASE_H_
#define FLIGHT_MANAGEMENT_FLIGHT_TRIP_DATABASE_H_

#include "flight_management/i_flight_trip_database.h"

#include <algorithm>
#include <ostream>

namespace fms
{
/// @brief Flight Trip Database Interface Implementation
class FlightTripDatabase : public IFlightTripDatabase
{
  public:
    virtual ~FlightTripDatabase() = default;

    virtual void AddTrip(const std::string& name, const std::string& operated_by, const std::string& origin,
                         const std::string& destination, const double& fare) override;

    virtual void RemoveTrip(const std::string& name) override;

    virtual void UpdateFareByTrip(const std::string& name, const double& fare) override;

    virtual void UpdateFareByOperator(const std::string& operated_by, const double& fare) override;

    virtual void DisplayAllTrips() const override;

    virtual std::vector<FlightTrip> FindFlightByNumber(const std::string& name) const override;

    virtual std::vector<FlightTrip> FindFlightsByOriginCity(const std::string& origin_city) const override;

    virtual double FindAverageCostOfAllTrips() const override;

    virtual double FindMinFareBetweenCities(const std::string& origin_city,
                                            const std::string& destination_city) const override;

    virtual double FindMaxFareByOperator(const std::string& operated_by) const override;

  private:
    std::vector<FlightTrip> trips_;
};

/// @brief Output stream for all the provided trips (vector) (useful for logging)
inline std::ostream& operator<<(std::ostream& out, const std::vector<FlightTrip> trips)
{
    std::for_each(trips.begin(), trips.end(), [&](const auto& trip) { out << " (+) " << trip; });
    return out;
}

}  // namespace fms

#endif  /// FLIGHT_MANAGEMENT_FLIGHT_TRIP_DATABASE_H_