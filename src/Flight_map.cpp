#include "../includes/Flight_map.hpp"

void Flight_map::construct_map(){
    auto airports=all_data->getVertices();
    for(auto port:airports){
        all_routes[port->ID]=map<int,Routes*>();
    }
    for(auto route:all_data->getRoutes()){
        all_routes[route->source_ID][route->destination_ID]=route;
    }
}

Flight_map::Flight_map(string Airports, string Routes, string Airlines){
    all_data=new Transform(Airlines,Routes,Airlines);
    construct_map();
}

Database::Routes* Flight_map::getEdge(int source_id, int des_id){
    if(all_routes.find(source_id)!=all_routes.end()){
        return all_routes[source_id][des_id];
    }
    return nullptr;
}


