#include "../includes/Flight_map.hpp"
#include <catch2/catch_test_macros.hpp>

#include <fstream>
using namespace std;
Flight_map* flight = new Flight_map("../Data/airports.dat", "../Data/routes.dat", "../Data/airlines.dat");
TEST_CASE("data") {
    cout<<"Data example: "<<endl;
    flight->get_Data()->printAirports(1120,1124);
    flight->get_Data()->printRoutes(1120,1124);

}
TEST_CASE("BFS itself") {
    vector<int> result = flight->findPath(3830,3830);
    vector<int> toCompare = {3830};
    REQUIRE(result == toCompare);
}

TEST_CASE("BFS out of data") {
    vector<int> result = flight->findPath(14900,20000);
    vector<int> toCompare;
    REQUIRE(result == toCompare);
}

TEST_CASE("BFS successfully") {
     
    vector<int> result = flight->findPath(3830,4042);
    vector<int> toCompare;
    ifstream TheText("../tests/BFS_Sucess.txt");
    string word;
    if (TheText.is_open()) {
        while (getline(TheText, word)) {
            toCompare.push_back(stoi(word));
        }
    }
    REQUIRE(result == toCompare);
}

TEST_CASE("Full BFS successfully1") {
     
    vector<int> result = flight->BFS(3830);
    vector<int> toCompare;
    ifstream TheText("../tests/Full_BFS_Sucess1.txt");
    string word;
    if (TheText.is_open()) {
        while (getline(TheText, word)) {
            toCompare.push_back(stoi(word));
        }
    }
    REQUIRE(result == toCompare);
}

TEST_CASE("Full BFS successfully2") {
     
    vector<int> result = flight->BFS(6740);
    vector<int> toCompare;
    ifstream TheText("../tests/Full_BFS_Sucess2.txt");
    string word;
    if (TheText.is_open()) {
        while (getline(TheText, word)) {
            toCompare.push_back(stoi(word));
        }
    }
    REQUIRE(result == toCompare);
}

TEST_CASE("Full BFS can't find a path") {
    vector<int> result = flight->BFS(4540);
    vector<int> toCompare;
    toCompare.push_back(4540);
    for(auto i: result){
        cout<<i<<endl;
    }
    cout<<"No more path"<<endl;
    REQUIRE(result == toCompare);
}

TEST_CASE("Full BFS out of data") {
     
    vector<int> result = flight->BFS(20000);
    vector<int> toCompare;
    REQUIRE(result == toCompare);
}

// PageRank
TEST_CASE("test_matrix_multiply_small") {
    unordered_map<int, unordered_map<int, double>> A;
    A = {
        {0, {{0, 0.0}, {1, 1.0/2}, {2, 1.0/2}, {3, 0.0}}},
        {1, {{0, 0.0}, {1, 0.0}, {2, 0.0}, {3, 1.0}}},
        {2, {{0, 1.0/3}, {1, 1.0/3}, {2, 0}, {3, 1.0/3}}},
        {3, {{0, 0.0}, {1, 0.0}, {2, 1.0}, {3, 0.0}}}};
    
    unordered_map<int, double> x = {{0, 1.0/4}, {1, 1.0/4}, {2, 1.0/4}, {3, 1.0/4}};
    unordered_map<int, double> result1 = {{0, 1.0/12}, {1, 2.5/12}, {2, 4.5/12}, {3, 4.0/12}};
    unordered_map<int, double> result2 = {{0, 1.5/12}, {1, 2.0/12}, {2, 4.5/12}, {3, 4.0/12}};
    unordered_map<int, double> x1 = flight->matrix_multiply(A, x);
    unordered_map<int, double> x2 = flight->matrix_multiply(A, x1);

    for (int i = 0; i < 4; i++) {
        REQUIRE(flight->double_compare(result1[i], x1[i]));
    }
    for (int i = 0; i < 4; i++) {
        REQUIRE(flight->double_compare(result2[i], x2[i]));
    }
}

TEST_CASE("invalid input 1: same start and end") {
cout<<"<----------------------------------------------------------->"<<endl;

cout<<"The Following test is relate to Dijstras:"<<endl;
    cout<<"Invalid Test:"<<endl;
    auto answer=flight->Dijstras(3384,3384);
    REQUIRE(answer.empty());
    cout<<"invalid from Airport: 3384 to 3384"<<endl;
cout <<"<----------------------------------------------------------->"<<endl;
}

TEST_CASE("invalid input 2: Wrong ID") {
    auto answer=flight->Dijstras(3384,9999);
    REQUIRE(answer.empty());
    cout<<"invalid from Airport: 3384 to 9999"<<endl;
cout <<"<----------------------------------------------------------->"<<endl;

}

TEST_CASE("invalid input 2: ID with /N") {
    auto answer=flight->Dijstras(3384,2223);
    REQUIRE(answer.empty());
    cout<<"invalid from Airport: 3384 to 2223"<<endl;
cout <<"<----------------------------------------------------------->"<<endl;

}

TEST_CASE("valid output 1: Nanchang to Champagin") {
    cout<<"Valid Test: "<<endl;
    auto answer=flight->Dijstras(3384,4049);
    cout<<"The shortest path from Nanchang to Champagin will be:"<<endl;
    for(size_t i=0;i<answer.size();i++){
        auto* location=flight->get_Data()->searchAirports(answer[i]);
        cout<<location->country<<": ";
        cout<<location->name<<""<<endl;
    }
cout <<"<----------------------------------------------------------->"<<endl;

}

TEST_CASE("valid output 2: ORD to CMI") {
    auto answer=flight->Dijstras(3830,4049);
    vector<int> should={4049};
    cout<<"The shortest path from Chicago to Champagin will be:"<<endl;
    double sum=0;
    for(size_t i=0;i<answer.size();i++){
        auto* location=flight->get_Data()->searchAirports(answer[i]);
        cout<<location->country<<": ";
        cout<<location->name<<""<<endl;
    }
cout <<"<----------------------------------------------------------->"<<endl;
}

TEST_CASE("valid output 3: PEK to CMI") {
    auto answer=flight->Dijstras(3364,4049);
    vector<int> should={4049};
    cout<<"The shortest path from Peking to Champagin will be:"<<endl;
    double sum=0;
    for(size_t i=0;i<answer.size();i++){
        auto* location=flight->get_Data()->searchAirports(answer[i]);
        cout<<location->country<<": ";
        cout<<location->name<<""<<endl;
    }
cout <<"<----------------------------------------------------------->"<<endl;
}

