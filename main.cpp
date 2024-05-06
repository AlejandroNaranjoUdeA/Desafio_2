#include "estaciones.h"
#include "linea.h"
#include "redmetro.h"
#include <iostream>
#include "estacionnormal.h"
#include "estaciontransferencia.h"



int main() {
    EstacionNormal estacionNormal("Estacion Normal", 10, 20);
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

    // Mostrar el nombre de la primera estación de la primera línea
    if (redMetro->getCantidadLineas() > 0 && redMetro->getLineas()[0]->obtenerCantidadEstaciones() > 0) {
        cout << "Nombre de la primera estacion de la primera linea: " << redMetro->getLineas()[0]->getEstaciones()[0]->getnombreEstacion() << endl;
    }
    cout<<"hola al mundo"<<endl;

    // Liberar la memoria al finalizar
    delete redMetro;
    delete linea1;

    delete linea5;


    return 0;
}
