#ifndef LINEA_H
#define LINEA_H

#include <QObject>
#include "estaciones.h"

class Linea
{
private:
    std::string nombreLinea;
    Estacion** estaciones;
    int cantidadEstaciones;
public:
    Linea(std::string nombre);
    ~Linea();
    std::string obtenerNombre()const;

    // Opción para agregar una estación al principio de la línea
    void agregarEstacionAlPrincipio(Estacion* estacion);

    // Opción para agregar una estación en una posición específica
    void agregarEstacionEnPosicion(Estacion* estacion, int posicion);

    bool perteneceEstacion(const std::string& nombreEstacion);

    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(const std::string& nombreEstacion);
    bool esEstacionTransferencia(const std::string& nombreEstacion);
    void mostrarEstacionesDisponibles();
    int obtenerCantidadEstaciones();
    std::string getNombreLinea();
    void setNombreLinea(std::string nombre);
    Estacion** getEstaciones();
    int getCantidadEstaciones();
};

#endif // LINEA_H
