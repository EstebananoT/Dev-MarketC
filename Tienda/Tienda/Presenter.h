
#ifndef PRESENTER_H
#define PRESENTER_H
#include <string>
#include "IView.h"
#include "Vendedor.h"

class Presenter
{
private:
	IView* m_view = nullptr;
	Vendedor* m_vendedor = nullptr;
public:
	explicit Presenter(IView* view);
	~Presenter();
	Pantalon* buscarPantalon(bool isChupin, bool isPremiun);
	Camisa* buscarCamisa(bool isCuelloMao, bool isMangaCorta, bool isPremiun);
	void hacerCotizacion(Prenda* p, int cantidad, int codigoCotizacion);
	string verHistorialCotizaciones();

	//Setter and Getter
	void setVendedor(Vendedor* r) { m_vendedor = r; }
	Vendedor* getVendedor() { return m_vendedor; }
};

#endif //PRESENTER_H
