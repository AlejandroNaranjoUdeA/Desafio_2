#ifndef ESTACIONTRANSFERENCIA_H
#define ESTACIONTRANSFERENCIA_H


#include "estaciones.h"

class EstacionTransferencia : public Estacion {
public:
    EstacionTransferencia(const string& nombre, int tiempoSiguiente, int tiempoAnterior);
    virtual ~EstacionTransferencia();

    virtual bool esEstacionTransferencia() const override;
};

#endif // ESTACIONTRANSFERENCIA_H
