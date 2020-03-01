///
/// @file app_main.cpp
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#include "flight_management/flight_trip_database.h"
#include "flight_management/i_flight_trip_database.h"

#include <iostream>
#include <memory>

int main(int argc, char** argv)
{
    std::unique_ptr<fms::IFlightTripDatabase> flight_trip_database = std::make_unique<fms::FlightTripDatabase>();

    flight_trip_database->AddTrip("AI-854", "AirIndia", "Pune", "Delhi", 5000);
    flight_trip_database->AddTrip("6E-702", "Indigo", "Pune", "Bengaluru", 3000);
    flight_trip_database->AddTrip("6E-302", "Indigo", "Mumbai", "Bengaluru", 3230);
    flight_trip_database->AddTrip("SJ-512", "SpiceJet", "Bengaluru", "Ahmedabad", 5000);
    flight_trip_database->DisplayAllTrips();

    flight_trip_database->RemoveTrip("SG-512");
    flight_trip_database->DisplayAllTrips();

    flight_trip_database->UpdateFareByTrip("6E-702", 5000);
    flight_trip_database->DisplayAllTrips();

    std::cout << "Found flights with number (6E-302): " << std::endl
              << flight_trip_database->FindFlightByNumber("6E-302") << std::endl
              << std::endl;

    std::cout << "Found flights with origin city (Pune): " << std::endl
              << flight_trip_database->FindFlightsByOriginCity("Pune") << std::endl
              << std::endl;

    std::cout << "Found average cost for all trips: " << flight_trip_database->FindAverageCostOfAllTrips() << std::endl
              << std::endl;

    std::cout << "Found minimum fare between Pune->Bengaluru: "
              << flight_trip_database->FindMinFareBetweenCities("Pune", "Bengaluru") << std::endl
              << std::endl;

    std::cout << "Found max fare from Indigo:  " << flight_trip_database->FindMaxFareByOperator("Indigo") << std::endl
              << std::endl;

    flight_trip_database->UpdateFareByOperator("AirIndia", 4500);
    flight_trip_database->DisplayAllTrips();

    return 0;
}