#include <fstream>
#include "../includes/Transform.hpp"
#include "math.h"

using namespace std;
//////helper///////

double Transform::distance(double lat1, double long1,
                    double lat2, double long2){
    double R = 6371;
    lat1 = lat1*M_PI/180;
    long1 = long1*M_PI/180;
    lat2 = lat2*M_PI/180;
    long2 = long2*M_PI/180;
     
    // Haversine Formula
    double dlong = long2 - long1;
    double dlat = lat2 - lat1;
 
    double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
    ans = 2 * asin(sqrt(ans));
 
    return ans * R;
}

vector<std::string> Transform::Split(string str,char determine) {
  size_t last = 0;
  vector<std::string> substrs;
  int special=1;
  for (size_t i = 0; i != str.length(); ++i) {
    if(str[i]=='"'){
        special *=-1;
    }
    if (str.at(i) == determine && special==1) {
      string substr = str.substr(last, i - last);
      last = i + 1;
      if(substr[0]=='"'){
        substr=substr.substr(1,substr.length()-2);
      }
      substrs.push_back(substr);
    }
  }
  std::string substr = str.substr(last, str.length() - last);
  substrs.push_back(substr);
  return substrs;
}

bool Transform::isDouble(string deter){
    try{
        stod(deter);
    }catch(invalid_argument){
        return false;
    }
    return true;
}

void Transform::printAirports(int begin,int end){
    int count=0;
     for(auto i : airports_vertices){
        if(count>=begin){
            cout<<"new Airports:--------------"<<endl;
            cout<<"ID:" <<i->ID<<endl;
            cout<<"name:" <<i->name<<endl;
            cout<<"city: "<< i->city<<endl;
            cout<<"country: "<<i->country<<endl;
            cout<<"IATA: "<<i->IATA<<endl;
            cout<<"location: ("<<i->location.first<<","<<i->location.second<<")"<<endl;
        }
        if(count==end){
            break;
        }
        count++;
    }

}

void Transform::printAirlins(int begin,int end){
    int count=0;
     for(auto i : airlines){
        if(count>=begin){
            cout<<"new Airline:--------------"<<endl;
            cout<<"ID:" <<i->ID<<endl;
            cout<<"Name:" <<i->name<<endl;
            cout<<"Active: "<< i->active<<endl;
        }
        if(count==end){
            break;
        }
        count++;
    }

}

void Transform::printRoutes(int begin,int end){ 
    int count=0;
     for(auto i : routes){
        if(count>=begin){
            cout<<"route:--------------"<<endl;
            cout<<"origin:" <<i->source_IATA<<endl;
            cout<<"end:" <<i->destination_IATA<<endl;
            cout<<"distance: "<< i->distance<<endl;
        }
        if(count==end){
            break;
        }
        count++;
    }
}

//////make 1,1,1,1,1,1, to [1][1][1][1][1]

Transform::Transform(string Airports, string Routes, string Airlines){
    InsertRoutes(Routes);
    InsertAirports(Airports);
    InsertAirlines(Airlines);
}

void Transform::InsertAirports(string filename){
    ifstream AirportsFile(filename);
    string word;
    vector<string> temp;
    // int count=0;
    if (AirportsFile.is_open()) {
        while (getline(AirportsFile, word)) {
            temp = Split(word,',');
            vector<string> deter = {temp[0],temp[1],temp[2],temp[3],temp[4],temp[6],temp[7]};
            // bool add=true; should not be test because some airports name is not english but still valid construct invalid data after talk
            // for(auto i: deter){
            //     if(isDouble(i)) continue;
            //     for(auto j:i){
            //         if(!isalpha(j)&&j!=' '&&j!='/'&&j!=','){
            //             add=false;
            //             break;
            //         };
            //     }  
            //     if(!add){
            //         break;
            //     }
            // }
            // if(!add) continue;

            // verify if data with \N
            bool flag = false;
            for (auto& d : deter) {
                if (d == "\\N") {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }

            Airports* airport = new Airports();
            airport->ID = stoi(temp[0]);
            airport->name = temp[1];
            airport->city = temp[2];
            airport->country = temp[3];
            airport->IATA = temp[4];
            airport->location = pair<double,double>(stod(temp[6]),stod(temp[7]));
            airports_vertices.push_back(airport);
        }   
    }
}

void Transform::InsertAirlines(string filename){
    ifstream AirlinesFile(filename);
    string word;
    vector<string> temp;
    // int count=0;
    if (AirlinesFile.is_open()) {
        while (getline(AirlinesFile, word)) {
            temp = Split(word,',');

            Airlines* airline = new Airlines();
            if (stoi(temp[0]) > 0) {
                // verify if data with \N
                if (temp[0] == "\\N" || temp[1] == "\\N" || temp[7] == "\\N") {
                    continue;
                }
                airline->ID = stoi(temp[0]);
                airline->name = temp[1];
                airline->active =  temp[7];
                airlines.push_back(airline);
            }
        }   
    }
}

void Transform::InsertRoutes(string filename){
    ifstream RoutesFile(filename);
    string line;
    vector<string> temp;
    if (RoutesFile.is_open()) {
        while (getline(RoutesFile, line)) {
            temp = Split(line,',');
            
            // verify if data with \N
            bool flag = false;
            for (unsigned int i = 0; i < 6; i++) {
                if (temp[i] == "\\N") {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            
            Routes* route = new Routes();
            route->airline = temp[0];
            route->airline_ID = stoi(temp[1]);
            route->source_IATA = temp[2];
            route->source_ID = stoi(temp[3]);
            route->destination_IATA = temp[4];
            route->destination_ID = stoi(temp[5]);
            Airports* origin;
            Airports* end;
            for(auto i:airports_vertices){
                if(i->ID==route->source_ID){
                    origin=i;
                }
                if(i->ID==route->destination_ID){
                    end=i;
                }
                if(origin&&end){
                    route->distance=distance(origin->location.first,origin->location.second,end->location.first,end->location.second);
                    break;
                }
            }
            routes.push_back(route);
        }   
    }
}