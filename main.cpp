#include "estaciones.h"
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


    while(opcion<9){

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

            Estacion* nuevaEstacion;
            if (esTransferencia) {
                nuevaEstacion = new EstacionTransferencia(nombreEstacion, tiempoSiguiente, tiempoAnterior);
            } else {
                nuevaEstacion = new EstacionNormal(nombreEstacion, tiempoSiguiente, tiempoAnterior);
            }

            switch (opcionAgregarEstacion) {
            case 1:
                // Agregar estacion al inicio de la linea
                if (redMetro->getCantidadLineas() > 0) {
                    Linea* primeraLinea = redMetro->getLineas()[0]; // Supongo que se agrega a la primera linea, puedes adaptarlo según tu lógica
                    primeraLinea->agregarEstacionAlPrincipio(nuevaEstacion);
                } else {
                    std::cout << "No hay lineas en la red de metro para agregar la estacion." << std::endl;
                }
                break;
            case 2:
                // Agregar estacion al final de la linea
                if (redMetro->getCantidadLineas() > 0) {
                    Linea* primeraLinea = redMetro->getLineas()[0]; // Supongo que se agrega a la primera linea, puedes adaptarlo según tu lógica
                    primeraLinea->agregarEstacion(nuevaEstacion);
                } else {
                    std::cout << "No hay lineas en la red de metro para agregar la estacion." << std::endl;
                }
                break;
            case 3:
                // Agregar estacion en posicion intermedia
                int posicion;
                std::cout << "Posicion intermedia para agregar la estacion: "; std::cin >> posicion;
                if (redMetro->getCantidadLineas() > 0) {
                    Linea* primeraLinea = redMetro->getLineas()[0]; // Supongo que se agrega a la primera linea, puedes adaptarlo según tu lógica
                    primeraLinea->agregarEstacionEnPosicion(nuevaEstacion, posicion);
                } else {
                    std::cout << "No hay lineas en la red de metro para agregar la estacion." << std::endl;
                }
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
            }
            break;
/*
        case 2:
            //mostrar lineas:
            break;
        case 3:
            break;
        case 4:
            break;

*/
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
/*
        case 7:
            break;
*/
        case 8:

            // Obtener la cantidad total de estaciones en la red Metro
            for (int i = 0; i < redMetro->getCantidadLineas(); ++i) {
                cantidadEstacionesRed += redMetro->getLineas()[i]->obtenerCantidadEstaciones();
            }
            std::cout << "La red de metro tiene en total " << cantidadEstacionesRed << " estaciones.\n";
            break;
/*
        case 9:
            break;
*/
        default:
            std::cout<<"\nOpcion no valida!!\n";
            break;

        }


        std::cout<<"\n\n1. Agregar una estacion a una linea, en los extremos o en posiciones intermedias.\n";
        std::cout<<"2. Eliminar una estacion de una linea.\n";
        std::cout<<"3. Saber cuantas lineas tiene la red Metro.\n";
        std::cout<<"4. Saber cuantas estaciones tiene una linea dada.\n";
        std::cout<<"5. Saber si una estacion dada pertenece a una linea especifica.\n";
        std::cout<<"6. Agregar una linea a la red Metro.\n";
        std::cout<<"7. Eliminar una linea de la red Metro. \n";
        std::cout<<"8. Saber cuantas estaciones tiene una red Metro.\n";
        std::cout<<"9. Salir.\n";
        std::cout<<"Eliga una opcion: "; std::cin>>opcion;

    }

/*
    EstacionNormal estacionNormal("Estacion Normalll", 10, 20);
    EstacionTransferencia estacionTransferencia("Estacion de Transferencia", 15, 25);

    // Polimorfismo
    Estacion* ptrEstacion1 = &estacionNormal;
    Estacion* ptrEstacion2 = &estacionTransferencia;

    std::cout << ptrEstacion1-> getnombreEstacion() << " es estacion de transferencia: " << ptrEstacion1->esEstacionTransferencia() << std::endl;
    std::cout << ptrEstacion2-> getnombreEstacion() << " es estacion de transferencia: " << ptrEstacion2->esEstacionTransferencia() << std::endl;


    // Crear una linea y agregar estaciones a la línea
    Linea* linea1 = new Linea("Linea1");
    Linea* linea5 = new Linea("Linea5");
    linea1->agregarEstacion(ptrEstacion1);
    linea1->agregarEstacion(ptrEstacion2);



    // Crear una red de metro y agregar la linea a la red
    RedMetro* redMetro = new RedMetro();
    redMetro->agregarLinea(linea1);
    redMetro->agregarLinea(linea5);


    // Mostrar la cantidad de lineas en la red
    cout << "Cantidad de lineas en la red de metro: " << redMetro->obtenerCantidadLineas() << endl;
    redMetro->eliminarLineaPorNombre("Linea1");
    cout << "Cantidad de lineas en la red de metro: " << redMetro->obtenerCantidadLineas() << endl;
    cout<<endl;



    // Mostrar el nombre de la primera estación de la primera línea
    if (redMetro->getCantidadLineas() > 0 && redMetro->getLineas()[0]->obtenerCantidadEstaciones() > 0) {
        cout << "Nombre de la primera estacion de la primera linea: " << redMetro->getLineas()[0]->getEstaciones()[0]->getnombreEstacion() << endl;
    }
    cout<<"hola al mundo"<<endl;

    if (redMetro->getCantidadLineas() > 0) {
        Linea* primeraLinea = redMetro->getLineas()[0]; // Obtener la primera línea de la red de metro aqui es donde hay que tantear
        int cantidadEstaciones = primeraLinea->obtenerCantidadEstaciones();
        cout << "las cantidad de estaciones de la linea seleccionada es "<< cantidadEstaciones << " estaciones." << endl;
    } else {
        cout << "No hay líneas en la red de metro." << endl;
    }

    linea1->mostrarEstacionesDisponibles();
    // Suponiendo que tienes una instancia de Linea llamada "linea1" creada previamente
    linea1->eliminarEstacion("Estacion de Transferencia");
    linea1->mostrarEstacionesDisponibles();






*/


    // Liberar la memoria al finalizar

    delete redMetro;



    return 0;
}
