
#include "menu.h"
#include "red.h"
#include "estacion.h"
#include "surtidor.h"
#include <string>

//cargar info en archivos, descargar info en archivos

int main(){

    bool salir = false;

    red miRed;

    string database;
    string registros;

    while (!salir){

        cout<<"Bienvenido.\n\nDigite:\n(1) Cargar red existente\n(2) Crear nueva red\n(#) Salir\n-> ";
        int input;
        cin >> input;



        if (input == 1){
            cout<<"Ingrese nombre del archivo fuente: ";
            cin >> database;
            database += ".txt";
            cout<<"Ingrese nombre del archivo de registros: ";
            cin >> registros;
            registros += ".txt";
            descargarRed(miRed, database);

        }else if (input == 2){
            cout<<"Ingrese nombre para el archivo fuente: ";
            cin >> database;
            database += ".txt";
            cout<<"Ingrese nombre para el archivo de registros: ";
            cin >> registros;
            registros += ".txt";
        }
        else{
            salir = true;
        }

        bool main = false;

        while (!main){

            cerr<<"\nRed Nacional.\n";
            int input2;
            cout<<"\nDigite: \n(1) Agregar estacion\n(2) Eliminar estacion\n(3) Fijar precios en la red\n(4) Reporte de ventas\n(5) Seleccionar una estacion\n(#) Salir\n-> ";
            cin>>input2;

            switch (input2) {

                case 1 : {

                    miRed.agregarEstacion();
                    cout<<"\nEstacion agregada.\n";
                    break;
                }

                case 2 : {

                    int index = elegirEstacion(miRed);
                    if (index == -1){
                        break;
                    }
                    string codigo = miRed.getEstaciones()[index].getCodigo();
                    miRed.eliminarEstacion(codigo);
                    cout<<"\nEstacion eliminada.\n";
                    break;

                }

                case 3 : {

                    fijarPrecios(miRed);
                    break;

                }

                case 4 : {

                    miRed.reporteVentas(registros);
                    break;

                }

                case 5 : {

                    int index = elegirEstacion(miRed);
                    if (index == -1){
                        break;
                    }
                    estacion& miEstacion = miRed.getEstaciones()[index];

                    bool volver = false;
                    while (!volver) {

                        cout<<"\nEstacion "<<miEstacion.getNombre()<<endl;
                        cout<<"\nDigite: \n(1) Agregar surtidor\n(2) Eliminar surtidor\n(3) Activar/desactivar surtidor\n(4) Consultar historial de ventas\n(5) Reporte de litros vendidos\n(6) Simular venta\n(7) Verificar fugas\n(8) Volver\n(#) Salir\n-> ";
                        int input3;
                        cin>>input3;

                        switch (input3) {

                            case 1 : {

                                miEstacion.agregarSurtidor();
                                break;

                            }

                            case 2 : {

                                string codigo = elegirSurtidor(miEstacion);
                                miEstacion.eliminarSurtidor(codigo);
                                break;

                            }

                            case 3 : {

                                string codigo = elegirSurtidor_(miEstacion);
                                miEstacion.activarDesactivarSurtidor(codigo);
                                break;

                            }

                            case 4 : {

                                miEstacion.consultarHistorico(registros);
                                break;

                            }

                            case 5 : {

                                miEstacion.reporteLitros(registros);
                                break;

                            }

                            case 6 : {

                                miEstacion.simularVenta(registros);
                                break;

                            }

                            case 7 : {

                                miEstacion.verificarFugas(registros);
                                break;

                            }

                            case 8 : {

                                volver = true;
                                break;

                            }

                            default : {

                                salir = true;
                                volver = true;
                                break;

                            }

                        }

                    }

                    break;

                }

                default : {

                    salir = true;
                    main = true;
                    break;

                }
            }
        }
    }

    cargarRed(miRed,database);

    return 0;

}
