#include "estaciones.h"

//implementacion del constructro y de los metodos de la clase estaciones:
Estaciones::Estaciones(string nombre, int siguiente, int anterior, bool transferencia)
{
    nombreEstacion = nombre;
    tiempoSiguiente = siguiente;
    tiempoAnterior = anterior;
    esTransferencia = transferencia;
}

bool Estacion::esTransferencia() {
    return esTransferencia;
}

string Estacion::getNombreEstacion() {
    return nombreEstacion;
}

void Estacion::setNombreEstacion(string nombre) {
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

