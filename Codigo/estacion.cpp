#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include "estacion.h"


string genCodigo(string codigo){
    int codInt = stoi(codigo);
    codIn++;
    ostringstream oss;
    oss << setw(codigo.size())<<setfill('0')<<codInt;
    return oss.str();
}

estacion(string n_nombre, string n_codigo, string n_region, string n_coordenadas, string n_gerente, int n_precioR, int n_precioP, int n_precioE){
    nombre = n_nombre;
    codigo = n_codigo;
    region = n_region;
    coordenadas = n_coordenadas;
    gerente = n_gerente;

    precioR = n_precioR;
    precioP = n_precioP;
    precioE = n_precioE;

    surtidores = new surtidor[cantSurtidores];

    string SCodigo = genCodigo(codigo);
    for (int i = 0; i<cantSurtidores;i++){
        surtidores[i] = surtidor(SCodigo,"Modelo-X",tanqueCentral,precioR,precioP,precioE);
        SCodigo = genCodigo(SCodigo);
    }
}

void agregarSurtidor(surtidor A, int& cap){

    int nuevacap = cap+1;
    surtidor* newSurtidores = new surtidor [nuevacap];
    for (int i = 0; i<cap;i++){
        newSurtidores[i] = surtidores[i];
    }
    newSurtidores[nuevacap-1] = A;

    delete[] surtidores;
    surtidores = newSurtidores;
    cap = nuevacap;
}

void eliminarSurtidor(string codigo, int&cap){
    int nuevacap = cap-1;
    surtidor* newSurtidores = new surtidor [nuevacap];
    int index = 0;
    for (int i = 0; i < cap; i++){
        if (surtidores[i].getCodigo() != codigo ){
            newSurtidores[index] = surtidores[i];
            index++;
        }
    }
    delete[] surtidores;
    surtidores = newSurtidores;
    cap = nuevacap;

}
void activarSurtidor(string codigo){
    for (int i=0; i < cantSurtidores;i++){
        if (surtidores[i].getCodigo() == codigo){
            surtidores[i].setEstado(true);
        }
    }
}

void desactivarSurtidor(string codigo){
    for (int i = 0; i< cantSurtidores;i++){
        if (surtidores[i].getCodigo() == codigo){
            surtidores[i].setEstado(false);
        }
    }
}

/*
string getRegion(){
    return region;
}

int getCapRegular(){
    return regular[0];
}
int getCapPremium(){
    return premium[0];
}
int getCapEco(){
    return eco[0];
}
int getPrecioRegular(){
    return regular[1];
}
int getPrecioPremium(){
    return premium[1];
}
int getPrecioEco(){
    return eco[1];
}
*/

