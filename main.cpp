1#include "estaciones.h"
#include "linea.h"
#include "redmetro.h"
#include <iostream>
#include "estacionnormal.h"
#include "estaciontransferencia.h"

int main() {
    RedMetro* redMetro = new RedMetro(); // Crear una instancia de RedMetro
    unsigned int opcion = 0;
    std::string nombreLinea;
    std::string nombreEstacion;
    //Se le muestra al usuario un mensaje y un menu:
    std::cout<<"!!!BIENVENIDO A SU RED METRO!!!\n";
    std::cout<<"Nota: Como es la primera vez, tu unica opcion es agregar una linea a la red metro\n\n";

    std::cout<<"1. Agregar una linea a la red Metro.\n";
    std::cout<<"2. Salir.\n";
    std::cout<<"Eliga una opcion: "; std::cin>>opcion;

    if(opcion==1){
        opcion = 6;
    }
    else{
        opcion = 9;
    }

    Linea* nuevaLinea = nullptr; // Declarar la variable fuera del switch
    int cantidadEstacionesRed = 0; // Declarar e inicializar la variable fuera del switch
    Estacion* nuevaEstacion;

    while(opcion<10){

        switch(opcion){
        case 1:
            int opcionAgregarEstacion;
            int tiempoSiguiente, tiempoAnterior;
            bool esTransferencia;

            std::cout << "1. Agregar estacion al inicio\n";
            std::cout << "2. Agregar estacion al final\n";
            std::cout << "3. Agregar estacion en posicion intermedia\n";
            std::cout << "Elige una opcion: "; std::cin >> opcionAgregarEstacion;

            std::cout << "Nombre de la estacion: "; std::cin >> nombreEstacion;
            std::cout << "Tiempo siguiente: "; std::cin >> tiempoSiguiente;
            std::cout << "Tiempo anterior: "; std::cin >> tiempoAnterior;
            std::cout << "Es estacion de transferencia (1 para Si, 0 para No): "; std::cin >> esTransferencia;

            if (esTransferencia) {
                nuevaEstacion = new EstacionTransferencia(nombreEstacion, tiempoSiguiente, tiempoAnterior);
            } else {
                nuevaEstacion = new EstacionNormal(nombreEstacion, tiempoSiguiente, tiempoAnterior);
            }
            // Mostrar todas las líneas disponibles para que el usuario elija a qué línea agregar la estación
            std::cout << "Lineas disponibles:\n";
            for (int i = 0; i < redMetro->getCantidadLineas(); ++i) {
                std::cout << i+1 << ". " << redMetro->getLineas()[i]->obtenerNombre() << std::endl;
            }

            int opcionLinea;
            std::cout << "Elige la linea a la que deseas agregar la estacion: "; std::cin >> opcionLinea;
            if (opcionLinea >= 1 && opcionLinea <= redMetro->getCantidadLineas()) {
                Linea* lineaSeleccionada = redMetro->getLineas()[opcionLinea - 1];
                switch (opcionAgregarEstacion) {
                case 1:
                    lineaSeleccionada->agregarEstacionAlPrincipio(nuevaEstacion);
                    break;
                case 2:
                    lineaSeleccionada->agregarEstacion(nuevaEstacion);
                    break;
                case 3:
                    int posicion;
                    std::cout << "Posicion intermedia para agregar la estacion: "; std::cin >> posicion;
                    lineaSeleccionada->agregarEstacionEnPosicion(nuevaEstacion, posicion);
                    break;
                default:
                    std::cout << "Opcion no valida." << std::endl;
                    break;
                }
            } else {
                std::cout << "Opcion de linea no valida." << std::endl;
            }
            break;

        case 2:{
            Linea** lineas = redMetro->getLineas();
            redMetro->mostrarLineasDisponibles();

            cout << "Ingrese el nombre de la linea que desea ver sus estaciones para eliminar una: ";
            std::string nombreLinea;
            cin >> nombreLinea;
            // Buscar la línea con el nombre proporcionado
            Linea* lineaSeleccionada = nullptr;
            for (int i = 0; i < redMetro->obtenerCantidadLineas(); ++i) {
                if (lineas[i]->obtenerNombre() == nombreLinea) {
                    lineaSeleccionada = lineas[i];
                    break;
                }
            }
            if (lineaSeleccionada != nullptr) {
                // Mostrar las estaciones de la línea seleccionada
                lineaSeleccionada->mostrarEstacionesDisponibles(nombreLinea);
                string estaciondes;
                cout<<"ingrese el nombre de la estacion a borar de la linea"<<endl;
                cin>>estaciondes;
                lineaSeleccionada->eliminarEstacion(estaciondes);
            } else {
                cout << "La línea ingresada no existe." << endl;
            };
            break;
        }

        case 3:
            cout << "Cantidad de lineas en la red de metro: " << redMetro->obtenerCantidadLineas() << endl;
            break;

        case 4:{
            Linea** lineas = redMetro->getLineas();
            redMetro->mostrarLineasDisponibles();

            cout << "Ingrese el nombre de la linea que desea ver sus estaciones: ";
            std::string nombreLinea;
            cin >> nombreLinea;

            // Buscar la línea con el nombre proporcionado
            Linea* lineaSeleccionada = nullptr;
            for (int i = 0; i < redMetro->obtenerCantidadLineas(); ++i) {
                if (lineas[i]->obtenerNombre() == nombreLinea) {
                    lineaSeleccionada = lineas[i];
                    break;
                }
            }

            if (lineaSeleccionada != nullptr) {
                // Mostrar las estaciones de la línea seleccionada
                lineaSeleccionada->mostrarEstacionesDisponibles(nombreLinea);
            } else {
                cout << "La línea ingresada no existe." << endl;
            }
            break;
        }


        case 5:
            std::cout << "Ingrese el nombre de la estacion: "; std::cin >> nombreEstacion;
            std::cout << "Ingrese el nombre de la linea: "; std::cin >> nombreLinea;
            // Verificar si la estacion pertenece a la linea especifica
            if (redMetro->getCantidadLineas() > 0) {
                Linea** lineas = redMetro->getLineas();
                bool encontrada = false;
                for (int i = 0; i < redMetro->getCantidadLineas(); ++i) {
                    if (lineas[i]->obtenerNombre() == nombreLinea) {
                        encontrada = lineas[i]->perteneceEstacion(nombreEstacion);
                        break;
                    }
                }
                if (encontrada) {
                    std::cout << "La estacion " << nombreEstacion << " pertenece a la linea " << nombreLinea << std::endl;
                } else {
                    std::cout << "La estacion " << nombreEstacion << " no pertenece a la linea " << nombreLinea << std::endl;
                }
            } else {
                std::cout << "No hay lineas en la red de metro.\n";
            }
            break;

        case 6:
            std::cout << "Ingrese el nombre de la linea: "; std::cin >> nombreLinea;
            nuevaLinea = new Linea(nombreLinea);
            redMetro->agregarLinea(nuevaLinea);
            std::cout << "Linea agregada correctamente.\n";
            break;

        case 7:{
            cout << "Cantidad de lineas en la red de metro: " << redMetro->obtenerCantidadLineas() << endl;
            redMetro->mostrarLineasDisponibles();
            string nume;
            cout<<"escribe el nombre de la linea que quierres borrar"<<endl;
            cin>>nume;
            redMetro->eliminarLineaPorNombre(nume);
            break;

        }
        case 8:
            // Obtener la cantidad total de estaciones en la red Metro
            for (int i = 0; i < redMetro->getCantidadLineas(); i++) {
                Linea* linea = redMetro->getLineas()[i];
                cantidadEstacionesRed += linea->obtenerCantidadEstaciones();
                // Restar una estación por cada estación de transferencia para evitar contarlas dos veces
                for (int j = 0; j < linea->obtenerCantidadEstaciones(); ++j) {
                    if (linea->getEstaciones()[j]->esEstacionTransferencia()) {
                        cantidadEstacionesRed--;
                    }
                }
            }
            std::cout << "La red de metro tiene en total " << cantidadEstacionesRed << " estaciones.\n";

            break;

        case 9:{
            // Obtener las estaciones relevantes de la línea
            string lineacal,estacione, estacionf;

            cout<<"ingrese la linea de las estaciones para calcular el tiempo de llegada"<<endl;
            cin>>lineacal;
            cout<<"ingrese la estacion de partida "<<endl;
            cin>>estacione;
            cout<<"ingrese la estacion de destino"<<endl;
            cin>>estacionf;
            Estacion** estaciones = redMetro->getEstacionesDeLinea(lineacal);
            // Encontrar las posiciones de las estaciones que se quieren comparar en la línea
            int posicionEstacionA = redMetro->getPosicionEstacionEnLinea(estacione, lineacal);
            int posicionEstacionB = redMetro->getPosicionEstacionEnLinea(estacionf, lineacal);

            // Obtener la hora actual como tiempo de salida
            std::time_t tiempoActual = std::time(nullptr);
            std::tm tiempoSalida = *std::localtime(&tiempoActual);

            // Inicializar el tiempo total de viaje con los tiempos de viaje entre las estaciones
            int tiempoTotalViaje = 0;

            // Sumar los tiempos de espera entre las estaciones relevantes
            for (int i = posicionEstacionA; i < posicionEstacionB; ++i) {
                tiempoTotalViaje += estaciones[i]->getTiempoSiguiente();
            }

            // Calcular el tiempo de llegada a la estación C desde la estación A
            std::tm tiempoLlegada = estaciones[posicionEstacionA]->calcularTiempoLlegada(tiempoSalida, tiempoTotalViaje);

            // Imprimir el tiempo de salida y llegada
            std::cout << "Hora de salida: " << tiempoSalida.tm_hour << ":" << tiempoSalida.tm_min << ":" << tiempoSalida.tm_sec << std::endl;
            std::cout << "Hora de llegada estimada: " << tiempoLlegada.tm_hour << ":" << tiempoLlegada.tm_min << ":" << tiempoLlegada.tm_sec << std::endl;
            break;

        }
        default:
            std::cout<<"\nOpcion no valida!!\n";
            break;

        }

        // Liberar memoria de nuevaEstacion si fue creada dinámicamente
        if (nuevaEstacion != nullptr) {
            delete nuevaEstacion;
            nuevaEstacion = nullptr; // Establecer a nullptr después de eliminarla
        }


        std::cout<<"\n\n1. Agregar una estacion a una linea, en los extremos o en posiciones intermedias.\n";
        std::cout<<"2. Eliminar una estacion de una linea.\n";
        std::cout<<"3. Saber cuantas lineas tiene la red Metro.\n";
        std::cout<<"4. Saber cuantas estaciones tiene una linea dada.\n";
        std::cout<<"5. Saber si una estacion dada pertenece a una linea especifica.\n";
        std::cout<<"6. Agregar una linea a la red Metro.\n";
        std::cout<<"7. Eliminar una linea de la red Metro. \n";
        std::cout<<"8. Saber cuantas estaciones tiene una red Metro.\n";
        std::cout<<"9. saber el tiempo que tomara llegar de una estacion a otra dependiendo la linea"<<std::endl;
        std::cout<<"10. Salir.\n";
        std::cout<<"Eliga una opcion: "; std::cin>>opcion;
    }


    // Liberar la memoria al finalizar

    delete redMetro;
    delete nuevaLinea;


    return 0;
}

