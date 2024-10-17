#include <string>
#include <sstream>
#include <iostream>
#include <random>
using namespace std;

#include "estacion.h"
#include "tanque.h"
#include "surtidor.h"

//GETTERS

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

surtidor* estacion::getSurtidores(){
    return surtidores;
}

int estacion::getCantSurtidores(){
    return cantSurtidores;
}

bool estacion::getPrimerSurtidor(){
    return primerSurtidor;
}

tanque* estacion::getTanque(){
    return& tanqueCentral;
}

int** estacion::getPrecioR(){
    return& precioR;
}

int** estacion::getPrecioP(){
    return& precioP;
}

int** estacion::getPrecioE(){
    return& precioE;
}

string estacion::getUltimoCodigo(){
    return ultimoCodigo;
}

string estacion::getGerente(){
    return gerente;
}

//SETTERS

void estacion::setCodigo(string cod){
    codigo = cod;
}

void estacion::setPrimerSurtidor(bool valor){
    primerSurtidor = valor;
}

void estacion::setUltimoCodigo(string codigo){
    ultimoCodigo = codigo;
}

//CONSTRUCTORES

estacion::estacion(){

    nombre = "";
    codigo = "";
    region = "";
    coordenadas = "";
    gerente = "";

    cantSurtidores = 1;

    precioR = nullptr;
    precioP = nullptr;
    precioE = nullptr;

    primerSurtidor = true;

    surtidores = new surtidor[cantSurtidores];
}

estacion::estacion(string n_nombre, string n_codigo, string n_region, string n_coordenadas, string n_gerente, int* n_precioR, int* n_precioP, int* n_precioE, int n_cantS){

    nombre = n_nombre;
    codigo = n_codigo;
    region = n_region;
    coordenadas = n_coordenadas;
    gerente = n_gerente;

    precioR = n_precioR;
    precioP = n_precioP;
    precioE = n_precioE;

    cantSurtidores=n_cantS;

    primerSurtidor = true;

    surtidores = new surtidor[cantSurtidores];
}

//OTROS METODOS

string genCodigo(string codigo){
    int codInt = stoi(codigo);
    codInt++;
    ostringstream oss;
    oss << setw(codigo.size())<<setfill('0')<<codInt;
    return oss.str();
}

void estacion::agregarSurtidor(){

    if (cantSurtidores == 12){
        cerr<<"Ya se ha alcanzado el maximo de surtidores\n";
        return;
    }

    string codigoS;

    int nuevacap;

    if (primerSurtidor){
        primerSurtidor = false;
        codigoS = genCodigo(codigo);
        nuevacap = cantSurtidores;
        ultimoCodigo = codigoS;
    }else{
        codigoS = genCodigo(ultimoCodigo);
        nuevacap = cantSurtidores+1;
        ultimoCodigo = codigoS;
    }

    cout<<"Ingrese el modelo: ";
    string modelo;
    cin >> modelo;

    surtidor nuevoSurtidor(codigoS,modelo,&tanqueCentral,&precioR,&precioP,&precioE);

    surtidor* newSurtidores = new surtidor [nuevacap];
    for (int i = 0; i<cantSurtidores;i++){
        newSurtidores[i] = surtidores[i];
    }
    newSurtidores[nuevacap-1] = nuevoSurtidor;

    delete[] surtidores;
    surtidores = newSurtidores;
    cantSurtidores = nuevacap;
}

void estacion::eliminarSurtidor(string codigo){
    if (codigo == ""){
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

void estacion::activarDesactivarSurtidor(string codigo){
    for (int i=0; i < cantSurtidores;i++){
        if (surtidores[i].getCodigo() == codigo){
            if (surtidores[i].getEstado()){
                surtidores[i].setEstado(false);
            }else{
                surtidores[i].setEstado(true);
            }
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
        string codigo = linea.substr(0,5);
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

    ifstream file (nomArchivo);

    if (!file.is_open()){
        cerr<<"Error abriendo archivo.";
        return;
    }

    float litrosR = 0, litrosP = 0, litrosE = 0;

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
    cout<<"Litros vendidos:\n";
    cout<<"  Regular: "<<litrosR<<"\n";
    cout<<"  Premium: "<<litrosP<<"\n";
    cout<<"  EcoExtra: "<<litrosE<<"\n";
}

int randomIndex(int cap){
    random_device x;
    uniform_int_distribution<> distrib(0,cap-1);
    return distrib(x);
}

void estacion::simularVenta(string nomArchivo){
    int index = randomIndex(cantSurtidores);
    surtidores[index].vender(nomArchivo);
}

void estacion::verificarFugas(string nomArchivo){
    fstream file (nomArchivo);

    if (!file.is_open()){
        cerr<<"Error abriendo archivo.";
        return;
    }

    float litrosR = 0;
    float litrosP = 0;
    float litrosE = 0;

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
    if (porcentajeR>=95){
        cout<<"No hay fuga. Correspondencia al "<<porcentajeR<<"%\n";
    }else{
        cout<<"¡Alerta de fuga! Correspondencia al"<<porcentajeR<<"%\n";
    }
    cout<<"Combustible premium: ";
    float porcentajeP = ((litrosP+tanqueCentral.getCantP())/(tanqueCentral.getCapP()))*100;
    if (porcentajeP>=95){
        cout<<"No hay fuga. Correspondencia al "<<porcentajeP<<"%\n";
    }else{
        cout<<"¡Alerta de fuga! Correspondencia al"<<porcentajeP<<"%\n";
    }
    cout<<"Combustible EcoExtra: ";
    float porcentajeE = ((litrosE+tanqueCentral.getCantE())/(tanqueCentral.getCapE()))*100;
    if (porcentajeE >= 95){
        cout<<"No hay fuga. Correspondencia al "<<porcentajeE<<"%\n";
    }else{
        cout<<"¡Alerta de fuga! Correspondencia al"<<porcentajeE<<"%\n";
    }
}
