
#include "estacionnormal.h"

EstacionNormal::EstacionNormal(const string& nombre, int tiempoSiguiente, int tiempoAnterior)
    : Estacion(nombre, tiempoSiguiente, tiempoAnterior, false) {}

EstacionNormal::~EstacionNormal() {}

bool EstacionNormal::esEstacionTransferencia() const {
    return false; // Estación normal nunca es una estación de transferencia
}
