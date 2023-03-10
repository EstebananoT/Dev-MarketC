#pragma once
#include "Vendedor.h"
#include "Camisa.h"
#include "Pantalon.h"
#include <typeindex>

 Cotizacion Vendedor::hacerCotizacionPantalon(Pantalon* pantalon, int cantidad, int numeroCotizacion) {
     if (cantidad > pantalon->getCantidadUnidades()) {
         throw PrendaNoStock();
     }
     else {
         double precio = pantalon->getPrecioTotalPrenda();
         double total = precio * cantidad;
         Cotizacion cotizacion(numeroCotizacion, codigo, pantalon, cantidad, total);
         //agregarCotizacionTienda(*cotizacion);
         numeroCotizacion += 1;
         agregarCotizacionToMe(cotizacion);
         cout << cotizacion.toString();
         return cotizacion;

     }
}

 Cotizacion Vendedor::hacerCotizacionCamisa(Camisa* camisa, int cantidad, int numeroCotizacion) {
     if (cantidad > camisa->getCantidadUnidades()) {
         throw PrendaNoStock();
     }
     else {
         double precio = camisa->getPrecioTotalPrenda();
         double total = precio * cantidad;
         Cotizacion cotizacion(numeroCotizacion, codigo, camisa, cantidad, total);
         numeroCotizacion += 1;
         //agregarCotizacionTienda(*cotizacion); No lo c rick. 
         agregarCotizacionToMe(cotizacion);
         cout << cotizacion.toString();
         return cotizacion;

     }
 }

/**void Vendedor::agregarCotizacionTienda(Cotizacion cotizacion) {
    tienda->agregarCotizacion(cotizacion);
}*/
void Vendedor::agregarCotizacionToMe(Cotizacion cotizacion) {
    historial_cotizaciones.push_back(cotizacion);
}

Camisa* Vendedor::buscarCamisa(bool isCuelloMao, bool isMangaCorta, bool isPremiun) {
    vector<Camisa> camisas = tienda->getCamisas();
    //Crear puntero de camisa
    Camisa* camisaBuscada = nullptr;
    // Iterar por el vector de prendas
    for (int i = 0; i < camisas.size(); i++) {
        if ((camisas[i].getCalidad() == Calidad::PREMIUM) == isPremiun) {
            if (camisas[i].isMangaCorta() == isMangaCorta) {
                if (camisas[i].isCuelloMao() == isCuelloMao) {
                    camisaBuscada = &camisas[i];
                }
                else {
                    camisaBuscada = &camisas[i];
                }
            }
            else {
                if (camisas[i].isCuelloMao() == isCuelloMao) {
                    camisaBuscada = &camisas[i];
                }
                else {
                    camisaBuscada = &camisas[i];
                }
            }
        }
        else {
             if (camisas[i].isMangaCorta() == isMangaCorta) {
                 if (camisas[i].isCuelloMao() == isCuelloMao) {
                     camisaBuscada = &camisas[i];
                 }
                 else {
                     camisaBuscada = &camisas[i];
                 }
             }
             else {
                 if (camisas[i].isCuelloMao() == isCuelloMao) {
                    camisaBuscada = &camisas[i];
                 }
                 else {
                     camisaBuscada = &camisas[i];
                 }
             }
        }

        
    }
    if (camisaBuscada == nullptr) throw PrendaNotFound();
    return camisaBuscada;
};

Pantalon* Vendedor::buscarPantalon(bool isChupin, bool isPremiun) {
    vector<Pantalon*> pantalones = tienda->getPantalonesReferencia();
    Pantalon* objPantalonFound = nullptr;
    cout << pantalones.size();
    for (int i = 0; i < pantalones.size(); i++) {
        if (pantalones[i]->getCalidad() == Calidad::PREMIUM && isPremiun) {
            if (pantalones[i]->isChupin() == isChupin) {
                objPantalonFound = pantalones[i];
                break;
            }
        }
        else if (pantalones[i]->getCalidad() != Calidad::PREMIUM && !isPremiun) {
            if (pantalones[i]->isChupin() == isChupin) {
                objPantalonFound = pantalones[i];
                break;
            }
        }
    }
    if (objPantalonFound == nullptr) throw PrendaNotFound();
    cout << objPantalonFound->getPrecioTotalPrenda() <<std::endl;
    cout << objPantalonFound->getPrecioUnitario() << std::endl;
    return objPantalonFound;
}


