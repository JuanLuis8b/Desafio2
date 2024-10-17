#include <fstream>
#include <random>
#include "surtidor.h"
#include "tanque.h"

string getFecha(){
    //auto permite al compilador deducir el tipo de dato
    time_t t = time(nullptr);//devuelve la hora como segundos (tipo time_t)
    auto tm = *localtime(&t);//lo convierte al formato local
    ostringstream oss;//construir cadena
    oss << put_time(&tm, "%d/%m/%Y | %H:%M:%S");//formatear la fecha y hora
    string str = oss.str();//obtener la cadena
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
/*
void surtidor::vender(){

    string fecha = getFecha();
    cout<<"Numero de cedula: ";
    string cedula;
    cin >> cedula;
    cout<<"\n(1) Regular\n(2) Premium\n(3) EcoExtra\n->";
    string tipo;
    cin >> tipo;
    tipo = combustible(tipo);
    cout << "\nGalones vendidos: ";
    string cantidad;
    cin >> cantidad;
    string montoPago = calcularPrecio(tipo,cantidad,Surtidor);
    cout <<"\n(1) Efectivo\n(2) Tarjeta Debito\n(3) Tarjeta Credito\n->";
    string metodoPago;
    cin >> metodoPago;
    metodoPago = t_metodoPago(metodoPago);

    string registro = Surtidor.getCodigo() + " | " + fecha + " | " + cedula + " | " + tipo + " | " + cantidad + " | " + montoPago + " | " + metodoPago;

}

void registrarVenta(string info, string nomArchivo){
    ofstream file(nomArchivo, ios::out | ios::app);

    if (!file.is_open()){
        cerr<<"Error abriendo archivo.";
        return;
    }

    file << info << endl;
    file.close();
}*/

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

void surtidor::setModelo(string nuevoModelo){
    modelo = nuevoModelo;
}
void surtidor::setEstado(bool nuevoEstado){
    estado = nuevoEstado;
}

string surtidor::getModelo(){
    return modelo;
}


