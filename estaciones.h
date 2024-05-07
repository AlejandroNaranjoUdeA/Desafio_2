#ifndef ESTACIONES_H
#define ESTACIONES_H

#include <QObject>
#include<iostream>
#include <string>

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
};


#endif // ESTACIONES_H
