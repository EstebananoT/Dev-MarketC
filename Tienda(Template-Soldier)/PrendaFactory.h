#ifndef PRENDA_FACTORY_H
#define PRENDA_FACTORY_H
#include <map>

#include "Prenda.h"
#include "Camisa.h"
#include "Pantalon.h"
class PrendaFactory
{
public:
	PrendaFactory();
	~PrendaFactory() = default;
	static Pantalon crearPantalon(Calidad calidad, double precioUnitario, int cantidad, TipoPantalon tipo);
	static Camisa crearCamisa(Calidad calidad, double precioUnitario, int cantidad, TipoCuello tipoCuello, TipoManga tipoManga);
};
#endif //PRENDA_FACTORY_H
