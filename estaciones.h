
#ifndef ESTACIONES_H
#define ESTACIONES_H

#include <iostream>
#include <ctime>
using namespace std;

class Estacion
{
private:
    std::string nombreEstacion;
    int tiempoSiguiente;
    int tiempoAnterior;
    bool esTransferencia;
public:
    Estacion(const std::string& nombre, int tiempoSiguiente, int tiempoAnterior, bool transferencia);
    virtual ~Estacion();
    bool Transferencia();
    virtual bool esEstacionTransferencia() const;
    std::string getnombreEstacion();
    void setnombreEstacion(std::string nombre);


    int getTiempoSiguiente();
    void setTiempoSiguiente(int tiempo);
    int getTiempoAnterior();
    void setTiempoAnterior(int tiempo);
    std::tm calcularTiempoLlegada(const std::tm& tiempoSalida, int tiempoViaje) const;
};
#endif // ESTACIONES_H
