///
/// @file trip_info.h
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#ifndef FLIGHT_MANAGEMENT_TRIP_INFO_H_
#define FLIGHT_MANAGEMENT_TRIP_INFO_H_

#include "flight_management/flight_info.h"

namespace fms
{
/// @brief Fare Information
struct Fare
{
    /// @brief Currency Type
    enum class Currency : std::uint32_t
    {
        kInvalid = 0U,
        kUSD = 1U,
        kINR = 2U,
        kEURO = 3U
    };

    /// @brief Xchange Rate for USD to INR
    static constexpr double XchangeRateUSDToINR() { return 60.0; }

    /// @brief Convert USD to INR
    static constexpr double ConvertUSDToINR(const double usd) { return usd * XchangeRateUSDToINR(); }

    /// @brief Convert INR to USD
    static constexpr double ConvertINRToUSD(const double inr) { return inr / XchangeRateUSDToINR(); }

    /// @brief Xchange Rate for EURO to INR
    static constexpr double XchangeRateEUROToINR() { return 79.0; }

    /// @brief Convert EURO to INR
    static constexpr double ConvertEUROToINR(const double euro) { return euro * XchangeRateEUROToINR(); }

    /// @brief Convert EURO to INR
    static constexpr double ConvertINRToEURO(const double inr) { return inr / XchangeRateEUROToINR(); }

    /// @brief Fare (USD, Euro or INR) for flight
    double total_fare;

    /// @brief Fare Currency
    Currency currency_type;
};

/// @brief Trip Information
struct TripInfo
{
    /// @brief Flight Information
    FlightInfo flight;

    /// @brief Trip Origin Airport Information
    AirportInfo origin;

    /// @brief Trip destination Airport Information
    AirportInfo destination;

    /// @brief Trip fare
    Fare fare;
};
}  // namespace fms

#endif  /// FLIGHT_MANAGEMENT_TRIP_INFO_H_