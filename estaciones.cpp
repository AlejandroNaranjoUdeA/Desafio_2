#include "estaciones.h"


Estacion::Estacion(const std::string& nombre, int tiempoSiguiente, int tiempoAnterior, bool transferencia)
    : nombreEstacion(nombre), tiempoSiguiente(tiempoSiguiente), tiempoAnterior(tiempoAnterior), esTransferencia(transferencia) {}

Estacion::~Estacion() {}

bool Estacion::esEstacionTransferencia() const {
    return esTransferencia;
}

std::string Estacion::getnombreEstacion() {
    return nombreEstacion;
}

void Estacion::setnombreEstacion(string nombre) {
    nombreEstacion = nombre;
}

int Estacion::getTiempoSiguiente() {
    return tiempoSiguiente;
}

void Estacion::setTiempoSiguiente(int tiempo) {
    tiempoSiguiente = tiempo;
}

int Estacion::getTiempoAnterior() {
    return tiempoAnterior;
}

void Estacion::setTiempoAnterior(int tiempo) {
    tiempoAnterior = tiempo;
}


