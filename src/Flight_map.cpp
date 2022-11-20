#include "../includes/Flight_map.hpp"

void Flight_map::construct_map(){
    auto airports=all_data->getVertices();
    for(auto port:airports){
        all_routes[port->ID]=vector<Routes*>();
    }
    for(auto route:all_data->getRoutes()){
        all_routes[route->source_ID].push_back(route);
    }
}
Flight_map::Flight_map(string Airports, string Routes, string Airlines){
    all_data=new Transform(Airlines,Routes,Airlines);
    construct_map();
}

