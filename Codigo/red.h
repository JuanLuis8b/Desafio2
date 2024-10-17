#include <iostream>

#include "estacion.h"

#ifndef red_h
#define red_h

class red {
    private:

        int precioRNorte;
        int precioRCentro;
        int precioRSur;

        int precioPNorte;
        int precioPCentro;
        int precioPSur;

        int precioENorte;
        int precioECentro;
        int precioESur;

        int capacidad;
        estacion* estaciones;

        bool primeraEstacion;
        string ultimocodigo;

    public:

        red();

        int getCapacidad();
        estacion* getEstaciones();

        bool getPrimeraEstacion();

        void setPrecioRNorte(int precio);
        void setPrecioRCentro(int precio);
        void setPrecioRSur(int precio);

        void setPrecioPNorte(int precio);
        void setPrecioPCentro(int precio);
        void setPrecioPSur(int precio);

        void setPrecioENorte(int precio);
        void setPrecioECentro(int precio);
        void setPrecioESur(int precio);

        void setCapacidad(int valor);
        void setUltimoCodigo(string codigo);
        void setPrimeraEstacion(bool valor);


        void agregarEstacion ();
        void agregarEstacion (estacion& miEstacion);
        void eliminarEstacion(string codigo);

        void reporteVentas(string nomArchivo);

        int* getPrecioRNorte();
        int* getPrecioRCentro();
        int* getPrecioRSur();
        int* getPrecioPNorte();
        int* getPrecioPCentro();
        int* getPrecioPSur();
        int* getPrecioENorte();
        int* getPrecioECentro();
        int* getPrecioESur();
};

#endif // RED_H
