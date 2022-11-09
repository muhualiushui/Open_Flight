#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include "Database.h"
#include <fstream>

class Transform :public Database{
    public:
    Transform(){};
    Transform(string Airports, string Routes, string Airlines);
    void InsertRoutes(string filename);
    void InsertAirports(string filename);
    void InsertAirlines(string filenname);
    vector<Airports*> getVertices(){return airports_vertices;};
    vector<Routes*> SearchRoute(int airline_ID){return routes_search[airline_ID];};
    vector<Airlines*> SearchAirlines(pair<int,string>airports){return airports_search[airports];};
//helper:
    vector<std::string> Split(string str,char determine);
    bool isDouble(string deter);
    void print(int begin, int end);
//
    private:
    vector<Airports*> airports_vertices;
    map<int,vector<Routes*>> routes_search;//use ID of airlines to checkout all the routes on this airline 
    map<pair<int,string>,vector<Airlines*>> airports_search;// use ID of Airports to get all the avaliable airline
};
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

void Transform::InsertAirports(string filename){
    ifstream AirportsFile(filename);
    string word;
    vector<string> temp;
    // int count=0;
    if (AirportsFile.is_open()) {
        while (getline(AirportsFile, word)) {
            temp=Split(word,',');
            vector<string> deter={temp[0],temp[1],temp[2],temp[3],temp[4],temp[6],temp[7]};
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
            Airports* airport=new Airports();
            airport->ID=stoi(temp[0]);
            airport->name=temp[1];
            airport->city=temp[2];
            airport->country=temp[3];
            airport->IATA=temp[4];
            airport->location=pair<double,double>(stod(temp[6]),stod(temp[7]));
            airports_vertices.push_back(airport);
        }   
    }
}
void Transform::print(int begin,int end){
    int count=0;
     for(auto i :airports_vertices){
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
#pragma once
#endif