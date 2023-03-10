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
        : nombre(nombre), apellido(apellido), codigo(codigo), tienda(t) {
        numeroCotizacion = 0;
    }

    // Getters
    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    int getCodigo() { return codigo; }
    int getNumeroCotizacion() { return numeroCotizacion; }
    Tienda* getTienda() { return tienda; }
    //vector<Cotizacion*> getHistorialCotizaciones() { return historial_cotizaciones; }
    //vector<Cotizacion*> getCotizaciones() { return historial_cotizaciones; }

    // Setters
    void setNombre(string _nombre) { nombre = _nombre; }
    void setApellido(string _apellido) { apellido = _apellido; }
    void setCodigo(int _codigo) { codigo = _codigo; }
    
    // Métodos
    void agregarCotizacionTienda(Cotizacion* cotizacion);
    void agregarCotizacionToMe(Cotizacion cotizacion);

    //Uso apuntadores para devolver la referencia al objeto en cuestion.
    Camisa* buscarCamisa(bool isCuelloMao, bool isMangaCorta, bool isPremium);

    Pantalon* buscarPantalon(bool isChupin, bool isPremium);

    //Realiza cotizaciones dependiendo la prenda
    Cotizacion hacerCotizacionPantalon(Pantalon* prenda, int cantidad);
    Cotizacion hacerCotizacionCamisa(Camisa* prenda, int cantidad);
    vector<Cotizacion*> getCotizacionesReferencias();
private:
    string nombre;
    string apellido;
    int codigo;
    vector<Cotizacion> historial_cotizaciones;
    int numeroCotizacion;
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