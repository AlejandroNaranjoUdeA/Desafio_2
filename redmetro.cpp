#include "redmetro.h"
#include <iostream>

RedMetro::RedMetro() {
    cantidadLineas = 0;
    lineas = new Linea*[50]; // Capacidad inicial,
}

void RedMetro::agregarLinea(Linea* linea) {
    if (cantidadLineas < 50) {
        lineas[cantidadLineas] = linea;
        cantidadLineas++;
    } else {
        std::cout << "Error: Capacidad máxima alcanzada." << std::endl;
    }
}

void RedMetro::eliminarLinea(std::string nombre) {
    for (int i = 0; i < cantidadLineas; i++) {
        if (lineas[i]->getNombreLinea() == nombre) {
            delete lineas[i];
            for (int j = i; j < cantidadLineas - 1; j++) {
                lineas[j] = lineas[j + 1];
            }
            cantidadLineas--;
            return;
        }
    }
    std::cout << "Error: Línea no encontrada." << std::endl;
}

int RedMetro::obtenerCantidadLineas() {
    return cantidadLineas;
}

Linea** RedMetro::getLineas() {
    return lineas;
}

int RedMetro::getCantidadLineas() {
    return cantidadLineas;
}
