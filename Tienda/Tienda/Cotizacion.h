#ifndef COTIZACION_H
#define COTIZACION_H
#include <string>
#include <iostream>
#include <chrono>
#include "Prenda.h"

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
        setFechaHora(std::chrono::system_clock::now());//Setea fecha automatico cuando se crea una cotizacion.
    }

    //Metodos
    std::string toString() const;

    //Gettes y Setters de Cotizacion
    int getId() const { return id; }

    const std::chrono::system_clock::time_point& getFechaHora() const { return fechaHora; }
    void setFechaHora(const std::chrono::system_clock::time_point& fechaHora) { this->fechaHora = fechaHora; }

    int getCodigoVendedor() const { return codigoVendedor; }
    void setCodigoVendedor(int codigoVendedor) { this->codigoVendedor = codigoVendedor; }

    const Prenda* getPrenda() const { return prenda; }
    void setPrenda(Prenda* prenda) { this->prenda = prenda; }

    int getCantidad() const { return cantidad; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }

    double getResultado() const { return total; }
    void setResultado(double resultado) { this->total = resultado; }
};

#endif //COTIZACION_H