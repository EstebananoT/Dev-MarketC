#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>

//#include "Vendedor.h" // Incluimos el archivo de cabecera de la clase Vendedor
#include "Cotizacion.h"
#include "Pantalon.h"
#include "Camisa.h"

using namespace std;

class Tienda {
private:
    string nombre;
    string direccion;
    //vector<Vendedor*> vendedores; // Usamos la clase Vendedor después de haberla incluido
    vector<Pantalon> pantalones;
    vector<Camisa> camisas;
    vector<Cotizacion> allCotizaciones;
public:
    Tienda(string nombre, string direccion)
        : nombre(nombre), direccion(direccion) {}
    //Metodos para usar la logica
    string getNombre() { return nombre; };
    void setNombre(std::string _nombre) { nombre = _nombre; };


    string getDireccion() { return direccion; }
    void setDireccion(std::string _direccion) { direccion = _direccion; }

    
    void agregarCamisa(Camisa prenda);
    void agregarPantalon(Pantalon prenda);
    void agregarCotizacion(Cotizacion cotizacion);

    vector<Pantalon> getPantalones();
    vector<Pantalon*> getPantalonesReferencia();

    vector<Camisa> getCamisas();
    vector<Camisa*> getCamisasReferencia();
    vector<Cotizacion> getCotizaciones();
};


class VendedorNoEncontradoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "El vendedor no se encontró.";
    }
};

#endif //TIENDA_H