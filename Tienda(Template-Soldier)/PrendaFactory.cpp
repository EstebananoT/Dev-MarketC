#include "PrendaFactory.h"
#include <algorithm>

PrendaFactory::PrendaFactory() = default;

Pantalon* PrendaFactory::crearPantalon(Calidad calidad, double precioUnitario, int cantidad, TipoPantalon tipo) {

	Pantalon* newPantalon = new Pantalon(calidad, precioUnitario, cantidad, tipo);
	return newPantalon;
}

Camisa* PrendaFactory::crearCamisa(Calidad calidad, double precioUnitario, int cantidad, TipoCuello tipoCuello, TipoManga tipoManga) {

	Camisa* camisa = new Camisa(calidad, precioUnitario, cantidad, tipoCuello, tipoManga);
	return camisa;
}
