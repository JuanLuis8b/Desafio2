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

        int cantSurtidores;
        bool primerSurtidor;
        string ultimoCodigo;

        tanque tanqueCentral;

        int* precioR;
        int* precioP;
        int* precioE;

        surtidor* surtidores;

    public:

        estacion();
        estacion(string n_nombre, string n_codigo, string n_region, string n_coordenadas, string n_gerente, int *n_precioR, int *n_precioP, int *n_precioE,int n_cantS=1);

        string getNombre();
        string getCodigo();
        string getRegion();
        string getCoordenadas();
        string getGerente();
        int getCantSurtidores();
        bool getPrimerSurtidor();
        int** getPrecioR();
        int** getPrecioP();
        int** getPrecioE();
        string getUltimoCodigo();

        surtidor* getSurtidores();
        tanque* getTanque();

        void setNombre();
        void setCodigo(string codigo);
        void setRegion();
        void setCoordenadas();
        void setGerente();
        void setPrimerSurtidor(bool valor);
        void setUltimoCodigo(string codigo);

        void agregarSurtidor();
        void eliminarSurtidor(string codigo);
        void activarDesactivarSurtidor(string codigo);
        void consultarHistorico(string nomArchivo);
        void reporteLitros(string nomArchivo);
        void verificarFugas(string nomArchivo);
        void simularVenta(string nomArchivo);

};

#endif // ESTACION_H
