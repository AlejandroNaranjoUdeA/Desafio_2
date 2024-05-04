#ifndef ESTACIONES_H
#define ESTACIONES_H


class Estaciones
{
private:
    //ATRIBUTOS:
    string nombreEstacion;
    int tiempoSiguiente;
    int tiempoAnterior;
    bool estransferencia;
public:
    Estaciones(string nombre, int siguiente, int anterior, bool transferencia); //CONSTRUCTOR
    //METODOS:
    bool estransferencia();
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
