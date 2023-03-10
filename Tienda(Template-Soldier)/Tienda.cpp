

#include <iostream>
#include <vector>
#include "Tienda.h"
#include "Camisa.h"

/**Vendedor* Tienda::getVendedorPorId(int id) {
    for (Vendedor* vendedor : vendedores) {
        if (vendedor->getCodigo() == id) {
            return vendedor;
        }
    }

    throw VendedorNoEncontradoException(); // Si no se encuentra el vendedor, se retorna un puntero nulo
}*/

void Tienda::agregarCamisa(Camisa prenda)
{
    camisas.push_back(prenda);
}

void Tienda::agregarPantalon(Pantalon prenda)
{
    pantalones.push_back(prenda);
}

void Tienda::agregarCotizacion(Cotizacion cotizacion)
{
    allCotizaciones.push_back(cotizacion);
}

vector<Pantalon> Tienda::getPantalones()
{
    return pantalones;
}

vector<Pantalon*> Tienda::getPantalonesReferencia() {
    vector<Pantalon*> referencias;
    for (Pantalon& pantalon : pantalones) {
        referencias.push_back(&pantalon);
    }
    return referencias;
}

vector<Camisa> Tienda::getCamisas()
{
    return camisas;
}

vector<Camisa*> Tienda::getCamisasReferencia() {
    vector<Camisa*> referencias;
    for (Camisa& camisa : camisas) {
        referencias.push_back(&camisa);
    }
    return referencias;
}

vector<Cotizacion> Tienda::getCotizaciones()
{
    return allCotizaciones;
}
