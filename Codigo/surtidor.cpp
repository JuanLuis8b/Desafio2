#include <fstream>
#include <random>
#include "surtidor.h"
#include "tanque.h"

string getFecha();
string combustible(string num);
string t_metodoPago(string metodo);
string calcularPrecio(string tipo, string cantidad, surtidor &Surtidor);
string randomCedula();
string randomCombustible();
string randomMetodoPago();
string randomCantidad();

//CONSTRUCTORES

surtidor::surtidor(){
    codigo = "";
    modelo = "";
    estado = false;
    tanqueCentral = nullptr;
    precioR = nullptr;
    precioP = nullptr;
    precioE = nullptr;
}

surtidor::surtidor(string n_codigo, string n_modelo, tanque* n_tanqueCentral, int** n_precioR, int** n_precioP, int** n_precioE){
    codigo = n_codigo;
    modelo = n_modelo;
    estado = true;
    tanqueCentral = n_tanqueCentral;
    precioR = n_precioR;
    precioP = n_precioP;
    precioE = n_precioE;
}

//GETTERS

string surtidor::getCodigo(){
    return codigo;
}

bool surtidor::getEstado(){
    return estado;
}

int surtidor::getPrecioR(){
    return **precioR;
}

int surtidor::getPrecioP(){
    return **precioP;
}

int surtidor::getPrecioE(){
    return **precioE;
}

string surtidor::getModelo(){
    return modelo;
}

//SETTERS

void surtidor::setModelo(string nuevoModelo){
    modelo = nuevoModelo;
}

void surtidor::setEstado(bool nuevoEstado){
    estado = nuevoEstado;
}

//OTROS METODOS

void surtidor::vender(string nomArchivo){
    string fecha = getFecha();
    string cedula = randomCedula();
    string tipo = randomCombustible();
    string cantidad = randomCantidad();
    int pago;
    int cant = stoi(cantidad);
    if (tipo == "Regular"){
        if (tanqueCentral->getCantR()==0){
            cerr<<"No hay combustible disponible.";
            return;
        }
        if (tanqueCentral->getCantR()<cant){
            cant = tanqueCentral->getCantR();
        }
        pago = **precioR * cant;
        tanqueCentral->restarCantR(cant);
    }else if (tipo == "Premium"){
        if (tanqueCentral->getCantP()==0){
            cerr<<"No hay combustible disponible.";
            return;
        }
        if (tanqueCentral->getCantP()<cant){
            cant = tanqueCentral->getCantR();
        }
        pago = **precioP * cant;
        tanqueCentral->restarCantP(cant);
    }else {
        if (tanqueCentral->getCantE()==0){
            cerr<<"No hay combustible disponible.";
            return;
        }
        if (tanqueCentral->getCantE()<cant){
            cant = tanqueCentral->getCantE();
        }
        pago = **precioP * cant;
        tanqueCentral->restarCantE(cant);
    }
    string montoPago = to_string(pago);
    cantidad = to_string(cant);
    string metodoPago = randomMetodoPago();
    string registro = codigo + " | " + fecha + " | " + cedula + " | " + tipo + " | " + cantidad + " | " + montoPago + " | " + metodoPago;
    ofstream file(nomArchivo, ios::out | ios::app);
    if (!file.is_open()){
        cerr<<"Error abriendo archivo.";
        return;
    }
    file << registro << endl;
    file.close();
    cout<<"Informacion de la transaccion:\n";
    cout << registro << endl;
}

string getFecha(){
    time_t t = time(nullptr);
    auto tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%d/%m/%Y | %H:%M:%S");
    string str = oss.str();
    return str;
}

string combustible(string num){
    if (num == "1"){
        return "Regular";
    }
    else if (num == "2"){
        return "Premium";
    }
    else {
        return "Eco";
    }
}

string t_metodoPago(string metodo){
    if (metodo == "1"){
        return "Efectivo";
    }else if (metodo == "2"){
        return "Debito";
    }else {
        return "Credito";
    }
}

string calcularPrecio(string tipo, string cantidad, surtidor& Surtidor){
    int cant = stoi(cantidad);
    int pago;

    if (tipo == "Regular"){
        pago = Surtidor.getPrecioR() * cant;
        return to_string(pago);
    }else if (tipo == "Premium"){
        pago = Surtidor.getPrecioP() * cant;
        return to_string(pago);
    }else {
        pago = Surtidor.getPrecioE() * cant;
        return to_string(pago);
    }
}

string randomCedula(){
    random_device x;
    uniform_int_distribution<> distrib(10000000,99999999);
    return to_string(distrib(x));
}

string randomCombustible(){
    random_device x;
    uniform_int_distribution<> distrib(1,3);
    string tipo = to_string(distrib(x));
    return combustible(tipo);
}

string randomMetodoPago(){
    random_device x;
    uniform_int_distribution<> distrib(1,3);
    string tipo = to_string(distrib(x));
    return t_metodoPago(tipo);
}

string randomCantidad(){
    random_device x;
    uniform_int_distribution<> distrib(3,20);
    return to_string(distrib(x));
}
