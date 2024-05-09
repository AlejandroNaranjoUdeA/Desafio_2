
#include "linea.h"
#include <iostream>

Linea::Linea(string nombre) {
    nombreLinea = nombre;
    cantidadEstaciones = 0;
    estaciones = new Estacion*[100]; // Capacidad inicial
}
//destructor::
Linea::~Linea() {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;
}
string Linea::obtenerNombre() const {
    return nombreLinea;
}
//caso 1
void Linea::agregarEstacionAlPrincipio(Estacion* estacion) {
    if (cantidadEstaciones < 100) {
        for (int i = cantidadEstaciones; i > 0; --i) {
            estaciones[i] = estaciones[i - 1];
        }
        estaciones[0] = estacion;
        cantidadEstaciones++;
    } else {
        cout << "Error: Capacidad máxima alcanzada." << endl;
    }
}

void Linea::agregarEstacionEnPosicion(Estacion* estacion, int posicion) {
    if (cantidadEstaciones < 100 && posicion >= 0 && posicion <= cantidadEstaciones) {
        for (int i = cantidadEstaciones; i > posicion; --i) {
            estaciones[i] = estaciones[i - 1];
        }
        estaciones[posicion] = estacion;
        cantidadEstaciones++;
    } else {
        cout << "Error: Posición inválida o capacidad máxima alcanzada." << endl;
    }
}




bool Linea::perteneceEstacion(const std::string& nombreEstacion) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->getnombreEstacion() == nombreEstacion) {
            return true;
        }
    }
    return false;
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

void Linea::mostrarEstacionesDisponibles(const std::string& nombreLinea) {
    std::cout << "Estaciones disponibles en la linea " << nombreLinea << ":" << std::endl;
    for (int i = 0; i < cantidadEstaciones; ++i) {
        std::cout << "- " << estaciones[i]->getnombreEstacion() << std::endl;
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
