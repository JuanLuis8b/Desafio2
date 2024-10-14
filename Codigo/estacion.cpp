#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include "estacion.h"
#include "tanque.h"
#include "surtidor.h"


string genCodigo(string codigo){
    int codInt = stoi(codigo);
    codInt++;
    ostringstream oss;
    oss << setw(codigo.size())<<setfill('0')<<codInt;
    return oss.str();
}


estacion::estacion(){
    nombre = "";
    codigo = "";
    region = "";
    coordenadas = "";
    gerente = "";

    precioR = nullptr;
    precioP = nullptr;
    precioE = nullptr;

    surtidores = new surtidor[cantSurtidores];

    string SCodigo = genCodigo(codigo);
    for (int i = 0; i<cantSurtidores;i++){
        surtidores[i] = surtidor(SCodigo,"Modelo-1",&tanqueCentral,&precioR,&precioP,&precioE);
        SCodigo = genCodigo(SCodigo);
    }
}
estacion::estacion(string n_nombre, string n_codigo, string n_region, string n_coordenadas, string n_gerente, int* n_precioR, int* n_precioP, int* n_precioE){
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
        surtidores[i] = surtidor(SCodigo,"Modelo-1",&tanqueCentral,&precioR,&precioP,&precioE);
        SCodigo = genCodigo(SCodigo);
    }
}


surtidor estacion::crearSurtidor(){

    string codigo = surtidores[cantSurtidores-1].getCodigo();
    codigo = genCodigo(codigo);
    cout<<"Ingrese el modelo: ";
    string modelo;
    cin >> modelo;
    surtidor A(codigo,modelo,&tanqueCentral,&precioR,&precioP,&precioE);
    return A;
}

void estacion::agregarSurtidor(surtidor& A){

    if (cantSurtidores == 12){
        cerr<<"Ya se ha alcanzado el maximo de surtidores\n";
        return;
    }

    int nuevacap = cantSurtidores+1;

    surtidor* newSurtidores = new surtidor [nuevacap];
    for (int i = 0; i<cantSurtidores;i++){
        newSurtidores[i] = surtidores[i];
    }
    newSurtidores[nuevacap-1] = A;

    delete[] surtidores;
    surtidores = newSurtidores;
    cantSurtidores = nuevacap;
}

void estacion::eliminarSurtidor(string codigo){
    if (cantSurtidores = 0){
        cerr<<"No hay surtidores para eliminar\n";
        return;
    }
    int nuevacap = cantSurtidores-1;
    surtidor* newSurtidores = new surtidor [nuevacap];
    int index = 0;
    for (int i = 0; i < cantSurtidores; i++){
        if (surtidores[i].getCodigo() != codigo ){
            newSurtidores[index] = surtidores[i];
            index++;
        }
    }
    delete[] surtidores;
    surtidores = newSurtidores;
    cantSurtidores = nuevacap;
}

void estacion::activarSurtidor(string codigo){
    for (int i=0; i < cantSurtidores;i++){
        if (surtidores[i].getCodigo() == codigo){
            surtidores[i].setEstado(true);
        }
    }
}

void estacion::desactivarSurtidor(string codigo){
    for (int i = 0; i< cantSurtidores;i++){
        if (surtidores[i].getCodigo() == codigo){
            surtidores[i].setEstado(false);
        }
    }
}

string estacion::getCodigo(){
    return codigo;
}

string estacion::getNombre(){
    return nombre;
}

string estacion::getRegion(){
    return region;
}

string estacion::getCoordenadas(){
    return coordenadas;
}
/*
int getCantSurtidores(){
    return cantSurtidores;
}
*/

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

