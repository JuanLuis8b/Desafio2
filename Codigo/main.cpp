/*
Tengo 3 clases en C++ y necesito que se cumpla lo siguiente: La clase A tendrá un atributo, que necesito pueda ser utilizado por la clase B y la clase C ( la clase C es parte de la clase B y la clase B es parte de la clase A). Pero necesito que los valores que hay en B y C cambien cuando cambie el valor de A, para ello pensé en utlizar punteros que apunten a la direccion de memoria del atributo de la clase A, entonces, en la clase B habrá un puntero a la direccion de memoria del valor en la clase A, y la clase C también hará lo mismo, pero entonces como el valor de A solo puede entrar a C a través de B necesitaré un puntero a puntero, ¿cómo harías la implementacion? Piensa paso a paso
*/

#include "red.h"
#include "estacion.h"
#include "surtidor.h"
#include <string>

bool esNumero(const string& str);
void fijarPrecios(red& nameRed);

int main(){

    bool salir = false;
    while (salir == false){
        cout<<"Bienvenido.\n\nDigite:\n(1) Cargar red existente\n(2) Crear nueva red\n(3) Salir\n-> ";
        int input;
        cin >> input;

        switch (input) {

            case 1 : {
                //red redNacional;

                break;
            }
            case 2 : {
                bool case2 = false;
                while (case2 == false){

                    red redNacional;
                    cerr<<"\nRed Nacional.\n";
                    int input3;
                    cout<<"Digite: \n(1) Agregar estacion\n(2) Eliminar estacion\n(3) Fijar precios en la red\n(4) Reporte de ventas\n(5) Seleccionar una estacion\n(6) Salir\n-> ";
                    cin>>input3;

                    switch (input3) {

                        case 1 : {


                        break;
                        }

                        case 2 : {


                        break;
                        }

                        case 3 : {
                            fijarPrecios(redNacional);
                            break;
                        }
                        case 4 : {

                        break;
                        }

                        case 5 : {

                        break;
                        }

                        default : {
                            case2 = true;
                            salir = true;
                            break;
                        }
                    }
                }
                break;
            }

            default : {
                salir = true;
            }
        }
    }

    return 0;
}

void fijarPrecios(red& redNacional){

    int precioRN, precioPN, precioEN;
    int precioRC, precioPC, precioEC;
    int precioRS, precioPS, precioES;

    cout << "Region Norte:\n";
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
    cout << "Region Centro:\n";
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
    cout << "Region Sur:\n";
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
