#include <random>
#include "estacion.h"

using namespace std;

int randomCap(){
    random_device x;
    uniform_int_distribution<> distrib(100,200);
    return distrib(x);
}

estacion(string cod, string reg, string ger, string coo){

    codigo = cod;
    region = reg;
    gerente = ger;
    coordenadas = coo;

    regular[0] = randomCap();
    premium[0] = randomCap();
    eco[0] = randomCap();

}

string getRegion(){
    return region;
}

int getCapRegular(){
    return regular[0];
}
int getCapPremium(){
    return premium[0];
}
int getCapEco(){
    return eco[0];
}
int getPrecioRegular(){
    return regular[1];
}
int getPrecioPremium(){
    return premium[1];
}
int getPrecioEco(){
    return eco[1];
}

