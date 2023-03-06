#pragma once
#include "Presenter.h"
#include "IView.h"
#include "Vendedor.h"
#include "PrendaFactory.h"
#include "Camisa.h"
#include "Pantalon.h"

Presenter::Presenter(IView* view) 
	: m_view(view)
{
	//Creacion de datos Fictis XD
	Tienda QBendicion("A-quetel Agarro", "Calle de Dios #69-666");
	Vendedor* vendedor1 = new Vendedor("Juan", "Perez",12224, QBendicion);
	setVendedor(vendedor1);
	
	//Camisas
	//Manga Corta
	//Cuello Mao
	Prenda* camisaMC1 = PrendaFactory::crearCamisa(Calidad::STANDARD, 60000, 100, TipoCuello::MAO , TipoManga::CORTA);
	Prenda* camisaMC2 = PrendaFactory::crearCamisa(Calidad::PREMIUM, 60000, 100, TipoCuello::MAO, TipoManga::CORTA);

	//Cuallo Comun
	Prenda* camisaMC3 = PrendaFactory::crearCamisa(Calidad::STANDARD, 70000, 150, TipoCuello::COMUN, TipoManga::CORTA);
	Prenda* camisaMC4 = PrendaFactory::crearCamisa(Calidad::PREMIUM, 70000, 150, TipoCuello::COMUN, TipoManga::CORTA);

	//Manga Larga
	//Cuello Mao
	Prenda* camisaML1 = PrendaFactory::crearCamisa(Calidad::STANDARD, 50000, 75, TipoCuello::MAO, TipoManga::LARGA);
	Prenda* camisaML2 = PrendaFactory::crearCamisa(Calidad::PREMIUM, 50000, 75, TipoCuello::MAO, TipoManga::LARGA);

	//Cuello Comun
	Prenda* camisaML3 = PrendaFactory::crearCamisa(Calidad::STANDARD, 90000, 175, TipoCuello::COMUN, TipoManga::LARGA);
	Prenda* camisaML4 = PrendaFactory::crearCamisa(Calidad::PREMIUM, 90000, 175, TipoCuello::COMUN, TipoManga::LARGA);

	//Pantalones
	//Chupines
	Prenda* camisaPCH1 = PrendaFactory::crearPantalon(Calidad::STANDARD, 65000, 750, TipoPantalon::CHUPIN);
	Prenda* camisaPCH2 = PrendaFactory::crearPantalon(Calidad::PREMIUM, 65000, 750, TipoPantalon::CHUPIN);

	//Comunes 
	Prenda* camisaPCM1 = PrendaFactory::crearPantalon(Calidad::STANDARD, 75000, 250, TipoPantalon::COMUN);
	Prenda* camisaPCM2 = PrendaFactory::crearPantalon(Calidad::PREMIUM, 75000, 250, TipoPantalon::COMUN);

	//AgregarPrendas a Tienda
	QBendicion.agregarPrenda(camisaMC1);
	QBendicion.agregarPrenda(camisaMC2);
	QBendicion.agregarPrenda(camisaMC3);
	QBendicion.agregarPrenda(camisaMC4);
	QBendicion.agregarPrenda(camisaML1);
	QBendicion.agregarPrenda(camisaML2);
	QBendicion.agregarPrenda(camisaML3);
	QBendicion.agregarPrenda(camisaML4);
	QBendicion.agregarPrenda(camisaPCH1);
	QBendicion.agregarPrenda(camisaPCH2);
	QBendicion.agregarPrenda(camisaPCM1);
	QBendicion.agregarPrenda(camisaPCM2);
}

Presenter::~Presenter()
{
	delete m_vendedor;
};

Pantalon* Presenter::buscarPantalon(bool isChupin, bool isPremiun) {
	try {
		m_vendedor->buscarPantalon(isChupin , isPremiun);
	}
	catch (PrendaNotFound& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

Camisa* Presenter::buscarCamisa(bool isCuelloMao, bool isMangaCorta, bool isPremiun) {
	try {
		m_vendedor->buscarCamisa(isCuelloMao, isMangaCorta , isPremiun);
	}
	catch (PrendaNotFound& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void Presenter::hacerCotizacion(Prenda p ,int cantidad, int codigoCotizacion) {
	try {
		m_vendedor->hacerCotizacion(p, cantidad, codigoCotizacion);
	}
	catch (PrendaNoStock& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

string Presenter::verHistorialCotizaciones(){
	string result;
	for (const Cotizacion c : m_vendedor->getCotizaciones()) {
		result += c.toString() + "\n";
	}
	return result;
}
