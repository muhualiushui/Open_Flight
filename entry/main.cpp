#include "../src/Transform.cpp"

int main(){
    Transform data;
    data.InsertAirports("../Data/airports.dat");
    data.InsertAirlines("../Data/airlines.dat");
    data.printAirports(100,110);
    data.printAirlins(0,10);
    return 0;
}
