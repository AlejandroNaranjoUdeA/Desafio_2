#ifndef LINEA_H
#define LINEA_H

#include "estaciones.h"
using namespace std;

class Linea
{
private:
    string nombreLinea;
    Estacion** estaciones;
    int cantidadEstaciones;
public:
    Linea(string nombre);
    string obtenerNombre()const;

    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(string nombre);
    int obtenerCantidadEstaciones();
    string getNombreLinea();
    void setNombreLinea(string nombre);
    Estacion** getEstaciones();
    int getCantidadEstaciones();
};

#endif // LINEA_H
