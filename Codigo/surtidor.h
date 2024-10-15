#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>

#include "tanque.h"

using namespace std;

#ifndef surtidor_h
#define surtidor_h

//string getFecha();
//void registrarVenta(string info, string archivo);

class surtidor {

    private:

        string codigo;
        string modelo;
        bool estado;

        tanque* tanqueCentral;

        int** precioR;
        int** precioP;
        int** precioE;

    public:

        surtidor();
        surtidor(string n_codigo, string n_modelo, tanque* n_tanqueCentral, int** n_precioR, int** n_precioP, int** n_precioE);

        string getCodigo();
        bool getEstado();
        int getPrecioR();
        int getPrecioP();
        int getPrecioE();

        void setModelo(string nuevoModelo);
        void setEstado(bool nuevoEstado);

        void vender(string nomArchivo);
};

void registrarVenta(string info, string nomArchivo);
#endif // SURTIDOR_H
