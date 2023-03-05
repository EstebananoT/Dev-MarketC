#pragma once
#include "Prenda.h"

enum class Manga {
    CORTA,
    LARGA
};

enum class Cuello {
    COMUN,
    MAO
};

class Camisa : public Prenda {
public:
    Camisa(Calidad calidad, double precioUnitario, int cantidadUnidades, Manga manga, Cuello cuello) :
        Prenda(calidad, precioUnitario, cantidadUnidades), manga(manga), cuello(cuello) {}

private:
    Manga manga;
    Cuello cuello;
};

