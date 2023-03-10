#ifndef PANTALON_H
#define PANTALON_H

#include "Prenda.h"
#include <string>
enum TipoPantalon { COMUN, CHUPIN };

class Pantalon : public Prenda {
public:


    Pantalon(Calidad calidad, double precioUnitario, int cantidadUnidades, TipoPantalon tipo);
    
    std::string getNombrePrenda() { return "Pantalon"; }


    //Method
    double getPrecioTotalPrenda() override;
    bool isChupin() const { return getTipoPantalon() == TipoPantalon::CHUPIN ? true : false; };
    //Get and Setter TipoPantalon
    void setTipoP(TipoPantalon tipo) { tipo = tipo; }
    TipoPantalon getTipoPantalon() const{ return tipo; }
private:
    TipoPantalon tipo;
};

#endif //PANTALON_H
