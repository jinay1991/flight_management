///
/// @file main.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/trip_builder.h"

int main(int argc, char** argv)
{
    fms::FlightDatabase flight_database;

    flight_database.AddTrip("AI-854", "Pune", "Delhi", 5000);
    flight_database.RemoveTrip("SG-512");
    flight_database.UpdateFareByTrip("6E-702", 5000);
    flight_database.DisplayAllTrips();
    flight_database.FindFlightByNumber("6E-302");
    flight_database.FindFlightsByOriginCity("Pune");
    flight_database.FindAverageCostOfAllTrips();
    flight_database.FindMinFareBetweenCities("Pune", "Bengaluru");
    flight_database.FindMaxFareByOperator("Indigo");
    flight_database.UpdateFareByOperator("AirIndia", 4500);

    return 0;
}