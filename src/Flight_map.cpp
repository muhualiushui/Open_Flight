#include "../includes/Flight_map.hpp"

#include <queue>

using namespace std;

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

vector<int>  Flight_map::findPath(int startID, int destinationID) {
    vector<int> output;
    //mark all the vertex not visited
    vector<bool> visited(14111, false);
    queue<int> queue;
    queue.push(startID);
    visited[startID] = true;
    int currID = startID;

    while (!queue.empty()) {
        currID = queue.front();

        //if now is the destination, push it to the vector
        if (currID == destinationID) {
            output.push_back(currID);
            break;
        }
        output.push_back(currID);

        //push all the adjcent of curr to queue and mark visited
        for (auto a : all_routes[currID]) {
            if (visited[a.first] == false) {
                queue.push(a.first);
                visited[a.first] = true;
            }
        }
        queue.pop();
    }

    //not found
    if (currID != destinationID) {
        return vector<int> ();
    }

    return output;
}


