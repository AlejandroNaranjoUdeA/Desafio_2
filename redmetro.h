#ifndef REDMETRO_H
#define REDMETRO_H


class redMetro
{
private:
    Linea** lineas;
    int cantidadLineas;
public:
    redMetro();
    void agregarLinea(Linea* linea);
    void eliminarLinea(string nombre);
    int obtenerCantidadLineas();
    Linea** getLineas();
    int getCantidadLineas();
};

#endif // REDMETRO_H
