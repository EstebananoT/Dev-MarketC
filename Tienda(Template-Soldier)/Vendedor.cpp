#pragma once
#include "Vendedor.h"
#include "Camisa.h"
#include "Pantalon.h"
#include <typeindex>

 Cotizacion Vendedor::hacerCotizacionPantalon(Pantalon* pantalon, int cantidad) {
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
         return cotizacion;

     }
}

 Cotizacion Vendedor::hacerCotizacionCamisa(Camisa* camisa, int cantidad) {
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
         return cotizacion;

     }
 }

 vector<Cotizacion*> Vendedor::getCotizacionesReferencias() {
     vector<Cotizacion*> referencias;
     for (Cotizacion& coti : historial_cotizaciones) {
         referencias.push_back(&coti);
     }
     return referencias;
 }

/**void Vendedor::agregarCotizacionTienda(Cotizacion cotizacion) {
    tienda->agregarCotizacion(cotizacion);
}*/
void Vendedor::agregarCotizacionToMe(Cotizacion cotizacion) {
    historial_cotizaciones.push_back(cotizacion);
}

Camisa* Vendedor::buscarCamisa(bool isCuelloMao, bool isMangaCorta, bool isPremiun) {

    vector<Camisa*> camisas = tienda->getCamisasReferencia();
    Camisa* objCamisaFound = nullptr;
    for (int i = 0; i < camisas.size(); i++) {
        if (camisas[i]->getCalidad() == Calidad::PREMIUM && isPremiun) {
            if (camisas[i]->isCuelloMao() == isCuelloMao && camisas[i]->isMangaCorta() == isMangaCorta) {
                objCamisaFound = camisas[i];
                break;
            }
            else if(camisas[i]->isCuelloMao() != isCuelloMao && camisas[i]->isMangaCorta() == isMangaCorta){
                objCamisaFound = camisas[i];
                break;
            }
            else if (camisas[i]->isCuelloMao() == isCuelloMao && camisas[i]->isMangaCorta() != isMangaCorta) {
                objCamisaFound = camisas[i];
                break;
            }
            else {
                objCamisaFound = camisas[i];
                break;
            }
        }
        else if (camisas[i]->getCalidad() != Calidad::PREMIUM && !isPremiun) {
            if (camisas[i]->isCuelloMao() == isCuelloMao && camisas[i]->isMangaCorta() == isMangaCorta) {
                objCamisaFound = camisas[i];
                break;
            }
            else if (camisas[i]->isCuelloMao() != isCuelloMao && camisas[i]->isMangaCorta() == isMangaCorta) {
                objCamisaFound = camisas[i];
                break;
            }
            else if (camisas[i]->isCuelloMao() == isCuelloMao && camisas[i]->isMangaCorta() != isMangaCorta) {
                objCamisaFound = camisas[i];
                break;
            }
            else {
                objCamisaFound = camisas[i];
                break;
            }
        }
    }
    if (objCamisaFound == nullptr) throw PrendaNotFound();
    return objCamisaFound;
};

Pantalon* Vendedor::buscarPantalon(bool isChupin, bool isPremiun) {
    vector<Pantalon*> pantalones = tienda->getPantalonesReferencia();
    Pantalon* objPantalonFound = nullptr;
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
    return objPantalonFound;
}


