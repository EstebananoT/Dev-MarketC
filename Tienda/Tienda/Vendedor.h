#include <iostream>
#include <string>
#include <vector>
#include "Cotizacion.h"

class Vendedor {
private:
    string nombre;
    string apellido;
    int codigo;
    vector<Cotizacion> historial_cotizaciones;

public:
    // Constructores
    Vendedor() {}
    Vendedor(string nombre, string apellido, int codigo) : nombre(nombre), apellido(apellido), codigo(codigo) {}

    // Getters
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    int getCodigo() const { return codigo; }
    vector<Cotizacion> getHistorialCotizaciones() const { return historial_cotizaciones; }

    // Setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setApellido(string apellido) { this->apellido = apellido; }
    void setCodigo(int codigo) { this->codigo = codigo; }
    void setHistorialCotizaciones(vector<Cotizacion> historial_cotizaciones) { this->historial_cotizaciones = historial_cotizaciones; }

    // Métodos
    Cotizacion hacerCotizacion(Prenda prenda, int cantidad);
};
