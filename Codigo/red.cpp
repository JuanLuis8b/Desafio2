#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "red.h"
#include "estacion.h"

red::red(){

}

void red::setPrecioRNorte(int precio) {
    precioRNorte = precio;
}

void red::setPrecioRCentro(int precio) {
    precioRCentro = precio;
}

void red::setPrecioRSur(int precio) {
    precioRSur = precio;
}

void red::setPrecioPNorte(int precio) {
    precioPNorte = precio;
}

void red::setPrecioPCentro(int precio) {
    precioPCentro = precio;
}

void red::setPrecioPSur(int precio) {
    precioPSur = precio;
}

void red::setPrecioENorte(int precio) {
    precioENorte = precio;
}

void red::setPrecioECentro(int precio) {
    precioECentro = precio;
}

void red::setPrecioESur(int precio) {
    precioESur = precio;
}

void red::agregarEstacion (estacion& A){
    int nuevacap = capacidad + 1;
    estacion* newEstaciones = new estacion[nuevacap];
    for (int i = 0; i<capacidad;i++){
        newEstaciones[i] = estaciones[i];
    }
    newEstaciones[nuevacap-1] = A;
    delete[] estaciones;
    estaciones = newEstaciones;
    capacidad = nuevacap;

}
void red::eliminarEstacion(string codigo){
    int nuevacap = capacidad - 1;
    estacion* newEstaciones = new estacion [nuevacap];
    int index = 0;
    for (int i = 0; i<capacidad; i++){
        if (estaciones[i].getCodigo()!=codigo){
            newEstaciones[index]=estaciones[i];
            index++;
        }
    }
    delete[] estaciones;
    estaciones = newEstaciones;
    capacidad = nuevacap;
}

void red::reporteVentas(string nomArchivo){


    int datos[capacidad][3];
    /*
    for (int i = 0; i<capacidad;i++){
        datos[i][0] = estaciones[i].getCodigo();
    }*/

    ifstream file (nomArchivo);

    if (!file.is_open()){
        cerr<<"Error abriendo archivo.";
        return;
    }

    int Regular = 0;
    int Premium = 1;
    int Eco = 2;

    string linea;
    while (getline(file,linea)){
        stringstream ss(linea);
        string codigo, fecha, hora, cedula, tipoCombustible, cantidad, totalStr, metodoPago;

        ss >> codigo;
        ss.ignore(3);
        ss>>fecha;
        ss.ignore(3);
        ss>>hora;
        ss.ignore(3);
        ss>>cedula;
        ss.ignore(3);
        ss>>tipoCombustible;
        ss.ignore(3);
        ss>>cantidad;
        ss.ignore(3);
        ss>>totalStr;
        ss.ignore(3);
        ss>>metodoPago;

        string codigoEstacion = codigo.substr(0,3)+"00";
        int totalPagado = stoi(totalStr);

        for (int i = 0; i<capacidad;i++){
            if (estaciones[i].getCodigo() == codigoEstacion){
                if (tipoCombustible == "Regular"){
                    datos[i][Regular] += totalPagado;
                }else if (tipoCombustible == "Premium"){
                    datos[i][Premium] += totalPagado;
                }else{
                    datos[i][Eco] += totalPagado;
                }
            }
        }
    }

    for (int i = 0; i<capacidad; i++){
        cout<<"\nEstacion "<<estaciones[i].getNombre()<<" - "<<estaciones[i].getCodigo()<<endl;
        cout<<"     Regular: "<<datos[i][Regular]<<endl;
        cout<<"     Premium: "<<datos[i][Premium]<<endl;
        cout<<"     EcoExtra: "<<datos[i][Eco]<<endl;
    }

    return;
}
