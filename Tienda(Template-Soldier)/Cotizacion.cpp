#pragma once
#include "Cotizacion.h"
#include <string>       // Para el manejo de strings
#include <iostream>     // Para la entrada/salida estándar
#include <chrono>  
#include <ctime>        // Para trabajar con fechas y tiempos
#include "Prenda.h"     // Dependiendo de la implementación de la clase Prenda, podría ser necesaria su inclusión
#include <cstring>      // Si se necesita trabajar con strings estilo C
#include "Camisa.h"
#include "Pantalon.h"


std::string Cotizacion::toString() {
    std::string result = "ID: " + std::to_string(id) + "\n";

    // Formatear la fecha y hora
    /*std::time_t now_c = std::chrono::system_clock::to_time_t(fechaHora);

    struct tm time_info;
    localtime_s(&time_info, &now_c);

    char buffer[80];
    std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S",&time_info);


    result += "Fecha/Hora: " + std::string(buffer) + "\n";*/
    result += "Código Vendedor: " + std::to_string(codigoVendedor) + "\n";
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

