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

        int* precioR;
        int* precioP;
        int* precioE;

        int cantSurtidores = 2;

        surtidor* surtidores;// = new surtidor[cantSurtidores];

    public:

        estacion();
        estacion(string n_nombre, string n_codigo, string n_region, string n_coordenadas, string n_gerente, int *n_precioR, int *n_precioP, int *n_precioE);

        string getNombre();
        string getCodigo();
        string getRegion();
        string getCoordenadas();
        string getGerente();
        int getCantSurtidores();


        void setNombre();
        void setCodigo(string codigo);
        void setRegion();
        void setCoordenadas();
        void setGerente();

        surtidor* getSurtidores();

        //surtidor crearSurtidor();
        void agregarSurtidor();
        void eliminarSurtidor(string codigo);
        void activarDesactivarSurtidor(string codigo);
        //void desactivarSurtidor(string codigo);

        void consultarHistorico(string nomArchivo);
        void reporteLitros(string nomArchivo);
        void verificarFugas(string nomArchivo);
        void simularVenta(string nomArchivo);

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
