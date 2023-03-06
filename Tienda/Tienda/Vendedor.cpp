#pragma once
#include "Vendedor.h"
#include "Prenda.h"
#include "Cotizacion.h"
#include "Camisa.h"
#include <typeindex>

enum class TipoCuello { MAO, COMUN };
enum class TipoManga { CORTA, LARGA };
enum Calidad { STANDARD, PREMIUM };
enum TipoPantalon { COMUN, CHUPIN };

void Vendedor::hacerCotizacion(Prenda& prenda, int cantidad, int codigo_Cotiza) {
    if (cantidad > prenda.getCantidadUnidades())throw PrendaNoStock();
    else {
        double precio = prenda.getPrecioTotalPrenda();
        
        double total = precio * cantidad;
        Vendedor::agregarCotizacion(Cotizacion(++codigo_Cotiza, this->getCodigo(), &prenda, cantidad, total));

    }
    
}

void Vendedor::agregarCotizacion(Cotizacion cotizacion) {
    getTienda().agregarCotizacion(cotizacion);
}

Camisa* Vendedor::buscarCamisa(bool isCuelloMao, bool isMangaCorta , bool isPremiun) {
    vector<Prenda*> prendas = tienda.getPrendas();
    
    //Variable Camisa a encontrar (Aqui se guarda :)
    Camisa* objCamisaFound = nullptr;
    // Iterar por el vector de prendas
    for (std::vector<Prenda*>::iterator it = prendas.begin(); it != prendas.end(); ++it) {
        Prenda* prenda = *it;
        // Castear Prenda a Camisa
        if (prenda->getNombrePrenda() == "Camisa") {
            Camisa* camisaBusacada = dynamic_cast<Camisa*>(prenda);
            if ((camisaBusacada->getCalidad() == Calidad::PREMIUM) == isPremiun) {
                if (camisaBusacada->isMangaCorta() == isMangaCorta) {
                    if (camisaBusacada->isCuelloMao() == isCuelloMao) {
                        objCamisaFound = dynamic_cast<Camisa*>(prenda);
                    }
                    else {
                        objCamisaFound = dynamic_cast<Camisa*>(prenda);
                    }
                }
                else {
                    if (camisaBusacada->isCuelloMao() == isCuelloMao) {
                        objCamisaFound = dynamic_cast<Camisa*>(prenda);
                    }
                    else {
                        objCamisaFound = dynamic_cast<Camisa*>(prenda);
                    }
                }
            }
            else {
                if (camisaBusacada->isMangaCorta() == isMangaCorta) {
                    if (camisaBusacada->isCuelloMao() == isCuelloMao) {
                        objCamisaFound = dynamic_cast<Camisa*>(prenda);
                    }
                    else {
                        objCamisaFound = dynamic_cast<Camisa*>(prenda);
                    }
                }
                else {
                    if (camisaBusacada->isCuelloMao() == isCuelloMao) {
                        objCamisaFound = dynamic_cast<Camisa*>(prenda);
                    }
                    else {
                        objCamisaFound = dynamic_cast<Camisa*>(prenda);
                    }
                }
            }
            
        }
    }
    if (objCamisaFound == nullptr) throw PrendaNotFound();
    return objCamisaFound;
};

Pantalon* Vendedor::buscarPantalon(bool isChupin, bool isPremiun) {

    vector<Prenda*> prendas = tienda.getPrendas();
    //Variable Camisa a encontrar (Aqui se guarda :)
    Pantalon* objCamisaFound = nullptr;
    // Iterar por el vector de prendas
    for (std::vector<Prenda*>::iterator it = prendas.begin(); it != prendas.end(); ++it) {
        Prenda* prenda = *it;
        
        if (prenda->getNombrePrenda() == "Pantalon") {
            // Castear Prenda a Pantalon
            Pantalon* pantalonBuscada = dynamic_cast<Pantalon*>(prenda);
            //Prenda Premiun
            if ((pantalonBuscada->getCalidad() == Calidad::PREMIUM) == isPremiun) {
                //Comparo si la prenda es Chupin o no
                if (pantalonBuscada->isChupin() == isChupin) {
                    objCamisaFound = pantalonBuscada;
                }
                else { objCamisaFound = pantalonBuscada; }
            }
            //Prenda no Premiun (Comun)
            else {
                //Comparo si la prenda es Chupin o no
                if (pantalonBuscada->isChupin() == isChupin) {
                    objCamisaFound = pantalonBuscada;
                }
                else { objCamisaFound = pantalonBuscada; }
            }
            
        }
    }
    if (objCamisaFound == nullptr) throw PrendaNotFound();

    return objCamisaFound;
};


