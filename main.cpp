#include "estaciones.h"
#include "linea.h"
#include "redmetro.h"
#include <iostream>

int main() {
    // Crear algunas estaciones
    Estacion* estacion1 = new Estacion("Estacion1", 10, 10, false);
    Estacion* estacion2 = new Estacion("Estacion2", 15, 15, false);
    Estacion* estacion3 = new Estacion("Estacion3", 20, 20, true);

    // Crear una linea y agregar estaciones a la línea
    Linea* linea1 = new Linea("Linea1");
    linea1->agregarEstacion(estacion1);
    linea1->agregarEstacion(estacion2);
    linea1->agregarEstacion(estacion3);

    // Crear una red de metro y agregar la linea a la red
    RedMetro* redMetro = new RedMetro();
    redMetro->agregarLinea(linea1);

    // Mostrar la cantidad de lineas en la red
    std::cout << "Cantidad de lineas en la red de metro: " << redMetro->obtenerCantidadLineas() << std::endl;

    // Mostrar el nombre de la primera estación de la primera línea
    if (redMetro->getCantidadLineas() > 0 && redMetro->getLineas()[0]->obtenerCantidadEstaciones() > 0) {
        std::cout << "Nombre de la primera estacion de la primera linea: " << redMetro->getLineas()[0]->getEstaciones()[0]->getnombreEstacion() << std::endl;
    }
    std::cout<<"hol"<<std::endl;

    // Liberar la memoria al finalizar
    delete redMetro;
    delete linea1;
    delete estacion3;
    delete estacion2;
    delete estacion1;

    return 0;
}
