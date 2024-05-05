#ifndef LINEA_H
#define LINEA_H

#include <QObject>

#include "estaciones.h"

class Linea
{
private:
    //atributos:
    std::string nombreLinea;
    Estacion** estaciones;
    int cantidadEstaciones;
public:
    Linea(std::string nombre);
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(std::string nombre);
    int obtenerCantidadEstaciones();
    std::string getNombreLinea();
    void setNombreLinea(std::string nombre);
    Estacion** getEstaciones();
    int getCantidadEstaciones();
};

#endif // LINEA_H
