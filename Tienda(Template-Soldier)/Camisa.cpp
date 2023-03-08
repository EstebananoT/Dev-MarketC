#include "Camisa.h"
#include "Prenda.h"
double Camisa::getPrecioTotalPrenda() {
    // Si la prenda es una camisa
    double precio = this->getPrecioUnitario();
    // Si la camisa es de tipo manga corta, rebaja el precio un 10%
    if (this->getTipoManga() == TipoManga::CORTA) {
        precio -= precio * 0.1;
    }
    // Si la camisa tiene cuello mao, aumenta el precio un 3%
    if (this->getTipoCuello() == TipoCuello::MAO) {
        precio += precio * 0.03;
    }
    // Si la calidad de la prenda es Premium, aumenta el precio un 30%
    if (this->getCalidad() == Calidad::PREMIUM) {
        precio += precio * 0.3;
    }

    return precio;
}

Camisa::Camisa(Calidad calidad, double precioUnitario, int cantidadUnidades, TipoCuello tipoCuello, TipoManga tipoManga)
    :Prenda(calidad, precioUnitario, cantidadUnidades), tipoCuello(tipoCuello), tipoManga(tipoManga) {}