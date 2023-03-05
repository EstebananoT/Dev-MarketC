#include "Cotizacion.h"
#include <iomanip>
#include <sstream>
using namespace std;

string Cotizacion::toString() const {
    std::stringstream ss;
    ss << "ID: " << id << std::endl;
    std::time_t t = std::chrono::system_clock::to_time_t(fechaHora);
    ss << "Fecha y Hora: " << std::put_time(std::localtime(&t), "%F %T") << std::endl;
    ss << "Codigo del Vendedor: " << codigoVendedor << std::endl;
    ss << "Prenda Cotizada: " << prenda.getCodigo() << " - " << prenda.getDescripcion() << std::endl;
    ss << "Cantidad de Unidades Cotizadas: " << cantidadUnidades << std::endl;
    ss << "Resultado de la Cotizacion: " << resultado << std::endl;
    return ss.str();
}
