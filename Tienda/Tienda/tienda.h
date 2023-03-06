#include <string>
#include <vector>
#include "Vendedor.h"
#include "Cotizacion.h"
class Tienda {
private:
    string nombre;
    string direccion;
    vector<Vendedor*> vendedores;
    vector<Prenda*> prendas;
    vector<Cotizacion> allCotizaciones;
public:
    Tienda(string nombre, string direccion) 
        : nombre(nombre), direccion(direccion) {}
    ~Tienda() {}
    //Metodos para usar la logica
    vector<Cotizacion> getCotizaciones(int id);
    string getNombre() { return nombre; }
    void setNombre(std::string nombre) { this->nombre = nombre; }
    Vendedor* getVendedorPorId(int id);

    string getDireccion() { return direccion; }
    void setDireccion(std::string direccion) { this->direccion = direccion; }

    void agregarVendedor(Vendedor* vendedor) { vendedores.push_back(vendedor); }
    vector<Vendedor*> getVendedores() { return vendedores; }

    void agregarPrenda(Prenda* prenda) { prendas.push_back(prenda); }
    vector<Prenda*> getPrendas(){ return prendas; }

    void agregarCotizacion(Cotizacion cotizacion) { allCotizaciones.push_back(cotizacion); }
    vector<Cotizacion> getCotizaciones() { return allCotizaciones; }
};


class VendedorNoEncontradoException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "El vendedor no se encontró.";
    }
};