#include "redmetro.h"

RedMetro::RedMetro()
{
    cantidadLineas = 0;
    lineas = new Linea*[50]; // Capacidad inicial, puedes ajustarla según necesites
}

void RedMetro::agregarLinea(Linea* linea) {
    if (cantidadLineas < 50) {
        lineas[cantidadLineas] = linea;
        cantidadLineas++;
    } else {
        cout << "Error: Capacidad máxima alcanzada." << endl;
    }
}

void RedMetro::eliminarLinea(string nombre) {
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
    cout << "Error: Línea no encontrada." << endl;
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
