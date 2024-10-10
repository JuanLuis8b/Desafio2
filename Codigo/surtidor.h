#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "estacion.h"

using namespace std;

#ifndef surtidor_h
#define surtidor_h

string getFecha();
void registrarVenta(string info, string archivo);

class surtidor {

    private:
        string codigo;
        string modelo;
        bool estado;

    public:

        surtidor(string cod, string mod, tanque tan, bool status);

        string calcularPrecio(string cantidad);

        string vender();


};

#endif // SURTIDOR_H
