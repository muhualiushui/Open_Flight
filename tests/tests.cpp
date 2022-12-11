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

TEST_CASE("Full BFS successfully1") {
    Flight_map *map = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    vector<int> result = map->BFS(3830);
    vector<int> toCompare;
    ifstream TheText("../tests/Full_BFS_Sucess1.txt");
    string word;
    if (TheText.is_open()) {
        while (getline(TheText, word)) {
            toCompare.push_back(stoi(word));
        }
    }
    REQUIRE(result == toCompare);
}

TEST_CASE("Full BFS successfully2") {
    Flight_map *map = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    vector<int> result = map->BFS(6740);
    vector<int> toCompare;
    ifstream TheText("../tests/Full_BFS_Sucess2.txt");
    string word;
    if (TheText.is_open()) {
        while (getline(TheText, word)) {
            toCompare.push_back(stoi(word));
        }
    }
    REQUIRE(result == toCompare);
}

TEST_CASE("Full BFS can't find a path") {
    Flight_map *map = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    vector<int> result = map->BFS(4540);
    vector<int> toCompare;
    toCompare.push_back(4540);
    REQUIRE(result == toCompare);
}

TEST_CASE("Full BFS out of data") {
    Flight_map *map = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    vector<int> result = map->BFS(20000);
    vector<int> toCompare;
    REQUIRE(result == toCompare);
}

// PageRank
TEST_CASE("test_matrix_multiply_small") {
    Flight_map* flight = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    unordered_map<int, unordered_map<int, double>> A;
    
    A = {
        {0, {{0, 0.0}, {1, 1.0/2}, {2, 1.0/2}, {3, 0.0}}},
        {1, {{0, 0.0}, {1, 0.0}, {2, 0.0}, {3, 1.0}}},
        {2, {{0, 1.0/3}, {1, 1.0/3}, {2, 0}, {3, 1.0/3}}},
        {3, {{0, 0.0}, {1, 0.0}, {2, 1.0}, {3, 0.0}}}};
    
    unordered_map<int, double> x = {{0, 1.0/4}, {1, 1.0/4}, {2, 1.0/4}, {3, 1.0/4}};
    unordered_map<int, double> result1 = {{0, 1.0/12}, {1, 2.5/12}, {2, 4.5/12}, {3, 4.0/12}};
    unordered_map<int, double> result2 = {{0, 1.5/12}, {1, 2.0/12}, {2, 4.5/12}, {3, 4.0/12}};
    unordered_map<int, double> x1 = flight->matrix_multiply(A, x);
    unordered_map<int, double> x2 = flight->matrix_multiply(A, x1);

    for (int i = 0; i < 4; i++) {
        REQUIRE(flight->double_compare(result1[i], x1[i]));
    }
    for (int i = 0; i < 4; i++) {
        REQUIRE(flight->double_compare(result2[i], x2[i]));
    }
}
