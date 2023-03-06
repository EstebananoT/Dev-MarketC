#pragma once
#include "Prenda.h"
#include "Camisa.h"
#include "Pantalon.h"


class PrendaFactory {
public:
    static Prenda* crearPantalon(Calidad calidad, double precioUnitario, int cantidad, TipoPantalon tipo) {
        Pantalon* pantalon = new Pantalon(calidad, precioUnitario, cantidad, tipo);
        return pantalon;
    }

    static Prenda* crearCamisa(Calidad calidad, double precioUnitario, int cantidad, TipoCuello tipoCuello, TipoManga tipoManga) {
        Camisa* camisa = new Camisa(calidad, precioUnitario, cantidad, tipoCuello, tipoManga);
        return camisa;
    }
};