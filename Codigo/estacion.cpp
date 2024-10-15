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

void estacion::consultarHistorico(string nomArchivo){

    string datos[cantSurtidores];

    ifstream file (nomArchivo);

    if (!file.is_open()){
        cerr<<"Error abriendo archivo.";
        return;
    }

    string linea;
    while (getline(file,linea)){

        string codigo = linea.substr(0,4);
        string info = linea.substr(8)+"\n";

        for (int i = 0; i<cantSurtidores; i++){
            if (surtidores[i].getCodigo()==codigo){
                datos[i]+=info;
            }
        }
    }

    for (int i = 0; i<cantSurtidores;i++){
        cout<<"Surtidor #"<<surtidores[i].getCodigo()<<endl;
        cout<<datos[i]<<endl;
    }
}

void estacion::reporteLitros(string nomArchivo){

    fstream file (nomArchivo);

    if (!file.is_open()){
        cerr<<"Error abriendo archivo.";
        return;
    }

    float litrosR, litrosP, litrosE;

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

        if (tipoCombustible=="Regular"){
            //litrosR+= double(cantidad);
        }else if (tipoCombustible=="Premium"){
            //litrosP+= double(cantidad);
        }else {
            //litrosE+= double(cantidad);
        }
    }
    cout<<"Litros vendidos:\n";
    cout<<"  Regular: "<<litrosR<<"\n";
    cout<<"  Premium: "<<litrosP<<"\n";
    cout<<"  EcoExtra: "<<litrosE<<"\n";
}

void estacion::verificarFugas(string nomArchivo){
    fstream file (nomArchivo);

    if (!file.is_open()){
        cerr<<"Error abriendo archivo.";
        return;
    }

    float litrosR,litrosP,litrosE;

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

        if (tipoCombustible=="Regular"){
            litrosR+= stod(cantidad);
        }else if (tipoCombustible=="Premium"){
            litrosP+= stod(cantidad);
        }else {
            litrosE+= stod(cantidad);
        }
    }

    cout<<"Combustible regular: ";
    float porcentajeR = ((litrosR+tanqueCentral.getCantR())/(tanqueCentral.getCapR()))*100;
    if ((litrosR+tanqueCentral.getCantR())>=(tanqueCentral.getCapR()*0.95)){
        cout<<"No hay fuga. Correspondencia al "<<porcentajeR<<"%";
    }else{
        cout<<"¡Alerta de fuga! Correspondencia al"<<porcentajeR<<"%";
    }
    cout<<"Combustible premium: ";
    float porcentajeP = ((litrosP+tanqueCentral.getCantP())/(tanqueCentral.getCapP()))*100;
    if ((litrosR+tanqueCentral.getCantP())>=(tanqueCentral.getCapP()*0.95)){
        cout<<"No hay fuga. Correspondencia al "<<porcentajeP<<"%";
    }else{
        cout<<"¡Alerta de fuga! Correspondencia al"<<porcentajeP<<"%";
    }
    cout<<"Combustible EcoExtra: ";
    float porcentajeE = ((litrosE+tanqueCentral.getCantE())/(tanqueCentral.getCapE()))*100;
    if ((litrosR+tanqueCentral.getCantE())>=(tanqueCentral.getCapE()*0.95)){
        cout<<"No hay fuga. Correspondencia al "<<porcentajeE<<"%";
    }else{
        cout<<"¡Alerta de fuga! Correspondencia al"<<porcentajeE<<"%";
    }
}

void estacion::setCodigo(string cod){
    codigo = cod;
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

