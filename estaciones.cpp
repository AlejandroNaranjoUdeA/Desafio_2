
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

std::tm Estacion::calcularTiempoLlegada(const std::tm& tiempoSalida, int tiempoViaje) const {
    std::tm tiempoLlegada = tiempoSalida;
    tiempoLlegada.tm_sec += tiempoViaje;
    std::mktime(&tiempoLlegada); // Ajustar la estructura de tiempo

    return tiempoLlegada;
}
