#include <iostream>
#include <vector>
#include <map>
#pragma once

using namespace std;
//This class use to initial store data which we want and we need to use in the following functions
//each struct corresponding to one of the data shows in Data package
//each struct may not contain all of catalog of data because some we don't need
//see carefully which number corresponding to which type of value

class Database{
    public:
    struct Airports{//this should be present as a vertice
        int ID;
        string name;
        string city;
        string country;
        string IATA;//may be null be careful; example of IATA ORD
        pair<double,double> location;//Latitude,longtitute
    };

    struct Airlines{//this is support 
        int ID;
        string name;
        string active;
    };
    
    struct Routes{
        string airline;
        string airline_ID;//corresponding to the ID in Airlines
        string source_IATA;// example ORD
        int source_ID;//corresponding to ID in Airports
        string destination_IATA;// example ORD
        int destination_ID;//corresponding to ID in Airports
        double distance;
    };
};
