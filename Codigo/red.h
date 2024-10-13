#include <iostream>

#include "estacion.h"

#ifndef red_h
#define red_h

class red {
    private:
        int capacidad=1;
        estacion* estaciones;

    public:
        red();
        void agregarEstacion (estacion A);

        void eliminarEstacion(string codigo);
};

#endif // RED_H
