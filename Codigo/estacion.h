#include <iostream>
#include <string>

#include "surtidor.h"

using namespace std;


#ifndef estacion_h
#define estacion_h

class estacion {

    private:

        string codigo;
        string region;
        string coordenadas;
        string gerente;

        int regular[2];
        int premium[2];
        int eco[2];

        surtidor surtidores = new surtidor[3];

    public:

        estacion(string cod, string reg, string ger, string coo);

        string getRegion();
        int getCapRegular();
        int getCapPremium();
        int getCapEco();
        int getPrecioRegular();
        int getPrecioPremium();
        int getPrecioEco();
};

#endif // ESTACION_H
