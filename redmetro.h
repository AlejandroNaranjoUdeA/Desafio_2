#ifndef REDMETRO_H
#define REDMETRO_H

#include "linea.h"

class RedMetro
{
private:
    Linea** lineas;
    int cantidadLineas;
public:
    RedMetro();
    void agregarLinea(Linea* linea);
    void eliminarLineaPorNombre(const std::string& nombreLinea);

    int obtenerCantidadLineas();
    Linea** getLineas();
    int getCantidadLineas();
};

#endif // REDMETRO_H
