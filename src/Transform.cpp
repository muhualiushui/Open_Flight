#include <fstream>
#include "../includes/Transform.h"

//////helper///////
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
void Transform::print(int begin,int end){
    int count=begin;
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
//////make 1,1,1,1,1,1, to [1][1][1][1][1]


Transform::Transform(string Airports, string Routes, string Airlines){
    InsertRoutes(Routes);
    InsertAirports(Airports);
    InsertAirlines(Airlines);
}
void Transform::InsertRoutes(string filename){

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
void Transform::InsertAirlines(string filenname){

}