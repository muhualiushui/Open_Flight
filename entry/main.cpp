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
    Flight_map* flight = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
    // vector<int> result = map->findPath(3830,5726);
    // for(auto i:result){
    //     cout<<i<<endl;
    // }


    // Page Rank test
    map<int,map<int,Database::Routes*>> routes = flight->getAllRoutes();
    int c = 0;
    // for (auto r : routes) {
        // cout << "start : " << r.first << endl;
        // for (auto m : r.second) {
        //     cout << "end : " << m.first << endl;
        //     cout << "route : " << m.second->airline << endl;
        // }
        // c++;
        // if (c == 5) {
        //     bsreak;
        // }
        // break;

        // if (r.second.size() == 0) {
        //     cout << "dead start : " << r.first << endl;
        // }
    // }
    // CG,1308,GKA,1,POM,5,,0,DH8
    // PX,328,GKA,1,POM,5,,0,DH4 DH8 DH3

    std::cout << "beginning pagerank" << std::endl;

    // std::unordered_map<int, double> m = flight->PageRank(30);
    // for (auto& i : m) {
    //     cout << "airport" << i.first << endl;
    //     cout << "rank" << i.second << endl;
    //     // c++;
    //     // if (c == 100) {
    //     //     break;
    //     // }
    // }
    // flight->write_to_file("../Output/PageRank_output.txt", m);

    // cout << "airport 1 rank: " << endl;
    // cout << m[1] << endl;

    // Flight_map* pg_flight = new Flight_map("../Data/PageRank_test_airports.dat", "../Data/PageRank_test_routes.dat", "../Data/PageRank_test_airlines.dat");
    // std::unordered_map<int, double> m = pg_flight->PageRank(3);
    // for (auto& i : m) {
    //     cout << "airport :" << i.first << endl;
    //     cout << "rank :" << i.second << endl;
    // }

    return 0;
}
