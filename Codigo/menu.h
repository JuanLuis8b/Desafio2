#include "red.h"
#include <iostream>
using namespace std;
#include <string>

#ifndef menu_h
#define menu_h


void fijarPrecios(red& redNacional);
int elegirEstacion(red& nameRed);
string elegirSurtidor(estacion& nameEstacion);
string elegirSurtidor_(estacion& nameEstacion);
void descargarRed(red& miRed, string nomDatos);
void cargarRed(red& miRed,string nomDatos);

#endif // MENU_H
