#include <fstream>
#include <sstream>
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

    if (nameRed.getCapacidad()==0 || nameRed.getPrimeraEstacion()){
        cerr<<"\nNo hay estaciones.";
        return -1;
    }

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

void descargarRed(red& miRed, string nomDatos){

    ifstream file (nomDatos);

    if (!file.is_open()){
        cerr<<"Error abriendo archivo.";
    }

    string linea;
    int indexE = -1;
    int indexS;

    while (getline(file,linea)){
        if(linea.rfind("Red:",0)==0){
            stringstream ss(linea);
            string precioRNorte, precioRCentro, precioRSur, precioPNorte, precioPCentro, precioPSur, precioENorte, precioECentro, precioESur, capacidad, primeraEstacion, ultimocodigo;
            ss.ignore(5);
            ss>>precioRNorte;
            ss.ignore(3);
            ss>>precioRCentro;
            ss.ignore(3);
            ss>>precioRSur;
            ss.ignore(3);
            ss>>precioPNorte;
            ss.ignore(3);
            ss>>precioPCentro;
            ss.ignore(3);
            ss>>precioPSur;
            ss.ignore(3);
            ss>>precioENorte;
            ss.ignore(3);
            ss>>precioECentro;
            ss.ignore(3);
            ss>>precioESur;
            ss.ignore(3);
            ss>>capacidad;
            ss.ignore(3);
            ss>>primeraEstacion;
            ss.ignore(3);
            ss>>ultimocodigo;

            miRed = red(stoi(capacidad));

            miRed.setPrecioRNorte(stoi(precioRNorte));
            miRed.setPrecioRCentro(stoi(precioRCentro));
            miRed.setPrecioRSur(stoi(precioRSur));
            miRed.setPrecioPNorte(stoi(precioPNorte));
            miRed.setPrecioPCentro(stoi(precioPCentro));
            miRed.setPrecioPSur(stoi(precioPSur));
            miRed.setPrecioENorte(stoi(precioENorte));
            miRed.setPrecioECentro(stoi(precioECentro));
            miRed.setPrecioESur(stoi(precioESur));
            miRed.setPrimeraEstacion((primeraEstacion) == "true" ? true : false);
            miRed.setUltimoCodigo(ultimocodigo);
        }
        if (linea.rfind("Estacion:",0)==0){
            indexS = -1;
            indexE++;
            stringstream ss(linea);
            string nombre,codigo,region,coordenadas,gerente,cantSurtidores,primerSurtidor,ultimocodigo,capR,capP,capE,cantR,cantP,cantE;
            ss.ignore(10);
            ss>>nombre;
            ss.ignore(3);
            ss>>codigo;
            ss.ignore(3);
            ss>>region;
            ss.ignore(3);
            ss>>coordenadas;
            ss.ignore(3);
            ss>>gerente;
            ss.ignore(3);
            ss>>cantSurtidores;
            ss.ignore(3);
            ss>>primerSurtidor;
            ss.ignore(3);
            ss>>ultimocodigo;
            ss.ignore(3);
            ss>>capR;
            ss.ignore(3);
            ss>>capP;
            ss.ignore(3);
            ss>>capE;
            ss.ignore(3);
            ss>>cantR;
            ss.ignore(3);
            ss>>cantP;
            ss.ignore(3);
            ss>>cantE;

            estacion miEstacion;
            if (region == "Norte"){
                miEstacion = estacion(nombre,codigo,region,coordenadas,gerente,miRed.getPrecioRNorte(),miRed.getPrecioPNorte(),miRed.getPrecioENorte(),stoi(cantSurtidores));
            }else if (region == "Centro"){
                miEstacion = estacion(nombre,codigo,region,coordenadas,gerente,miRed.getPrecioRCentro(),miRed.getPrecioPCentro(),miRed.getPrecioECentro(),stoi(cantSurtidores));
            }else {
                miEstacion = estacion(nombre,codigo,region,coordenadas,gerente,miRed.getPrecioRSur(),miRed.getPrecioPSur(),miRed.getPrecioESur(),stoi(cantSurtidores));
            }

            miEstacion.setUltimoCodigo(ultimocodigo);
            miEstacion.setPrimerSurtidor((primerSurtidor=="true")?true:false);

            miEstacion.getTanque()->setCapR(stoi(capR));
            miEstacion.getTanque()->setCapP(stoi(capP));
            miEstacion.getTanque()->setCapE(stoi(capE));
            miEstacion.getTanque()->setCantR(stoi(cantR));
            miEstacion.getTanque()->setCantP(stoi(cantP));
            miEstacion.getTanque()->setCantE(stoi(cantE));

            miRed.getEstaciones()[indexE] = miEstacion;
        }
        if (linea.rfind("Surtidor:",0)==0){
            indexS++;
            stringstream ss(linea);
            string codigo, modelo, estado;
            ss.ignore(10);
            ss>>codigo;
            ss.ignore(3);
            ss>>modelo;
            ss.ignore(3);
            ss>>estado;

            cout<<"infosurti: "<<codigo<<endl<<modelo<<endl<<estado<<endl;

            surtidor miSurtidor(codigo,modelo,miRed.getEstaciones()[indexE].getTanque(),miRed.getEstaciones()[indexE].getPrecioR(),miRed.getEstaciones()[indexE].getPrecioP(),miRed.getEstaciones()[indexE].getPrecioE());

            miSurtidor.setEstado(((estado=="true")?true:false));

            miRed.getEstaciones()[indexE].getSurtidores()[indexS] = miSurtidor;
        }
    }
}

