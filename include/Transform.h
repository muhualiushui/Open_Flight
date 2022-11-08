#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include "Database.h"

class Transform :public Database{
    public:
    void InsertRoutes(string filename);
    void InsertAirpods(string filename);
    void InsertAirlines(string filenname);
    vector<Airports> getVertices(){return airports_vertices;};
    vector<Routes> SearchRoute(int airline_ID){return routes_search[airline_ID];};
    vector<Airlines> SearchAirlines(pair<int,string>airports){return airports_search[airports];};
    private:
    vector<Airports> airports_vertices;
    map<int,vector<Routes>> routes_search;//use ID of airlines to checkout all the routes on this airline 
    map<pair<int,string>,vector<Airlines>> airports_search;// use ID of Airports to get all the avaliable airline
};

#pragma once
#endif