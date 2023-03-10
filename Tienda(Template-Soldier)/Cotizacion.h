#ifndef COTIZACION_H
#define COTIZACION_H
#include <string>
#include <iostream>
#include <chrono>
#include "Prenda.h"
#include <string.h>

class Cotizacion {
private:
    int id;
    std::chrono::system_clock::time_point fechaHora;
    int codigoVendedor;
    Prenda* prenda;
    int cantidad;
    double total;

public:
    Cotizacion(int codigo, int codigo_vendedor, Prenda* prenda, int cantidad, double total)
        : id(codigo), codigoVendedor(codigo_vendedor), prenda(prenda), cantidad(cantidad), total(total) {
        fechaHora = std::chrono::system_clock::now();//Setea fecha automatico cuando se crea una cotizacion.
    }
    Cotizacion(){}
    //Metodos
    std::string toString();

    //Gettes y Setters de Cotizacion
    int getId() const { return id; }

    std::chrono::system_clock::time_point& getFechaHora() { return fechaHora; }
    void setFechaHora(std::chrono::system_clock::time_point _fechaHora) { fechaHora = _fechaHora; }

    int getCodigoVendedor()  { return codigoVendedor; }
    void setCodigoVendedor(int _codigoVendedor) {codigoVendedor = _codigoVendedor; }

    Prenda* getPrenda()  { return prenda; }
    void setPrenda(Prenda* _prenda) {prenda = _prenda; }

    int getCantidad()  { return cantidad; }
    void setCantidad(int _cantidad) { cantidad = _cantidad; }

    double getResultado()  { return total; }
    void setResultado(double _resultado) { total = _resultado; }
};

#endif //COTIZACION_H