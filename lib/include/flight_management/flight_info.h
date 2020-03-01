///
/// @file flight_info.h
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#ifndef FLIGHT_MANAGEMENT_FLIGHT_INFO_H_
#define FLIGHT_MANAGEMENT_FLIGHT_INFO_H_

#include <units.h>
#include <chrono>
#include <ostream>
#include <string>

namespace fms
{
/// @brief Flight State (at Airport)
enum class State : std::uint32_t
{
    kInvalid = 0U,
    kOnTime = 1U,
    kDelayed = 2U,
    kCheckIn = 3U,
    kImmigration = 4U,
    kBoarding = 5U,
    kDeparted = 6U,
    kLanded = 7U,
};

/// @brief State Information on Output Stream (used for logging)
inline std::ostream& operator<<(std::ostream& out, const State& state)
{
    switch (state)
    {
        case State::kOnTime:
            out << "kOnTime";
            break;
        case State::kDelayed:
            out << "kDelayed";
            break;
        case State::kCheckIn:
            out << "kCheckIn";
            break;
        case State::kImmigration:
            out << "kImmigration";
            break;
        case State::kBoarding:
            out << "kBoarding";
            break;
        case State::kDeparted:
            out << "kDeparted";
            break;
        case State::kLanded:
            out << "kLanded";
            break;
        case State::kInvalid:
        default:
            out << "kInvalid";
            break;
    }
    return out;
}

/// @brief Flight Status
struct FlightStatus
{
    /// @brief Flight arrival/departure gate
    std::string gate;

    /// @brief Flight arrival/departure terminal
    std::int32_t terminal;

    /// @brief Flight arrival/departure time (scheduled)
    std::chrono::system_clock::time_point scheduled;

    /// @brief Flight arrival/departure time (actual)
    std::chrono::system_clock::time_point actual;

    /// @brief Flight delay time
    std::chrono::system_clock::duration delayed_by;

    /// @brief Flight Duration
    std::chrono::system_clock::duration duration;

    /// @brief Is International Flight or Domestic?
    bool is_international;

    /// @brief Flight Aircraft name
    std::string aircraft;

    /// @brief Flight State at Airport
    State state;
};

/// @brief Weather Conditions
struct WeatherConditions
{
    /// @brief Temperature (degree celsius)
    units::temperature::celsius_t temperature;

    /// @brief Wind Speed (meters per seconds)
    units::velocity::meters_per_second_t wind_speed;

    /// @brief Visibility Distance (meters)
    units::length::meter_t visibility;
};

/// @brief Airport Information
struct AirportInfo
{
    /// @brief International code for Airport
    std::string code;

    /// @brief Name of the Airport
    std::string name;

    /// @brief Name of the City
    std::string city;

    /// @brief Weather condition for Flight's arrival/departure at Airport
    WeatherConditions weather_conditions;
};

/// @brief Flight Information
struct FlightInfo
{
    /// @brief Name of flight (e.g. QR-057, SJ-345)
    std::string name;

    /// @brief Flight Operated by (Qatar Airways, SpiceJet, Jet Airways etc.)
    std::string operated_by;

    /// @brief Origin Airport/Flight Information
    AirportInfo origin;

    /// @brief Destination Airport/Flight Information
    AirportInfo destination;

    /// @brief Distance (km) to cover/covered by Flight
    units::length::kilometer_t total_distance;

    /// @brief Flight Status
    FlightStatus status;
};

}  // namespace fms
#endif  /// FLIGHT_MANAGEMENT_FLIGHT_INFO_H_