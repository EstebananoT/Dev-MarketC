#include "Pantalon.h"
#include "Prenda.h"
#include <iostream>
double Pantalon::getPrecioTotalPrenda() {
    double precio = getPrecioUnitario();
    // Si el pantalón es chupín, rebaja el precio un 12%
    if (this->getTipoPantalon() == TipoPantalon::CHUPIN) {
        precio -= precio * 0.12;
    }


    // Si la calidad de la prenda es Premium, aumenta el precio un 30%
    if (this->getCalidad() == Calidad::PREMIUM) {
        precio += precio * 0.3;
    }
    return precio;
}

Pantalon::Pantalon(Calidad calidad, double precioUnitario, int cantidadUnidades, TipoPantalon tipo)
    : Prenda(calidad, precioUnitario, cantidadUnidades), tipo(tipo) {};
