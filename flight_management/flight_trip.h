///
/// @file flight_trip.h
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#ifndef FLIGHT_MANAGEMENT_FLIGHT_TRIP_H_
#define FLIGHT_MANAGEMENT_FLIGHT_TRIP_H_

#include <ostream>
#include <string>

namespace fms
{
/// @brief Flight Trip Information
struct FlightTrip
{
    /// @brief Name of flight (e.g. QR-057, SJ-345)
    std::string name;

    /// @brief Flight Operator (AirIndia, SpiceJet, Jet Airways etc.)
    std::string operated_by;

    /// @brief Origin City
    std::string origin_city;

    /// @brief Destination City
    std::string destination_city;

    /// @brief Fare
    double fare;
};

/// @brief Prepares output stream for detailing FlightTrip object (useful for logging)
inline std::ostream& operator<<(std::ostream& out, const FlightTrip& flight_trip)
{
    return out << "FlightTrip{name: " << flight_trip.name << ", operator: " << flight_trip.operated_by
               << ", origin_city: " << flight_trip.origin_city << ", destination_city: " << flight_trip.destination_city
               << ", fare: " << flight_trip.fare << "}" << std::endl;
}

}  // namespace fms

#endif  /// FLIGHT_MANAGEMENT_FLIGHT_TRIP_H_
