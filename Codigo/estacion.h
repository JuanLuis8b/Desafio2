#include <iostream>
#include <string>

#include "surtidor.h"
#include "tanque.h"

using namespace std;


#ifndef estacion_h
#define estacion_h

class estacion {

    private:

        string nombre;
        string codigo;
        string region;
        string coordenadas;
        string gerente;

        tanque tanqueCentral;

        int precioR;
        int precioP;
        int precioE;

        int cantSurtidores = 2;

        surtidor* surtidores;// = new surtidor[cantSurtidores];

    public:

        estacion(string nombre, string codigo, string region, string coordenadas, string gerente);

        string getNombre();
        string getCodigo();
        string getRegion();
        string getCoordenadas();
        string getGerente();

        void setNombre();
        void setCodigo();
        void setRegion();
        void setCoordenadas();
        void setGerente();

        void agregarSurtidor(surtidor A);
        void eliminarSurtidor(surtidor A);
        void activarSurtidor(string codigo);
        void desactivarSurtidor(string codigo);

};

#endif // ESTACION_H

/*
estacion(string cod, string reg, string ger, string coo);

        string getRegion();
        int getCapRegular();
        int getCapPremium();
        int getCapEco();
        int getPrecioRegular();
        int getPrecioPremium();
        int getPrecioEco();
*/
