#pragma once
#include "Prenda.h"

enum class TipoCuello { MAO, COMUN };
enum class TipoManga { CORTA, LARGA };

class Camisa : public Prenda {
private:
    TipoCuello tipoCuello;
    TipoManga tipoManga;

public:
    Camisa(Calidad _calidad, float _precioUnitario, int _cantidadUnidades, TipoCuello _tipoCuello, TipoManga _tipoManga) :
        Prenda(_calidad, _precioUnitario, _cantidadUnidades), tipoCuello(_tipoCuello), tipoManga(_tipoManga) {}

    TipoCuello getTipoCuello() const { return tipoCuello; }
    TipoManga getTipoManga() const { return tipoManga; }

    void setTipoCuello(TipoCuello _tipoCuello) { tipoCuello = _tipoCuello; }
    void setTipoManga(TipoManga _tipoManga) { tipoManga = _tipoManga; }
};
