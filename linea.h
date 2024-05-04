#ifndef LINEA_H
#define LINEA_H


class Linea
{
private:
    //ATRIBUTOS:
    string nombreLinea;
    estacion** estaciones; // puntero
    int cantidadEstaciones;
public:
    Linea(string nombre); //CONSTRUCTOR:
    //METODOS:
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(string nombre);
    int obtenerCantidadEstaciones();
    string getNombreLinea();
    void setNombreLinea(string nombre);
    Estacion** getEstaciones();
    int getCantidadEstaciones();
};

#endif // LINEA_H
