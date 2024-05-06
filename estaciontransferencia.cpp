#include "estaciontransferencia.h"

EstacionTransferencia::EstacionTransferencia(const string& nombre, int tiempoSiguiente, int tiempoAnterior)
    : Estacion(nombre, tiempoSiguiente, tiempoAnterior, true) {}

EstacionTransferencia::~EstacionTransferencia() {}

bool EstacionTransferencia::esEstacionTransferencia() const {
    return true; // Estación de transferencia siempre es una estación de transferencia
}
