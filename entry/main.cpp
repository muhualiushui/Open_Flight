#include "../src/Transform.cpp"
#include "../includes/Flight_map.hpp"

int main() {
    // Sample data
    Transform data;
    data.InsertAirports("../Data/airports.dat");
    data.InsertAirlines("../Data/airlines.dat");
    data.InsertRoutes("../Data/routes.dat");
    data.printAirports(0, 10);
    data.printAirlins(0, 10);
    data.printRoutes(0, 10);

    // BFS find path between two point
    Flight_map* flight = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    vector<int> result = flight->findPath(3830,4042);
    for (auto i : result) {
        cout << i << endl;
    }

    // Page Rank
    cout << "beginning pagerank" << endl;
    // Full airports data
    // unordered_map<int, double> m = flight->PageRank(3);
    // for (auto& i : m) {
    //     cout << "airport :" << i.first << endl;
    //     cout << "rank :" << i.second << endl;
    // }
    // flight->write_to_file("../Output/PageRank_output.txt", m);

    // Small part of airports
    Flight_map* pg_flight = new Flight_map("../Data/PageRank_test_airports.dat", "../Data/PageRank_test_routes.dat", "../Data/PageRank_test_airlines.dat");
    unordered_map<int, double> m = pg_flight->PageRank(3);
    for (auto& i : m) {
        cout << "airport :" << i.first << endl;
        cout << "rank :" << i.second << endl;
    }

    // Dijkstra's shortest path
    auto answer = flight->Dijstras(3384,4049);
    cout<<"The shortest path from Nanchang to Champagin will be:"<<endl;
    for (size_t i=0; i<answer.size(); i++) {
        auto* location = flight->get_Data()->searchAirports(answer[i]);
        cout<<location->country<<": ";
        cout<<location->name<<""<<endl;
    }
    return 0;
}
