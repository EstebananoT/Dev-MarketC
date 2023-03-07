#ifndef PRENDA_H
#define PRENDA_H
#include <string>

enum Calidad { STANDARD, PREMIUM };

class Prenda {

public:
    
    // Constructor
    Prenda(Calidad calidad, double precioUnitario, int cantidad);
    //Method
    virtual double getPrecioTotalPrenda();
    // Getters
    Calidad getCalidad();
    double getPrecioUnitario() ;
    int getCantidadUnidades();
    std::string getNombrePrenda();
    // Setters
    void setPrecioUnitario(double _precioUnitario);
    void setCalidad(Calidad _calidad);
    void setCantidadUnidades(int _cantidadUnidades);
private:
    Calidad calidad;
    double precioUnitario;
    int cantidad;
};
#endif // PRENDA_H