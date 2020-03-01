///
/// @file flight_builder.h
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#ifndef FLIGHT_MANAGEMENT_FLIGHT_BUILDER_H_
#define FLIGHT_MANAGEMENT_FLIGHT_BUILDER_H_

#include "flight_management/flight_info.h"
#include "flight_management/trip_info.h"

#include <vector>

namespace fms
{
class FlightStatusBuilder
{
  public:
    FlightStatusBuilder& WithGate(const std::string& gate)
    {
        status_.gate = gate;
        return *this;
    }

    FlightStatusBuilder& WithTerminal(const std::int32_t& terminal)
    {
        status_.terminal = terminal;
        return *this;
    }

    FlightStatusBuilder& WithScheduledTime(const std::chrono::system_clock::time_point& scheduled)
    {
        status_.scheduled = scheduled;
        return *this;
    }

    FlightStatusBuilder& WithActualTime(const std::chrono::system_clock::time_point& actual)
    {
        status_.actual = actual;
        status_.delayed_by = status_.actual - status_.scheduled;
        return *this;
    }

    FlightStatusBuilder& WithFlightDuration(const std::chrono::system_clock::duration& duration)
    {
        status_.duration = duration;
        return *this;
    }

    FlightStatusBuilder& IsInternationalFlight(const bool& is_international)
    {
        status_.is_international = is_international;
        return *this;
    }

    FlightStatusBuilder& WithAircraft(const std::string& aircraft)
    {
        status_.aircraft = aircraft;
        return *this;
    }

    FlightStatusBuilder& WithInitialFlightState(const State& state)
    {
        status_.state = state;
        return *this;
    }

    FlightStatus Build() const { return status_; }

  private:
    FlightStatus status_;
};

class FlightBuilder
{
  public:
    FlightBuilder() = default;

    FlightBuilder& WithName(const std::string& name)
    {
        flight_.name = name;
        return *this;
    }

    FlightBuilder& WithOriginCity(const std::string& origin, const std::string& airport_code,
                                  const std::string& airport_name, const WeatherConditions& airport_weather_conditions)
    {
        flight_.origin = AirportInfo{airport_code, airport_name, origin, airport_weather_conditions};
        return *this;
    }

    FlightBuilder& WithDestinationCity(const std::string& origin, const std::string& airport_code,
                                       const std::string& airport_name,
                                       const WeatherConditions& airport_weather_conditions)
    {
        flight_.destination = AirportInfo{airport_code, airport_name, origin, airport_weather_conditions};
        return *this;
    }

    FlightBuilder& WithDistance(const units::length::kilometer_t& total_distance)
    {
        flight_.total_distance = total_distance;
        return *this;
    }

    FlightBuilder& WithOperator(const std::string& operated_by)
    {
        flight_.operated_by = operated_by;
        return *this;
    }

    FlightBuilder& WithStatus(const FlightStatus& status)
    {
        flight_.status = status;
        return *this;
    }

    FlightInfo Build() const { return flight_; }

  private:
    FlightInfo flight_;
};

class TripBuilder
{
  public:
    TripBuilder& WithFlight(const FlightInfo& flight)
    {
        trip_.flight = flight;
        return *this;
    }

    TripBuilder& WithOriginCity(const std::string& origin, const std::string& airport_code,
                                const std::string& airport_name, const WeatherConditions& airport_weather_conditions)
    {
        trip_.origin = AirportInfo{airport_code, airport_name, origin, airport_weather_conditions};
        return *this;
    }

    TripBuilder& WithDestinationCity(const std::string& destination, const std::string& airport_code,
                                     const std::string& airport_name,
                                     const WeatherConditions& airport_weather_conditions)
    {
        trip_.destination = AirportInfo{airport_code, airport_name, destination, airport_weather_conditions};
        return *this;
    }

    TripBuilder& WithFare(const double& fare, const Fare::Currency& currency_type)
    {
        trip_.fare.total_fare = fare;
        trip_.fare.currency_type = currency_type;
        return *this;
    }

    TripInfo Build() const { return trip_; }

  private:
    TripInfo trip_;
};

class IFlightManagementSystem
{
  public:
    virtual ~IFlightManagementSystem() = default;

    virtual void AddTrip(const std::string& name, const std::string& origin, const std::string& destination,
                         const double& fare) = 0;

    virtual void RemoveTrip(const std::string& name) = 0;

    virtual void UpdateFareByTrip(const std::string& name, const double& airfare) = 0;

    virtual void UpdateFareByOperator(const std::string& operated_by, const double& airfare) = 0;

    virtual void DisplayAllTrips() = 0;

    virtual std::vector<TripInfo> FindFlightByNumber(const std::string& name) const = 0;
    virtual std::vector<TripInfo> FindFlightsByOriginCity(const std::string& origin) const = 0;
    virtual double FindAverageCostOfAllTrips() const = 0;
    virtual double FindMinFareBetweenCities(const std::string& origin, const std::string& destination) const = 0;
    virtual double FindMaxFareByOperator(const std::string& operated_by) const = 0;
};

class FlightTripDatabaseBuilder
{
  public:
    FlightTripDatabaseBuilder& WithTrip(const TripInfo& trip)
    {
        trips_.push_back(trip);
        return *this;
    }

    std::vector<TripInfo> Build() const { return trips_; }

  private:
    std::vector<TripInfo> trips_;
};

}  // namespace fms

#endif  /// FLIGHT_MANAGEMENT_FLIGHT_BUILDER_H_