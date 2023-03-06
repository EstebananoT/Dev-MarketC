#ifndef PRESENTER_H
#define PRESENTER_H

class IView;
class Vendedor;

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
	void hacerCotizacion(Prenda p, int cantidad, int codigoCotizacion);
	string verHistorialCotizaciones();
	//Setter
	void setVendedor(Vendedor* r) { m_vendedor = r; }
};
#endif //PRESENTER_H
