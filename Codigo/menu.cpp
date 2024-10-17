#include "red.h"
#include "estacion.h"
#include <string>
using namespace std;

bool esNumero(const string& str) {
    try {
        size_t pos; // Para almacenar la posición después de la conversión
        int numero = stoi(str, &pos);
        return pos == str.length(); // Verifica que toda la cadena fue convertida
    } catch (invalid_argument& e) {
        return false; // No se pudo convertir a número
    } catch (out_of_range& e) {
        return false; // El número está fuera de rango
    }
}

void fijarPrecios(red& redNacional){

    int precioRN, precioPN, precioEN;
    int precioRC, precioPC, precioEC;
    int precioRS, precioPS, precioES;

    cout << "\nRegion Norte:\n";
    cout << "  Regular: ";
    string precioRNstr;
    cin >> precioRNstr;
    while (!esNumero(precioRNstr)) {
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> precioRNstr;
    }
    precioRN = stoi(precioRNstr);
    cout << "  Premium: ";
    string precioPNstr;
    cin >> precioPNstr;
    while (!esNumero(precioPNstr)) {
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> precioPNstr;
    }
    precioPN = stoi(precioPNstr);
    cout << "  Eco: ";
    string precioENstr;
    cin >> precioENstr;
    while (!esNumero(precioENstr)) {
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> precioENstr;
    }
    precioEN = stoi(precioENstr);
    cout << "\nRegion Centro:\n";
    cout << "  Regular: ";
    string precioRCstr;
    cin >> precioRCstr;
    while (!esNumero(precioRCstr)) {
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> precioRCstr;
    }
    precioRC = stoi(precioRCstr);
    cout << "  Premium: ";
    string precioPCstr;
    cin >> precioPCstr;
    while (!esNumero(precioPCstr)) {
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> precioPCstr;
    }
    precioPC = stoi(precioPCstr);
    cout << "  Eco: ";
    string precioECstr;
    cin >> precioECstr;
    while (!esNumero(precioECstr)) {
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> precioECstr;
    }
    precioEC = stoi(precioECstr);
    cout << "\nRegion Sur:\n";
    cout << "  Regular: ";
    string precioRSstr;
    cin >> precioRSstr;
    while (!esNumero(precioRSstr)) {
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> precioRSstr;
    }
    precioRS = stoi(precioRSstr);
    cout << "  Premium: ";
    string precioPSstr;
    cin >> precioPSstr;
    while (!esNumero(precioPSstr)) {
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> precioPSstr;
    }
    precioPS = stoi(precioPSstr);
    cout << "  Eco: ";
    string precioESstr;
    cin >> precioESstr;
    while (!esNumero(precioESstr)) {
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> precioESstr;
    }
    precioES = stoi(precioESstr);

    redNacional.setPrecioRNorte(precioRN);
    redNacional.setPrecioPNorte(precioPN);
    redNacional.setPrecioENorte(precioEN);

    redNacional.setPrecioRCentro(precioRC);
    redNacional.setPrecioPCentro(precioPC);
    redNacional.setPrecioECentro(precioEC);

    redNacional.setPrecioRSur(precioRS);
    redNacional.setPrecioPSur(precioPS);
    redNacional.setPrecioESur(precioES);
}

int elegirEstacion(red& nameRed){
    cout<<"\nDigite:\n";
    for (int i = 0; i < nameRed.getCapacidad();i++){
        cout<<"("<<(i+1)<<") "<<nameRed.getEstaciones()[i].getNombre()<<endl;
    }
    cout<<"-> ";
    string input;
    cin >> input;
    while (!esNumero(input)){
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> input;
    }
    return (stoi(input)-1);
}

string elegirSurtidor(estacion& nameEstacion){

    if (nameEstacion.getCantSurtidores()==0 || nameEstacion.getPrimerSurtidor()){
        cout<<"\nNo hay surtidores.";
        return "";
    }

    cout<<"\nDigite:\n";
    for (int i = 0; i < nameEstacion.getCantSurtidores();i++){
        cout<<"("<<(i+1)<<") "<<nameEstacion.getSurtidores()[i].getCodigo()<<endl;
    }
    cout<<"-> ";
    string input;
    cin >> input;
    while (!esNumero(input)){
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> input;
    }
    int index = (stoi(input)-1);
    return nameEstacion.getSurtidores()[index].getCodigo();
}

string elegirSurtidor_(estacion& nameEstacion){
//imprime los estados
    if (nameEstacion.getCantSurtidores()==0 || nameEstacion.getPrimerSurtidor()){
        cout<<"\nNo hay surtidores.";
        return "";
    }

    cout<<"\nDigite:\n";
    for (int i = 0; i < nameEstacion.getCantSurtidores();i++){
        cout<<"("<<(i+1)<<") "<<nameEstacion.getSurtidores()[i].getCodigo()<<" Estado: "<<(nameEstacion.getSurtidores()[i].getEstado() ? "Activo\n" : "Desactivo\n") ;
    }
    cout<<"-> ";
    string input;
    cin >> input;
    while (!esNumero(input)){
        cerr << "Valor invalido. Ingrese un numero: ";
        cin >> input;
    }
    int index = (stoi(input)-1);
    return nameEstacion.getSurtidores()[index].getCodigo();
}
