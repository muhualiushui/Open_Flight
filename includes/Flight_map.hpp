#include "Transform.hpp"

#include <vector>

/**
 * class purpose:
 * access all useful data from Transform before 
 * the necessary "distance(weight)","source airports(vertice_origin)","destination airports(vertices_end)"
 * all include in the routes
 * 1. if ask get a possible route from vertice 1 to vertice 2:
 *    by using BFS search all routes as method to traversal map "all_routes", not need use weith at here
 * 2. if ask shortest path from vertice 1 to vertice 2;
 *    using Dijkstra’s Algorithm as method and distance as weight to finded out the shortest path
 * 3. I don't know (pageRank) I forget all.
 */

class Flight_map: public Transform{
    public:
    Flight_map(){};
    Flight_map(string Airports, string Routes, string Airlines);
    void construct_map();
    // struct Edge{ which you guys prefer? route or a specific Edge
    //     string origin;
    //     string destination;
    //     double distance;
    // };
    // Edge would require less storage 
    Routes* getEdge(int source_id, int des_id);
    /**
     * To implement BFS
     * Dijkstra’s Algorithm
     * PageRank at here
     */
    
    //BFS
    vector<int> findPath(int startID, int destinationID);
    
    private:
    Transform* all_data;//initial database 
    map<int,map<int,Routes*>> all_routes;// first int corresponding to origin id, second int corresponding to destination 
};
