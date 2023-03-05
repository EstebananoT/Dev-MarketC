#include <string>
#include <vector>
#include "Vendedor.h"
class Tienda {
private:
    std::string nombre;
    std::string direccion;
    std::vector<Vendedor> vendedores;
    std::vector<Prenda> prendas;
public:
    Tienda(std::string nombre, std::string direccion) : nombre(nombre), direccion(direccion) {}
    ~Tienda() {}

    std::string getNombre() const { return nombre; }
    void setNombre(std::string nombre) { this->nombre = nombre; }

    std::string getDireccion() const { return direccion; }
    void setDireccion(std::string direccion) { this->direccion = direccion; }

    void agregarVendedor(Vendedor vendedor) { vendedores.push_back(vendedor); }
    std::vector<Vendedor> getVendedores() const { return vendedores; }

    void agregarPrenda(Prenda prenda) { prendas.push_back(prenda); }
    std::vector<Prenda> getPrendas() const { return prendas; }
};


