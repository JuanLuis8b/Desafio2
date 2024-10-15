
#include "menu.h"
#include "red.h"
#include "estacion.h"
#include "surtidor.h"
#include <string>


const string registros = "registros.txt";

int main(){
    bool salir = false;
    while (salir == false){
        cout<<"Bienvenido.\n\nDigite:\n(1) Cargar red existente\n(2) Crear nueva red\n(#) Salir\n-> ";
        int input;
        cin >> input;
        switch (input) {
            case 1 : {
                //red redNacional;
                break;
            }
            case 2 : {
                bool case2 = false;
                red redNacional;
                while (case2 == false){
                    cerr<<"\nRed Nacional.\n";
                    int input3;
                    cout<<"\nDigite: \n(1) Agregar estacion\n(2) Eliminar estacion\n(3) Fijar precios en la red\n(4) Reporte de ventas\n(5) Seleccionar una estacion\n(#) Salir\n-> ";
                    cin>>input3;
                    switch (input3) {
                        case 1 : {
                            redNacional.agregarEstacion();
                            cout<<"\nEstacion agregada.\n";
                            break;
                        }
                        case 2 : {
                            int index = elegirEstacion(redNacional);
                            string codigo = redNacional.getEstaciones()[index].getCodigo();
                            redNacional.eliminarEstacion(codigo);
                            break;
                        }
                        case 3 : {
                            fijarPrecios(redNacional);
                            break;
                        }
                        case 4 : {
                            redNacional.reporteVentas(registros);
                            break;
                        }
                        case 5 : {
                            int index = elegirEstacion(redNacional);
                            estacion miEstacion = redNacional.getEstaciones()[index];
                            cout<<"\nEstacion "<<miEstacion.getNombre()<<endl;
                            cout<<"\nDigite: \n(1) Modificar estacion\n(2) Agregar surtidor\n(3) Eliminar surtidor\n(4) Activar/desactivar surtidor\n(5) Consultar historial de ventas\n(6) Reporte de litros vendidos\n(7) Simular venta\n(8) Verificar fugas\n(#) Salir\n-> ";
                            int input4;
                            cin>>input4;
                            switch (input4) {
                                case 1 : {
                                    //modificarEstacion(miEstacion);
                                    break;
                                }
                                case 2 : {
                                    miEstacion.agregarSurtidor();
                                    break;
                                }
                                case 3 : {
                                    string codigo = elegirSurtidor(miEstacion);
                                    miEstacion.eliminarSurtidor(codigo);
                                    break;
                                }
                                case 4 : {
                                    string codigo = elegirSurtidor_(miEstacion);
                                    miEstacion.activarDesactivarSurtidor(codigo);
                                    break;
                                }
                                case 5 : {
                                    miEstacion.consultarHistorico(registros);
                                    break;
                                }
                                case 6 : {
                                    miEstacion.reporteLitros(registros);
                                    break;
                                }
                                case 7 : {
                                    miEstacion.simularVenta(registros);
                                    break;
                                }
                                case 8 : {
                                    miEstacion.verificarFugas(registros);
                                    break;
                                }
                                default : {
                                    break;
                                }
                            }
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
