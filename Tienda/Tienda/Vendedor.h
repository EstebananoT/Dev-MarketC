#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Cotizacion.h"
#include "Tienda.h"
#include "Pantalon.h"

class Vendedor {
private:
    string nombre;
    string apellido;
    int codigo;
    vector<Cotizacion> historial_cotizaciones;
    int codigo_Cotiza = 0;
    Tienda tienda;
public:
    // Constructores
    Vendedor(string nombre, string apellido, int codigo, Tienda t) 
        : nombre(nombre), apellido(apellido), codigo(codigo) , tienda(t){}

    // Getters
    string getNombre()  { return nombre; }
    string getApellido()  { return apellido; }
    int getCodigo()  { return codigo; }
    vector<Cotizacion> getHistorialCotizaciones() { return historial_cotizaciones; }
    Tienda getTienda() { return tienda;  }
    vector<Cotizacion> getCotizaciones() { return historial_cotizaciones; }

    // Setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setApellido(string apellido) { this->apellido = apellido; }
    void setCodigo(int codigo) { this->codigo = codigo; }
    void setHistorialCotizaciones(vector<Cotizacion> historial_cotizaciones) { this->historial_cotizaciones = historial_cotizaciones; }
    // Métodos

    void agregarCotizacion( Cotizacion cotizacion);

    Camisa* buscarCamisa(bool isCuelloMao ,bool isMangaCorta , bool isPremiun);

    Pantalon* buscarPantalon(bool isChupin , bool isPremiun);
    void hacerCotizacion(Prenda& prenda, int cantidad, int codigo_Cotiza);
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