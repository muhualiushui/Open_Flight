#include "../includes/Flight_map.hpp"
#include "../includes/heaps.hpp"
#include <queue>
#include <stack>

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
    all_data=new Transform(Airports,Routes,Airlines);
    construct_map();
}

Database::Routes* Flight_map::getEdge(int source_id, int des_id){
    if(all_routes.find(source_id)!=all_routes.end()){
        return all_routes[source_id][des_id];
    }
    return nullptr;
}

//BFS
vector<int>  Flight_map::findPath(int startID, int destinationID) {
    if (startID > 14111 || startID < 0 || destinationID > 14111 || startID < 0) {
        cout<<"Please enter right ID"<<endl;
        return vector<int> ();
    }
    vector<int> output;
    //mark all the vertex not visited
    vector<bool> visited(14111, false);
    queue<int> queue;
    queue.push(startID);
    visited[(startID)] = true;
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
            if (visited[(a.first)] == false) {
                queue.push(a.first);
                visited[(a.first)] = true;
            }
        }
        queue.pop();
    }

    // not found
    if (currID != destinationID) {
        return vector<int> ();
    }

    return output;
}

vector<int> Flight_map::Dijstras(int start,int end){
    if(start==end){
        return vector<int>();
    }
    Heap q;
    map<int,int> parent;
    vector<int> answer;
    for(auto i:all_data->getVertices()){
        i->cost=999999;
        parent[i->ID]=-1;
        q.push(i);
    }
    q.change(start,0);
    for(auto count:all_data->getVertices()){
        auto v = q.pop();
        cout<<v->name<<":"<<endl;
        auto neigbors=all_routes[v->ID];
        for(auto neigbor:neigbors){//first: ID of destination; second: route which consisted distance
        double new_cost=neigbor.second->distance+v->cost;
            if(new_cost<all_data->searchAirports(neigbor.first)->cost){
                q.change(neigbor.first,new_cost);
                parent[neigbor.first]=v->ID;
            }
        }
    }
    int route=end;
    stack<int> path;
    while(route!=start){
        path.push(route);
        route=parent[route];
    }
    while(!path.empty()){
        answer.push_back(path.top());
        path.pop();
    }
    return answer;
}



