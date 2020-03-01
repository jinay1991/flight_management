///
/// @file app_main.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/flight_trip_database.h"
#include "flight_management/i_flight_trip_database.h"

int main(int argc, char** argv)
{
    std::unique_ptr<fms::IFlightTripDatabase> flight_trip_database = std::make_unique<fms::FlightTripDatabase>();

    flight_trip_database->AddTrip("AI-854", "Pune", "Delhi", 5000);
    flight_trip_database->RemoveTrip("SG-512");
    flight_trip_database->UpdateFareByTrip("6E-702", 5000);
    flight_trip_database->DisplayAllTrips();
    flight_trip_database->FindFlightByNumber("6E-302");
    flight_trip_database->FindFlightsByOriginCity("Pune");
    flight_trip_database->FindAverageCostOfAllTrips();
    flight_trip_database->FindMinFareBetweenCities("Pune", "Bengaluru");
    flight_trip_database->FindMaxFareByOperator("Indigo");
    flight_trip_database->UpdateFareByOperator("AirIndia", 4500);

    return 0;
}