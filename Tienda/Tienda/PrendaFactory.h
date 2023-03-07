#ifndef PRENDAFACTORY_H
#define PRENDAFACTORY_H
#include "Prenda.h"
#include "Camisa.cpp"
#include "Pantalon.cpp"

class PrendaFactory {
public:

    static Pantalon* crearPantalon(Calidad calidad, double precioUnitario, int cantidad, TipoPantalon tipo) {
        
        Pantalon* newPantalon = new Pantalon(calidad, precioUnitario, cantidad, tipo);
        return newPantalon;
    }

    static Camisa* crearCamisa(Calidad calidad, double precioUnitario, int cantidad, TipoCuello tipoCuello, TipoManga tipoManga) {
        
        Camisa* camisa = new Camisa(calidad, precioUnitario, cantidad, tipoCuello, tipoManga);
        return camisa;
    }
};

#endif //PRENDAFACTORY_H