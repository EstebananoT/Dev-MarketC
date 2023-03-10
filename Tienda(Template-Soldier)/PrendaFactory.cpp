#include "PrendaFactory.h"
#include <algorithm>

PrendaFactory::PrendaFactory() = default;

Pantalon PrendaFactory::crearPantalon(Calidad calidad, double precioUnitario, int cantidad, TipoPantalon tipo) {

	Pantalon p(calidad, precioUnitario, cantidad, tipo);
	return p;
}

Camisa  PrendaFactory::crearCamisa(Calidad calidad, double precioUnitario, int cantidad, TipoCuello tipoCuello, TipoManga tipoManga) {

	Camisa c (calidad, precioUnitario, cantidad, tipoCuello, tipoManga);
	return c;
}
