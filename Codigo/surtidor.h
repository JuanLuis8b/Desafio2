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

        tanque& tanqueCentral;

        int& precioR;
        int& precioP;
        int& precioE;

    public:

        surtidor();
        surtidor(string codigo, string modelo, tanque& tanqueCentral, int precioR, int precioP, int precioE);

        string getCodigo();
        bool getEstado();
        int getPrecioR();
        int getPrecioP();
        int getPrecioE();

        void setModelo(string nuevoModelo);
        void setEstado(bool nuevoEstado);
};

#endif // SURTIDOR_H
