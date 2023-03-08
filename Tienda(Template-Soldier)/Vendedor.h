#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Cotizacion.h"
#include "Tienda.h"
#include "Pantalon.h"
#include "Camisa.h"

#include <iostream>
#include <string>
#include <vector>


class Vendedor {

public:
    // Constructores
    Vendedor(string nombre, string apellido, int codigo, Tienda* t)
        : nombre(nombre), apellido(apellido), codigo(codigo), tienda(t) {}

    // Getters
    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    int getCodigo() { return codigo; }
    vector<Cotizacion*> getHistorialCotizaciones() { return historial_cotizaciones; }
    Tienda* getTienda() { return tienda; }
    vector<Cotizacion*> getCotizaciones() { return historial_cotizaciones; }

    // Setters
    void setNombre(string _nombre) { nombre = _nombre; }
    void setApellido(string _apellido) { apellido = _apellido; }
    void setCodigo(int _codigo) { codigo = _codigo; }
    void setHistorialCotizaciones(vector<Cotizacion*> _historial_cotizaciones) { historial_cotizaciones = _historial_cotizaciones; }
    // Métodos

    void agregarCotizacion(Cotizacion* cotizacion);

    Camisa* buscarCamisa(bool isCuelloMao, bool isMangaCorta, bool isPremium);

    Pantalon* buscarPantalon(bool isChupin, bool isPremium);
    void hacerCotizacion(Prenda* prenda, int cantidad, int codigo_Cotiza);

private:
    string nombre;
    string apellido;
    int codigo;
    vector<Cotizacion*> historial_cotizaciones;
    int codigo_Cotiza = 0;
    Tienda* tienda;

};



class PrendaNoStock : public std::exception {
public:
    virtual const char* what() const throw() {
        return "No hay suficientes prendas en stock.";
    }
};

class PrendaNotFound : public std::exception {
public:
    virtual const char* what() const throw() {
        return "No existe la prenda.";
    }
};

#endif //VENDEDOR_H