#include "Transform.hpp"

#include <vector>
#include <unordered_map>

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
    Routes* getEdge(int source_id, int des_id);

    map<int,map<int,Routes*>> getAllRoutes();
    
    //BFS
    vector<int> BFS(int startID);
    vector<int> findPath(int startID, int destinationID);
    
    //Dijkstra's
    vector<int> Dijstras(int start,int end);
    Transform* get_Data(){return all_data;};
    
    // PageRank
    unordered_map<int, double> PageRank(int max_iter);

    // PageRank helper
    unordered_map<int, double> matrix_multiply(const unordered_map<int, unordered_map<int, double>>& A, const unordered_map<int, double>& x);
    bool double_compare(double double1, double double2);
    void write_to_file(string filename, const unordered_map<int, double>& airport_rank);
    
    private:
    Transform* all_data;                    // initial database 
    map<int,map<int,Routes*>> all_routes;   // first int corresponding to origin id, second int corresponding to destination 
};
