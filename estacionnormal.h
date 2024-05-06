// Archivo estacionnormal.h
#ifndef ESTACIONNORMAL_H
#define ESTACIONNORMAL_H
#include "estaciones.h"

class EstacionNormal : public Estacion {
public:
    EstacionNormal(const string& nombre, int tiempoSiguiente, int tiempoAnterior);
    virtual ~EstacionNormal();

    virtual bool esEstacionTransferencia() const override;
};

#endif // ESTACIONNORMAL_H

