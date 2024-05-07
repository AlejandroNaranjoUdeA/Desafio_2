#include "linea.h"

#include <iostream>

Linea::Linea(string nombre) {
    nombreLinea = nombre;
    cantidadEstaciones = 0;
    estaciones = new Estacion*[100]; // Capacidad inicial
}

string Linea::obtenerNombre() const {
    return nombreLinea;
}

void Linea::agregarEstacion(Estacion* estacion) {
    if (cantidadEstaciones < 100) {
        estaciones[cantidadEstaciones] = estacion;
        cantidadEstaciones++;
    } else {
        cout << "Error: Capacidad máxima alcanzada." << endl;
    }
}
bool Linea::esEstacionTransferencia(const std::string& nombreEstacion) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getnombreEstacion() == nombreEstacion) {
            return estaciones[i]->esEstacionTransferencia(); // Utilizamos el método virtual para determinar si es estación de transferencia
        }
    }
    // Si no se encontró la estación, podrías lanzar una excepción o manejarlo según tus necesidades
    return false; // O podrías lanzar una excepción para indicar que la estación no se encontró
}

void Linea::eliminarEstacion(const std::string& nombreEstacion) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getnombreEstacion() == nombreEstacion) {

            if (esEstacionTransferencia(nombreEstacion)) {
                cout << "No se puede borrar la estacion de transferencia: " << nombreEstacion << endl;
            } else {
                delete estaciones[i]; // Liberar la memoria de la estación
                for (int j = i; j < cantidadEstaciones - 1; ++j) {
                    estaciones[j] = estaciones[j + 1];
                }
                --cantidadEstaciones;
                cout << "Estacion " << nombreEstacion << " eliminada correctamente." << endl;
            }
            return;
        }
    }
    cout << "La estacion " << nombreEstacion << " no se encontro en la linea." << endl;
}
void Linea::mostrarEstacionesDisponibles() {
    cout << "Estaciones disponibles en la linea:" << endl;
    for (int i = 0; i < cantidadEstaciones; ++i) {
        cout << "- " << estaciones[i]->getnombreEstacion() << endl;
    }
}

int Linea::obtenerCantidadEstaciones() {
    return cantidadEstaciones;
}

std::string Linea::getNombreLinea() {
    return nombreLinea;
}

void Linea::setNombreLinea(std::string nombre) {
    nombreLinea = nombre;
}

Estacion** Linea::getEstaciones() {
    return estaciones;
}

int Linea::getCantidadEstaciones() {
    return cantidadEstaciones;
}
