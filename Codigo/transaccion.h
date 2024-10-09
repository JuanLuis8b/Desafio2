#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef transaccion_h
#define transaccion_h

class transaccion
{
private:
    string fecha;
    string hora;
    string cedula;
    unsigned int cantidad;
    string categoria;
    unsigned int pago;
    string metodoPago;

public:
    transaccion(string ff, string hh, string cc,unsigned int cd, string ct, unsigned int pg,string mP){
        fecha = ff;
        hora = hh;
        cedula = cc;
        cantidad = cd;
        categoria = ct;
        pago = pg;
        metodoPago = mP;
    }

    string getFecha (){
        return fecha;
    }
    string getHora(){
        return hora;
    }
    string getCedula(){
        return cedula;
    }
    int getCantidad(){
        return cantidad;
    }
    string getCategoria(){
        return categoria;
    }
    int getPago(){
        return pago;
    }
    string getMetodoPago(){
        return metodoPago;
    }

    void registrar(const string Archivo){

        ofstream file(Archivo);//ios :: app

        if (!open.file()){
            cerr<<"Error abriendo archivo.";
            return;
        }
    //--------------------

    }
};

#endif // TRANSACCION_H
