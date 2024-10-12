#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "estacion.h"
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
        surtidor(string codigo, string modelo, tanque& tanqueCentral, int& precioR, int& precioP, int& precioE);

        string getCodigo();
        bool getEstado();
        int getPrecioR();
        int getPrecioP();
        int getPrecioE();

        void setModelo(string nuevoModelo);
        void setEstado(bool nuevoEstado);



        /*void setCodigo();
         * void setModelo();
         * string getCodigo();
         * string getModelo();
         */
};

#endif // SURTIDOR_H

/*
surtidor(string cod, string mod, bool status);

        string getCodigo();
        void setCodigo();
        string getModelo();
        void setModelo();

        string calcularPrecio(string tipo,string cantidad);

        string vender();
*/
