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
    ~Linea();
    string obtenerNombre()const;
    // Opción para agregar una estación al principio de la línea
    void agregarEstacionAlPrincipio(Estacion* estacion);

    // Opción para agregar una estación en una posición específica
    void agregarEstacionEnPosicion(Estacion* estacion, int posicion);

    bool perteneceEstacion(const std::string& nombreEstacion);

    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(const std::string& nombreEstacion);
    bool esEstacionTransferencia(const std::string& nombreEstacion);
    void mostrarEstacionesDisponibles(const std::string& nombreLinea);
    int obtenerCantidadEstaciones();
    string getNombreLinea();
    void setNombreLinea(string nombre);
    Estacion** getEstaciones();
    int getCantidadEstaciones();
};

#endif // LINEA_H
