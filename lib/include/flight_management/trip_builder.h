///
/// @file trip_builder.h
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#ifndef FLIGHT_MANAGEMENT_TRIP_BUILDER_H_
#define FLIGHT_MANAGEMENT_TRIP_BUILDER_H_

#include "flight_management/trip_info.h"

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

namespace fms
{
class Flight
{
  public:
    explicit Flight(const std::string& name, const std::string& origin, const std::string& destination,
                    const std::string& operated_by, const double& airfare)
        : name_{name}, origin_{origin}, destination_{destination}, operated_by_{operated_by}, airfare_{airfare}
    {
    }

    std::string GetName() const { return name_; }
    std::string GetOriginCity() const { return origin_; }
    std::string GetDestinationCity() const { return destination_; }
    std::string GetOperator() const { return operated_by_; }
    double GetAirfare() const { return airfare_; }

    void SetAirfare(const double& airfare) { airfare_ = airfare; }

  private:
    std::string name_;
    std::string origin_;
    std::string destination_;
    std::string operated_by_;
    double airfare_;
};

inline std::ostream& operator<<(std::ostream& out, const Flight& flight)
{
    return out << "Flight{name: " << flight.GetName() << ", origin: " << flight.GetOriginCity()
               << ", destination: " << flight.GetDestinationCity() << ", operator: " << flight.GetOperator()
               << ", airfare: " << flight.GetAirfare() << "}" << std::endl;
}

class FlightDatabase
{
  public:
    FlightDatabase() {}

    void AddTrip(const std::string& name, const std::string& origin, const std::string& destination,
                 const double& airfare)
    {
        flights_.push_back(Flight{name, origin, destination, "AirIndia", airfare});
    }

    void RemoveTrip(const std::string& name)
    {
        flights_.erase(std::remove_if(flights_.begin(), flights_.end(),
                                      [&](const auto& flight) { return flight.GetName() == name; }),
                       flights_.end());
    }

    void UpdateFareByTrip(const std::string& name, const double& airfare)
    {
        auto flight_iter = std::find_if(flights_.begin(), flights_.end(),
                                        [&](const auto& flight) { return flight.GetName() == name; });
        if (flight_iter != flights_.end())
        {
            flight_iter->SetAirfare(airfare);
        }
    }

    void UpdateFareByOperator(const std::string& operated_by, const double& airfare)
    {
        auto flight_iter = std::find_if(flights_.begin(), flights_.end(),
                                        [&](const auto& flight) { return flight.GetOperator() == operated_by; });
        if (flight_iter != flights_.end())
        {
            flight_iter->SetAirfare(airfare);
        }
    }

    void DisplayAllTrips()
    {
        std::for_each(flights_.begin(), flights_.end(), [](const auto& flight) { std::cout << flight << std::endl; });
    }

    std::vector<Flight> FindFlightByNumber(const std::string& name) const
    {
        std::vector<Flight> matches;
        for (auto flight : flights_)
        {
            if (flight.GetName() == name)
            {
                matches.push_back(flight);
            }
        }
        return matches;
    }

    std::vector<Flight> FindFlightsByOriginCity(const std::string& origin) const
    {
        std::vector<Flight> matches;
        for (auto flight : flights_)
        {
            if (flight.GetOriginCity() == origin)
            {
                matches.push_back(flight);
            }
        }
        return matches;
    }

    double FindAverageCostOfAllTrips() const
    {
        std::int32_t sum = 0;
        std::for_each(flights_.begin(), flights_.end(), [&sum](const auto& flight) { sum += flight.GetAirfare(); });
        return sum / flights_.size();
    }

    double FindMinFareBetweenCities(const std::string& origin, const std::string& destination) const
    {
        double min_fare = std::numeric_limits<double>::max();
        for (auto flight : flights_)
        {
            if (flight.GetOriginCity() == origin && flight.GetDestinationCity() == destination)
            {
                min_fare = std::min(min_fare, flight.GetAirfare());
            }
        }
        return min_fare;
    }
    double FindMaxFareByOperator(const std::string& operated_by) const
    {
        double max_fare = std::numeric_limits<double>::min();
        for (auto flight : flights_)
        {
            if (flight.GetOperator() == operated_by)
            {
                max_fare = std::max(max_fare, flight.GetAirfare());
            }
        }
        return max_fare;
    }

  private:
    std::vector<Flight> flights_;
};
}  // namespace fms

#endif  /// FLIGHT_MANAGEMENT_TRIP_BUILDER_H_