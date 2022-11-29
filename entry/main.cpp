#include "../src/Transform.cpp"
#include "../includes/Flight_map.hpp"
int main() {
    // Transform data;
    // data.InsertAirports("../Data/airports.dat");
    // data.InsertAirlines("../Data/airlines.dat");
    // data.InsertRoutes("../Data/routes.dat");

    // data.printAirports(100, 110);
    // data.printAirlins(0, 10);
    // data.printRoutes(0, 10);
    Flight_map *map = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    vector<int> result = map->findPath(3830,5726);
    for(auto i:result){
        cout<<i<<endl;
    }
    return 0;
}
