#include <string>
#include <iostream>
#include <chrono>
#include "Prenda.hpp"

using namespace std;
class Cotizacion {
private:
    int id;
    std::chrono::system_clock::time_point fechaHora;
    int codigoVendedor;
    Prenda prenda;
    int cantidad;
    double resultado;

public:
    Cotizacion(int id, const std::chrono::system_clock::time_point& fechaHora, int codigoVendedor, const Prenda& prenda, int cantidad, double resultado)
        : id(id), fechaHora(fechaHora), codigoVendedor(codigoVendedor), prenda(prenda), cantidad(cantidad), resultado(resultado) {
        fechaHora = std::chrono::system_clock::now();//Setea fecha automatico cuando se crea una cotizacion.
    }

    //Metodos
    string toString() const;

    //Gettes y Setters de Cotizacion
    int getId() const { return id; }

    const std::chrono::system_clock::time_point& getFechaHora() const { return fechaHora; }
    void setFechaHora(const std::chrono::system_clock::time_point& fechaHora) { this->fechaHora = fechaHora; }

    int getCodigoVendedor() const { return codigoVendedor; }
    void setCodigoVendedor(int codigoVendedor) { this->codigoVendedor = codigoVendedor; }

    const Prenda& getPrenda() const { return prenda; }
    void setPrenda(const Prenda& prenda) { this->prenda = prenda; }

    int getCantidad() const { return cantidad; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }

    double getResultado() const { return resultado; }
    void setResultado(double resultado) { this->resultado = resultado; }
};

