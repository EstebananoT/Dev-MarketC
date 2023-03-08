#include "Prenda.h"


Prenda::Prenda(Calidad _calidad, double _precioUnitario, int _cantidad)
{
    calidad = _calidad;
    precioUnitario = _precioUnitario;
    cantidad = _cantidad;
}

double Prenda::getPrecioTotalPrenda()
{
    return 0.0;
}

// Getter y Setter de calidad
Calidad Prenda::getCalidad() {
    return calidad;
}

void Prenda::setCalidad(Calidad _calidad) {
    calidad = _calidad;
}

// Getter y Setter de precio unitario
double Prenda::getPrecioUnitario() {
    return precioUnitario;
}

void Prenda::setPrecioUnitario(double _precioUnitario) {
    precioUnitario = _precioUnitario;
}

// Getter y Setter de cantidad de unidades
int Prenda::getCantidadUnidades() {
    return cantidad;
}

void Prenda::setCantidadUnidades(int _cantidadUnidades) {
    cantidad = _cantidadUnidades;
}