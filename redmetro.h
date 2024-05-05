#ifndef REDMETRO_H
#define REDMETRO_H

#include <QObject>

#include "linea.h"

class RedMetro
{
private:
    Linea** lineas;
    int cantidadLineas;
public:
    RedMetro();
    void agregarLinea(Linea* linea);
    void eliminarLinea(std::string nombre);
    int obtenerCantidadLineas();
    Linea** getLineas();
    int getCantidadLineas();
};

#endif // REDMETRO_H
