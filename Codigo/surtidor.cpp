#include "surtidor.h"
#include "estacion.h"
/*
string getFecha(){
    //auto permite al compilador deducir el tipo de dato
    time_t t = time(nullptr);//devuelve la hora como segundos (tipo time_t)
    auto tm = *localtime(&t);//lo convierte al formato local
    ostringstream oss;//construir cadena
    oss << put_time(&tm, "%d/%m/%Y %H:%M:%S");//formatear la fecha y hora
    string str = oss.str();//obtener la cadena
    return str;
}

surtidor(string code, string mod, bool status){
    codigo = code;
    modelo = mod;
    //tanqueAsociado = tan;
    estado = status;
}



string calcularPrecio(string tipo, float cantidad, estacion& A){

    if (tipo == "Regular"){
        return (A.getPrecioRegular()*cantidad);
    }else if (tipo == "Premium"){
        return (A.getPrecioPremium()*cantidad);
    }else if (tipo == "Eco"){
        return (A.getPrecioEco()*cantidad);
    }
}

string combustible(string num){
    if (num == "1"){
        return "Regular";
    }
    else if (num == "2"){
        return "Premium";
    }
    else if (num == "3"){
        return "Eco";
    }
}

string vender(){

    string fecha = getFecha();
    cout<<"Numero de cedula: ";
    string cedula;
    cin << cedula;
    cout<<"(1) Regular, (2) Premium, (3) EcoExtra -> ";
    string tipo;
    cin << tipo;
    tipo = combustible(tipo);
    cout << "Galones vendidos: ";
    string cantidad;
    cin << cantidad;
    string montoPago = calcularPrecio(tipo,cantidad,A);
    cout <<"(1) Efectivo, (2) Tarjeta Debito, (3) Tarjeta Credito ->: ";
    string metodoPago;


    string registro = codigo + " " + fecha + " " + cedula + " " + tipo + " " + cantidad + " " + montoPago + " " + metodoPago;
    return registro;

}

void registrarVenta(string info, string archivo){
    ofstream file(Archivo, ios::out | ios::app);

    if (!open.file()){
        cerr<<"Error abriendo archivo.";
        return;
    }

    file << info << endl;
    file.close();
}
*/

surtidor(string n_codigo, string n_modelo, tanque& n_tanqueCentral, int& n_precioR, int& n_precioP, int& n_precioE){
    codigo = n_codigo;
    modelo = n_modelo;
    tanqueCentral = n_tanqueCentral;
    precioR = n_precioR;
    precioP = n_precioP;
    precioE = n_precioE;
}

string getCodigo(){
    return codigo;
}
bool getEstado(){
    return estado;
}
int getPrecioR(){
    return precioR;
}
int getPrecioP(){
    return precioP;
}
int getPrecioE(){
    return precioE;
}

void setModelo(string nuevoModelo){
    modelo = nuevoModelo;
}
void setEstado(bool nuevoEstado){
    estado = nuevoEstado;
}


