#include "redmetro.h"
#include <iostream>

RedMetro::RedMetro() {
    cantidadLineas = 0;
    lineas = new Linea*[50]; // Capacidad inicial,
}
RedMetro::~RedMetro() {
    for (int i = 0; i < cantidadLineas; ++i) {
        delete lineas[i];
    }
    delete[] lineas;
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
        cout << "No se encontro la linea " << nombreLinea << endl;
    }
}
void RedMetro::mostrarLineasDisponibles() {
    std::cout << "Lineas disponibles en la red de metro:" << std::endl;
    for (int i = 0; i < cantidadLineas; ++i) {
        std::cout << "- " << lineas[i]->obtenerNombre() << std::endl;
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
Estacion** RedMetro::getEstacionesDeLinea(const std::string& nombreLinea) {
    for (int i = 0; i < cantidadLineas; ++i) {
        if (lineas[i]->obtenerNombre() == nombreLinea) {
            return lineas[i]->getEstaciones();
        }
    }
    return nullptr; // Si no se encuentra la línea
}

int RedMetro::getPosicionEstacionEnLinea(const std::string& nombreEstacion, const std::string& nombreLinea) {
    Estacion** estacionesDeLinea = getEstacionesDeLinea(nombreLinea);
    if (estacionesDeLinea) {
        for (int i = 0; estacionesDeLinea[i] != nullptr; ++i) {
            if (estacionesDeLinea[i]->getnombreEstacion() == nombreEstacion) {
                return i;
            }
        }
    }
    return -1; // Si no se encuentra la estación en la línea
}