void cargarRed(red& miRed, string nomFile){

    ofstream file (nomFile);

    if (!file.is_open()){
        cerr << "Error abriendo archivo."<<endl;
        return;
    }

    file << "Red: "
         << *miRed.getPrecioRNorte() << " | "
         << *miRed.getPrecioRCentro()<< " | "
         << *miRed.getPrecioRSur() << " | "
         << *miRed.getPrecioPNorte() << " | "
         << *miRed.getPrecioPCentro() << " | "
         << *miRed.getPrecioPSur() << " | "
         << *miRed.getPrecioENorte() << " | "
         << *miRed.getPrecioECentro() << " | "
         << *miRed.getPrecioESur() << " | "
         << miRed.getCapacidad() << " | "
         << (miRed.getPrimeraEstacion()? "true":"false")<<" | "
         << miRed.getUltimoCodigo()<<endl;

    for (int i = 0; i<miRed.getCapacidad();i++){
        file << "Estacion: "
             << miRed.getEstaciones()[i].getNombre()<<" | "
             << miRed.getEstaciones()[i].getCodigo()<<" | "
             << miRed.getEstaciones()[i].getRegion()<<" | "
             << miRed.getEstaciones()[i].getCoordenadas()<<" | "
             << miRed.getEstaciones()[i].getGerente()<<" | "
             << miRed.getEstaciones()[i].getCantSurtidores()<<" | "
             <<(miRed.getEstaciones()[i].getPrimerSurtidor()?"true":"false")<<" | "
             << miRed.getEstaciones()[i].getUltimoCodigo()<<" | "
             << miRed.getEstaciones()[i].getTanque()->getCapR() << " | "
             << miRed.getEstaciones()[i].getTanque()->getCapP() << " | "
             << miRed.getEstaciones()[i].getTanque()->getCapE() << " | "
             << miRed.getEstaciones()[i].getTanque()->getCantR() << " | "
             << miRed.getEstaciones()[i].getTanque()->getCantP() << " | "
             << miRed.getEstaciones()[i].getTanque()->getCantE() << endl;

        for (int j = 0; j< miRed.getEstaciones()[i].getCantSurtidores();j++){
            file<<"Surtidor: "
                << miRed.getEstaciones()[i].getSurtidores()[j].getCodigo()<<" | "
                <<miRed.getEstaciones()[i].getSurtidores()[j].getModelo()<<" | "
                <<(miRed.getEstaciones()[i].getSurtidores()[j].getEstado()?"true":"false")<<endl;
        }
    }
}
