#include "Prenda.h"

class Pantalon : public Prenda {
public:
    enum TipoPantalon {
        COMUN,
        CHUPIN
    };

    Pantalon(Calidad calidad, double precioUnitario, int cantidadUnidades, TipoPantalon tipo)
        : Prenda(calidad, precioUnitario, cantidadUnidades), tipo(tipo) {}

    TipoPantalon getTipo() const { return tipo; }
    void setTipo(TipoPantalon tipo) { this->tipo = tipo; }

private:
    TipoPantalon tipo;
};

