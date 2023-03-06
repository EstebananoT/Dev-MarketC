// Tienda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Tienda.h"
#include "Vendedor.h"
#include "Cotizacion.h"



Vendedor* Tienda::getVendedorPorId(int id) {
    for (Vendedor* vendedor : vendedores) {
        if (vendedor->getCodigo() == id) {
            return vendedor;
        }
    }
    throw VendedorNoEncontradoException(); // Si no se encuentra el vendedor, se retorna un puntero nulo
}
