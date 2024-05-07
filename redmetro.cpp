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
        cout << "Error: Capacidad máxima alcanzada." << endl;
    }
}

void RedMetro::eliminarLineaPorNombre(const std::string& nombreLinea) {
    // Busca el nombre de la línea
    int indiceLineaEliminar = -1;
    for (int i = 0; i < cantidadLineas; ++i) {
        if (lineas[i]->obtenerNombre() == nombreLinea) {
            indiceLineaEliminar = i;
            break;
        }
    }
    if (indiceLineaEliminar != -1) {
        // Verificar si la línea tiene estaciones de transferencia
        bool tieneTransferencia = false;
        Estacion** estaciones = lineas[indiceLineaEliminar]->getEstaciones();
        int cantidadEstaciones = lineas[indiceLineaEliminar]->obtenerCantidadEstaciones();
        for (int i = 0; i < cantidadEstaciones; ++i) {
            if (estaciones[i]->esEstacionTransferencia()) { // Aquí se llama al método correcto
                tieneTransferencia = true;
                break;
            }
        }

        if (!tieneTransferencia) {
            cout << "Eliminando la linea " << nombreLinea << endl;
            delete lineas[indiceLineaEliminar];
            for (int i = indiceLineaEliminar; i < cantidadLineas - 1; ++i) {
                lineas[i] = lineas[i + 1];
            }
            --cantidadLineas;
        } else {
            cout << "No se puede eliminar la linea " << nombreLinea << " porque contiene estaciones de transferencia." << endl;
        }
    } else {
        cout << "No se encontró la línea " << nombreLinea << endl;
    }
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
