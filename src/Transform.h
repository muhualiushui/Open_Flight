#include "Database.h"
#include <fstream>
#pragma once

class Transform : public Database{
    public:
        Transform(){};
        Transform(string Airports, string Routes, string Airlines);
        void InsertRoutes(string filename);
        void InsertAirports(string filename);
        void InsertAirlines(string filenname);
        vector<Airports*> getVertices(){return airports_vertices;};
        vector<Airlines*> getAirlines(){return airlines;};
        // vector<Routes*> SearchRoute(int airline_ID){return routes_search[airline_ID];};
        // vector<Airlines*> SearchAirlines(pair<int,string>airports){return airports_search[airports];};
//helper:
        vector<std::string> Split(string str,char determine);
        bool isDouble(string deter);
        void printAirports(int begin, int end);
        void printAirlins(int begin, int end);
//
    private:
        vector<Airports*> airports_vertices;
        vector<Airlines*> airlines;
        // map<int,vector<Routes*>> routes_search;//use ID of airlines to checkout all the routes on this airline 
        // map<pair<int,string>,vector<Airlines*>> airports_search;// use ID of Airports to get all the avaliable airline
};
