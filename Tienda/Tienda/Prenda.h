class Prenda {
public:
    enum Calidad { STANDARD, PREMIUM };

    // Constructor
    Prenda(Calidad calidad, double precioUnitario, int cantidad);

    // Getters
    Calidad getCalidad() const;
    double getPrecioUnitario() const;
    int getCantidad() const;

    // Setters
    void setPrecioUnitario(double precioUnitario);
    void setCantidad(int cantidad);

private:
    Calidad calidad;
    double precioUnitario;
    int cantidad;
};

