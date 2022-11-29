#include "../includes/Flight_map.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("data") {
    Transform data;
    data.InsertAirports("../Data/airports.dat");
    data.InsertAirlines("../Data/airlines.dat");
    // data.InsertRoutes("../Data/routes.dat");
    data.printAirports(100,110);
    data.printAirlins(0,10);
    // data.printRoutes(10,20);

}