#pragma once
#include "Cotizacion.h"
#include <iomanip>
#include <sstream>
#include <ctime>
#include "Camisa.h"
#include "Pantalon.h"


std::string Cotizacion::toString() {
    std::stringstream ss;
    ss << "ID: " << id << std::endl;
    std::time_t t = std::chrono::system_clock::to_time_t(fechaHora);
    std::tm timeinfo;
    localtime_s(&timeinfo, &t);
    ss << "Fecha y Hora: " << std::put_time(&timeinfo, "%F %T") << std::endl;
    ss << "Codigo del Vendedor: " << codigoVendedor << std::endl;
    //Que tipo es la prenda? Polimorfismo?
    Camisa* prendaPrueba = dynamic_cast<Camisa*>(prenda);

    if (prendaPrueba!= nullptr ) {
        ss << "Prenda Cotizada: " << prendaPrueba->getNombrePrenda() << std::endl;
    }
    else {
        Pantalon* prendaPrueba = dynamic_cast<Pantalon*>(prenda);
        ss << "Prenda Cotizada: " << prendaPrueba->getNombrePrenda() << std::endl;
    }
    
    ss << "Cantidad de Unidades Cotizadas: " << prenda->getCantidadUnidades() << std::endl;
    ss << "Resultado de la Cotizacion: " << this->getResultado() << std::endl;
    return ss.str();
}
