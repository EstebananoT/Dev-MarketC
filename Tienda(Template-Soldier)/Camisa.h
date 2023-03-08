#ifndef CAMISA_H
#define CAMISA_H
#include "Prenda.h"
#include <string>

enum class TipoCuello { MAO, COMUN };
enum class TipoManga { CORTA, LARGA };

class Camisa : public Prenda {

public:


    Camisa(Calidad calidad, double precioUnitario,
        int cantidadUnidades, TipoCuello tipoCuello, TipoManga tipoManga);


    std::string getNombrePrenda() { return "Camisa"; }

    //method
    double getPrecioTotalPrenda() override;
    bool isCuelloMao() { return getTipoCuello() == TipoCuello::MAO ? true : false; };
    bool isMangaCorta() { return getTipoManga() == TipoManga::CORTA ? true : false; };
    //Get and Setter TipoPantalon
    TipoCuello getTipoCuello() const { return tipoCuello; }
    TipoManga getTipoManga() const { return tipoManga; }
    void setTipoCuello(TipoCuello _tipoCuello) { tipoCuello = _tipoCuello; }
    void setTipoManga(TipoManga _tipoManga) { tipoManga = _tipoManga; }

private:
    TipoCuello tipoCuello;
    TipoManga tipoManga;
};
#endif // CAMISA_H
