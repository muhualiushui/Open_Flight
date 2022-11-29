#include "../includes/Flight_map.hpp"
#include <catch2/catch_test_macros.hpp>

#include <fstream>
using namespace std;
TEST_CASE("data") {
    Transform data;
    data.InsertAirports("../Data/airports.dat");
    data.InsertAirlines("../Data/airlines.dat");
    // data.InsertRoutes("../Data/routes.dat");
    data.printAirports(100,110);
    data.printAirlins(0,10);
    // data.printRoutes(10,20);

}

TEST_CASE("BFS itself") {
    Flight_map *map = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    vector<int> result = map->findPath(3830,3830);
    vector<int> toCompare = {3830};
    REQUIRE(result == toCompare);
}

TEST_CASE("BFS out of data") {
    Flight_map *map = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    vector<int> result = map->findPath(14900,20000);
    vector<int> toCompare;
    REQUIRE(result == toCompare);
}

TEST_CASE("BFS successfully") {
    Flight_map *map = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    vector<int> result = map->findPath(3830,4042);
    vector<int> toCompare;
    ifstream TheText("../tests/BFS_Sucess.txt");
    string word;
    if (TheText.is_open()) {
        while (getline(TheText, word)) {
            toCompare.push_back(stoi(word));
        }
    }
    REQUIRE(result == toCompare);
}