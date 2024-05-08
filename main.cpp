#include "estaciones.h"
#include "linea.h"
#include "redmetro.h"
#include <iostream>
#include "estacionnormal.h"
#include "estaciontransferencia.h"


int main() {
    Estacion** estaciones = nullptr;
    int numEstaciones;

    std::cout << "Ingrese el numero de estaciones: ";
    std::cin >> numEstaciones;

    estaciones = new Estacion*[numEstaciones];

    for (int i = 0; i < numEstaciones; ++i) {
        std::string nombreEstacion;
        int tiempoSiguiente, tiempoAnterior;
        bool esTransferencia;

        std::cout << "Ingrese el nombre de la estacion " << i + 1 << ": ";
        std::cin >> nombreEstacion;
        std::cout << "Ingrese el tiempo siguiente para la estacion " << nombreEstacion << ": ";
        std::cin >> tiempoSiguiente;
        std::cout << "Ingrese el tiempo anterior para la estacion " << nombreEstacion << ": ";
        std::cin >> tiempoAnterior;
        std::cout << "La estacion " << nombreEstacion << " es de transferencia? (0 = No, 1 = Si): ";
        std::cin >> esTransferencia;

        if (esTransferencia) {
            estaciones[i] = new EstacionTransferencia(nombreEstacion, tiempoSiguiente, tiempoAnterior);
        } else {
            estaciones[i] = new EstacionNormal(nombreEstacion, tiempoSiguiente, tiempoAnterior);
        }
    }

    // Polimorfismo
    for (int i = 0; i < numEstaciones; ++i) {
        std::cout << estaciones[i]->getnombreEstacion() << " es estacion de transferencia: " << estaciones[i]->esEstacionTransferencia() << std::endl;
    }

    // Obtener la hora actual como tiempo de salida
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* tiempoSalida = std::localtime(&tiempoActual);
    int tiempoSiguiente=150;
    int tiempoAnterior=150;

    // Definir el tiempo de viaje entre las estaciones (en segundos)
    int tiempoViaje = 300; // Por ejemplo, 5 minutos

    // Crear una instancia de Estacion con los datos apropiados
    Estacion tiempo("Nombre", tiempoSiguiente, tiempoAnterior, true);

    // Calcular el tiempo de llegada a una estación específica
    std::tm tiempoLlegada = tiempo.calcularTiempoLlegada(*tiempoSalida, tiempoViaje);

    // Imprimir el tiempo de salida y llegada
    std::cout << "Hora de salida: " << tiempoSalida->tm_hour << ":" << tiempoSalida->tm_min << ":" << tiempoSalida->tm_sec << std::endl;
    std::cout << "Hora de llegada estimada: " << tiempoLlegada.tm_hour << ":" << tiempoLlegada.tm_min << ":" << tiempoLlegada.tm_sec << std::endl;


    // Liberar la memoria al finalizar
    for (int i = 0; i < numEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;

    return 0;
}

/**
int main() {
    EstacionNormal estacionNormal("Estacion Normalll", 10, 20);
    EstacionTransferencia estacionTransferencia("Estacion de Transferencia", 15, 25);

    // Polimorfismo
    Estacion* ptrEstacion1 = &estacionNormal;
    Estacion* ptrEstacion2 = &estacionTransferencia;

    std::cout << ptrEstacion1-> getnombreEstacion() << " es estacion de transferencia: " << ptrEstacion1->esEstacionTransferencia() << std::endl;
    std::cout << ptrEstacion2-> getnombreEstacion() << " es estacion de transferencia: " << ptrEstacion2->esEstacionTransferencia() << std::endl;


    // Crear una linea y agregar estaciones a la línea
    Linea* linea1 = new Linea("Linea1");
    Linea* linea5= new Linea("Linea5");
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




    // Liberar la memoria al finalizar
    delete redMetro;
    delete linea1;

    delete linea5;


    return 0;
}
**/
