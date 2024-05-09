#ifndef REDMETRO_H
#define REDMETRO_H

#include "linea.h"
#include <QObject>

class RedMetro
{
private:
    Linea** lineas;
    int cantidadLineas;
public:
    RedMetro();
    ~RedMetro(); //destructor
    void agregarLinea(Linea* linea);
    void eliminarLineaPorNombre(const std::string& nombreLinea);
    void mostrarLineasDisponibles();

    int obtenerCantidadLineas();
    Linea** getLineas();
    int getCantidadLineas();
    Estacion** getEstacionesDeLinea(const std::string& nombreLinea);
    int getPosicionEstacionEnLinea(const std::string& nombreEstacion, const std::string& nombreLinea);
};

#endif // REDMETRO_H
