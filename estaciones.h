#ifndef ESTACIONES_H
#define ESTACIONES_H

#include <QObject>

#include <string>

class Estacion
{
private:
    std::string nombreEstacion;
    int tiempoSiguiente;
    int tiempoAnterior;
    bool esTransferencia;
public:
    Estacion(std::string nombre, int siguiente, int anterior, bool transferencia);
    bool Transferencia();
    std::string getnombreEstacion();
    void setnombreEstacion(std::string nombre);
    int getTiempoSiguiente();
    void setTiempoSiguiente(int tiempo);
    int getTiempoAnterior();
    void setTiempoAnterior(int tiempo);
    bool getEsTransferencia();
    void setEsTransferencia(bool transferencia);
};

#endif // ESTACIONES_H
