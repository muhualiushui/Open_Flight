#include "../includes/Transform.h"

int main(){
    Transform data;
    data.InsertAirports("../Data/airports.dat");
    data.print(100,110);
    return 0;
}