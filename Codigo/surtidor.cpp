#include "surtidor.h"

string getFecha(){
    //auto permite al compilador deducir el tipo de dato
    time_t t = time(nullptr);//devuelve la hora como segundos (tipo time_t)
    auto tm = *localtime(&t);//lo convierte al formato local
    ostringstream oss;//construir cadena
    oss << put_time(&tm, "%d/%m/%Y %H:%M:%S");//formatear la fecha y hora
    string str = oss.str();//obtener la cadena
    return str;
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

surtidor(string code, string mod, tanque tan, bool status){
    codigo = code;
    modelo = mod;
    tanqueAsociado = tan;
    estado = status;
}

string calcularPrecio(string cantidad){
        //int precio = tanqueAsociado.getPrecioPerGalon();
        //string total = to_string(stoi(cantidad)*precio)
        //return total;
}

string vender(){

    string fecha = getFecha();
    cout<<"Numero de cedula: ";
    string cedula;
    cin << cedula;
    cout<<"(1) Regular, (2) Premium, (3) EcoExtra -> ";
    string tipo;
    cin << tipo;
    cout << "Galones vendidos: ";
    string cantidad;
    cin << cantidad;
    cout <<"(1) Efectivo, (2) Tarjeta Debito, (3) Tarjeta Credito ->: ";
    string metodoPago;
    cin << metodoPago;
    string precio = precioTotal(cantidad);
    string registro = codigo + " " + fecha + " " + cedula + " " + tipo + " " + cantidad + " " + precio + " " + metodoPago;

    //cantidad = tanqueAsociado.getCantidad;
    //tanqueAsociado.setCantidad(cantidad - cantidadvendida)
    //---- O
    //tanqueAsociado.actualizar(cantidad);
    //return registro;
    //registrarVenta(registro,);
    }
