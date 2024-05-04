#include "linea.h"

//Implementacion del constructor y de los metodos de la clase linea
Linea::Linea(string nombre) {
    nombreLinea = nombre;
    cantidadEstaciones = 0;
    estaciones = new Estacion*[100]; // Capacidad inicial
}

void Linea::agregarEstacion(Estacion* estacion) {
    if (cantidadEstaciones < 100) {
        estaciones[cantidadEstaciones] = estacion;
        cantidadEstaciones++;
    } else {
        cout << "Error: Capacidad máxima alcanzada." << endl;
    }
}

void Linea::eliminarEstacion(string nombre) {
    for (int i = 0; i < cantidadEstaciones; i++) {
        if (estaciones[i]->getNombreEstacion() == nombre) {
            delete estaciones[i];
            for (int j = i; j < cantidadEstaciones - 1; j++) {
                estaciones[j] = estaciones[j + 1];
            }
            cantidadEstaciones--;
            return;
        }
    }
    cout << "Error: Estación no encontrada." << endl;
}

int Linea::obtenerCantidadEstaciones() {
    return cantidadEstaciones;
}

string Linea::getNombreLinea() {
    return nombreLinea;
}

void Linea::setNombreLinea(string nombre) {
    nombreLinea = nombre;
}

Estacion** Linea::getEstaciones() {
    return estaciones;
}

int Linea::getCantidadEstaciones() {
    return cantidadEstaciones;
}
