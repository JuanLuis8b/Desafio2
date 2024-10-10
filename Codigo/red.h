#include <iostream>

#include "estacion.h"

#ifndef red_h
#define red_h

class red {
    private:
        int capacidad = 6;
        estacion grupo = new estacion [6];
    public:
        red();
        void agregarEstacion (estacion A){
            //agregar estacion;
        }
        void eliminarEstacion(estacion A){
            //eliminar estacion;
        }

        void fijarPrecios(int NR, int NP, int NE, int CR, int CP, int CE, int SR, int SP, int SE){

            for (int i = 0; i < capacidad; i++){
                if (grupo[i].getRegion == "Norte"){
                    grupo[i].getRegular[1] = NR;
                    grupo[i].getPremium[1] = NP;
                }
            }
        }


};

#endif // RED_H
