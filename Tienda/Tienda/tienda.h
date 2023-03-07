#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>

//#include "Vendedor.h" // Incluimos el archivo de cabecera de la clase Vendedor
#include "Cotizacion.h"
#include "Prenda.h"

using namespace std;

class Tienda {
private:
    string nombre;
    string direccion;
    //vector<Vendedor*> vendedores; // Usamos la clase Vendedor después de haberla incluido
    vector<Prenda*> prendas;
    vector<Cotizacion*> allCotizaciones;
public:
    Tienda(string nombre, string direccion)
        : nombre(nombre), direccion(direccion) {}
    //Metodos para usar la logica
    vector<Cotizacion*> getCotizaciones(int id);
    string getNombre() { return nombre; };
    void setNombre(std::string nombre) { this->nombre = nombre; };
    

    string getDireccion() { return direccion; }
    void setDireccion(std::string direccion) { this->direccion = direccion; }

    //void agregarVendedor(Vendedor* vendedor) { vendedores.push_back(vendedor); }
    //vector<Vendedor*> getVendedores() { return vendedores; }
    //Vendedor* getVendedorPorId(int id);
    void agregarPrenda(Prenda* prenda) { prendas.push_back(prenda); }
    vector<Prenda*> getPrendas() { return prendas; }

    void agregarCotizacion(Cotizacion* cotizacion) { allCotizaciones.push_back(cotizacion); }
    vector<Cotizacion*> getCotizaciones() { return allCotizaciones; }
};


class VendedorNoEncontradoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "El vendedor no se encontró.";
    }
};

#endif //TIENDA_H