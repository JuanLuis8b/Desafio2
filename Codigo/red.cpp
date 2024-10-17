#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "red.h"
#include "estacion.h"


/*
int precioRNorte;
int precioRCentro;
int precioRSur;

int precioPNorte;
int precioPCentro;
int precioPSur;

int precioENorte;
int precioECentro;
int precioESur;

int capacidad = 1;
estacion* estaciones;
*/
//string n_nombre, string n_codigo, string n_region, string n_coordenadas, string n_gerente, int* n_precioR, int* n_precioP, int* n_precioE

string genCodigo_(string codigo){
    int codInt = stoi(codigo);
    codInt+=100;
    ostringstream oss;
    oss << setw(codigo.size())<<setfill('0')<<codInt;
    return oss.str();
}

red::red(){

    precioRNorte = 0;
    precioRCentro = 0;
    precioRSur = 0;
    precioPNorte = 0;
    precioPCentro = 0;
    precioPSur = 0;
    precioENorte = 0;
    precioECentro = 0;
    precioESur = 0;
    capacidad = 1;

    estaciones = new estacion[capacidad];

    primeraEstacion = true;

    //estacion(string n_nombre, string n_codigo, string n_region, string n_coordenadas, string n_gerente, int *n_precioR, int *n_precioP, int *n_precioE);
    //new (&estaciones[0]) estacion("Colombia","00100","Centro","(12.456, -08.345)","Juan Luis",&precioRCentro,&precioPCentro,&precioPSur);
    //estaciones[0] = estacion("Colombia","00100","Centro","(12.456, -08.345)","Juan Luis",&precioRCentro,&precioPCentro,&precioPSur);
}

/*red::red(){

}*/

int red::getCapacidad(){
    return capacidad;
}

estacion* red::getEstaciones(){
    return estaciones;

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

/*
string nombre;
string codigo;
string region;
string coordenadas;
string gerente;

tanque tanqueCentral;

int* precioR;
int* precioP;
int* precioE;

int cantSurtidores = 2;

surtidor* surtidores;// = new surtidor[cantSurtidores];
*/
string elegirRegion(){
    cout<<"(1) Norte\n(2) Centro\n(3) Sur\n->";
    string input;
    cin>>input;
    while (input != "1" && input != "2" && input != "3"){
        cerr<<"Opcion invalida. Ingrese un numero: ";
        cin>>input;
    }
    if (input == "1"){
        return "Norte";
    }else if (input == "2"){
        return "Centro";
    }else{
        return "Sur";
    }
}

void red::agregarEstacion(){

    cout<<"\nIngrese el nombre de la estacion: ";
    string nombre;
    cin>>nombre;
    string codigo;

    cout<<"\nIngrese la region:\n";
    string region = elegirRegion();
    cout<<"\nIngrese las coordenadas: ";
    string coor;
    cin>>coor;
    cout<<"\nIngrese el nombre del gerente: ";
    string gerente;
    cin>>gerente;

    int nuevacap;

    if (primeraEstacion){
        primeraEstacion = false;
        codigo = "00100";
        nuevacap = capacidad;
        ultimocodigo = codigo;
    }else{
        codigo = genCodigo_(ultimocodigo);
        nuevacap = capacidad+1;
    }

/*
    int* precioR = nullptr;
    int* precioP = nullptr;
    int* precioE = nullptr;

    if (region == "Norte"){
        precioR = precioRNorte;
        precioP = precioPNorte;
        precioE = precioENorte;
    }else if (region == "Centro"){
        precioR = precioRCentro;
        precioP = precioPCentro;
        precioE = precioECentro;
    }else{
        precioR = precioRSur;
        precioP = precioPSur;
        precioE = precioESur;
    }
*/
    estacion nuevaEstacion;


    if (region == "Norte"){
        nuevaEstacion = estacion(nombre,codigo,region,coor,gerente,&precioRNorte,&precioPNorte,&precioENorte);
    }else if (region == "Centro"){
        nuevaEstacion = estacion(nombre,codigo,region,coor,gerente,&precioRCentro,&precioPCentro,&precioECentro);
    }else {
        nuevaEstacion = estacion(nombre,codigo,region,coor,gerente,&precioRSur,&precioPSur,&precioESur);
    }


    estacion* newEstaciones = new estacion[nuevacap];
    for (int i = 0; i<capacidad;i++){
        newEstaciones[i] = estaciones[i];
    }
    newEstaciones[nuevacap-1] = nuevaEstacion;
    delete[] estaciones;
    estaciones = newEstaciones;
    capacidad = nuevacap;
}

/*
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
*/

void red::eliminarEstacion(string codigo){

    for (int i = 0; i<capacidad;i++){
        if (estaciones[i].getCodigo()==codigo){
            for (int j = 0; j<estaciones[i].getCantSurtidores();j++){
                if (estaciones[i].getSurtidores()->getEstado()){
                    cerr<<"\nDesactive los surtidores para eliminar estacion.";
                    return;
                }
            }
        }
    }
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


    int datos[capacidad][3] = {0,0,0};

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
