#pragma once
#include "Cotizacion.h"
#include <string>       // Para el manejo de strings
#include <iostream>     // Para la entrada/salida est�ndar
#include <chrono>  
#include <ctime>        // Para trabajar con fechas y tiempos
#include "Prenda.h"     // Dependiendo de la implementaci�n de la clase Prenda, podr�a ser necesaria su inclusi�n
#include <cstring>      // Si se necesita trabajar con strings estilo C
#include "Camisa.h"
#include "Pantalon.h"

/*
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
}*/

std::string Cotizacion::toString() {
    std::string result = "ID: " + std::to_string(id) + "\n";

    // Formatear la fecha y hora
    /*std::time_t now_c = std::chrono::system_clock::to_time_t(fechaHora);

    struct tm time_info;
    localtime_s(&time_info, &now_c);

    char buffer[80];
    std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S",&time_info);


    result += "Fecha/Hora: " + std::string(buffer) + "\n";*/
    result += "C�digo Vendedor: " + std::to_string(codigoVendedor) + "\n";
    Camisa* prendaPrueba = dynamic_cast<Camisa*>(prenda);

    if (prendaPrueba != nullptr) {
        result += "Prenda Cotizada: "+ prendaPrueba->getNombrePrenda() +"\n";
    }
    else {
        Pantalon* prendaPrueba = dynamic_cast<Pantalon*>(prenda);
        result += "Prenda Cotizada: " + prendaPrueba->getNombrePrenda() + "\n";
    }
    result += "Cantidad: " + std::to_string(cantidad) + "\n";
    result += "Total: " + std::to_string(total) + "\n";

    return result;
}

