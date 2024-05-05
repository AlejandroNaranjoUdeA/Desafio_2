#include "estaciones.h"


Estacion::Estacion(std::string nombre, int siguiente, int anterior, bool transferencia) {
    nombreEstacion = nombre;
    tiempoSiguiente = siguiente;
    tiempoAnterior = anterior;
    esTransferencia = transferencia;
}

bool Estacion::Transferencia() {
    return esTransferencia;
}

std::string Estacion::getnombreEstacion() {
    return nombreEstacion;
}

void Estacion::setnombreEstacion(std::string nombre) {
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

bool Estacion::getEsTransferencia() {
    return esTransferencia;
}

void Estacion::setEsTransferencia(bool transferencia) {
    esTransferencia = transferencia;
}
