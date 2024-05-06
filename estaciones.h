#ifndef ESTACIONES_H
#define ESTACIONES_H

#include <iostream>
using namespace std;

class Estacion
{
private:
    string nombreEstacion;
    int tiempoSiguiente;
    int tiempoAnterior;
    bool esTransferencia;
public:
    Estacion(string nombre, int siguiente, int anterior, bool transferencia);
    bool Transferencia();
    string getnombreEstacion();
    void setnombreEstacion(string nombre);
    int getTiempoSiguiente();
    void setTiempoSiguiente(int tiempo);
    int getTiempoAnterior();
    void setTiempoAnterior(int tiempo);
    bool getEsTransferencia();
    void setEsTransferencia(bool transferencia);
};
#endif // ESTACIONES_H
