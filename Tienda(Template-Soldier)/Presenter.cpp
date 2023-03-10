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
	Tienda* QBendicion = new Tienda("A-quetel Agarro", "Calle de Dios #69-666");
	std::string nombre = "Juan";
	std::string apellido = "Perez";
	Vendedor* vendedor1 = new Vendedor(nombre, apellido, 12224, QBendicion);
	

	//Objetos Calidad :D
	Calidad standard = Calidad::STANDARD;
	Calidad premiun = Calidad::PREMIUM;

	//Objetos Tipo Cuello
	TipoCuello mao = TipoCuello::MAO;
	TipoCuello comun = TipoCuello::COMUN;

	//Objetos Tipo Manga
	TipoManga corta = TipoManga::CORTA;
	TipoManga larga = TipoManga::LARGA;


	//Objetos Tipo Pantalon
	TipoPantalon chupin = TipoPantalon::CHUPIN;
	TipoPantalon pantalonComun = TipoPantalon::COMUN;


	//Camisas
	//Manga Corta
	//Cuello Mao
	Camisa camisaMC1 = PrendaFactory::crearCamisa(standard, 60000, 100, mao, corta);
	Camisa camisaMC2 = PrendaFactory::crearCamisa(premiun, 60000, 100, mao, corta);

	//Cuallo Comun
	Camisa camisaMC3 = PrendaFactory::crearCamisa(standard, 70000, 150, comun, corta);
	Camisa camisaMC4 = PrendaFactory::crearCamisa(premiun, 70000, 150, comun, corta);

	//Manga Larga
	//Cuello Mao
	Camisa camisaML1 = PrendaFactory::crearCamisa(standard, 50000, 75, mao, larga);
	Camisa camisaML2 = PrendaFactory::crearCamisa(premiun, 50000, 75, mao, larga);

	//Cuello Comun
	Camisa camisaML3 = PrendaFactory::crearCamisa(standard, 90000, 175, comun, larga);
	Camisa camisaML4 = PrendaFactory::crearCamisa(premiun, 90000, 175, comun, larga);

	//Pantalones
	//Chupines
	Pantalon pantalonPCH1 = PrendaFactory::crearPantalon(standard, 65000, 750, chupin);
	Pantalon pantalonPCH2 = PrendaFactory::crearPantalon(premiun, 68000, 750, chupin);

	//Comunes 
	Pantalon pantalonPCM1 = PrendaFactory::crearPantalon(standard, 75000, 250, pantalonComun);
	Pantalon pantalonPCM2 = PrendaFactory::crearPantalon(premiun, 75000, 250, pantalonComun);

	

	//AgregarPrendas a Tienda
	QBendicion->agregarCamisa(camisaMC1);
	QBendicion->agregarCamisa(camisaMC2);
	QBendicion->agregarCamisa(camisaMC3);
	QBendicion->agregarCamisa(camisaMC4);
	QBendicion->agregarCamisa(camisaML1);
	QBendicion->agregarCamisa(camisaML2);
	QBendicion->agregarCamisa(camisaML3);
	QBendicion->agregarCamisa(camisaML4);
	QBendicion->agregarPantalon(pantalonPCH1);
	QBendicion->agregarPantalon(pantalonPCH2);
	QBendicion->agregarPantalon(pantalonPCM1);
	QBendicion->agregarPantalon(pantalonPCM2);

	setVendedor(vendedor1);
}

Presenter::~Presenter()
{
	delete m_vendedor;
};

Pantalon* Presenter::buscarPantalon(bool isChupin, bool isPremiun) {

	
	try {
		return m_vendedor->buscarPantalon(isChupin, isPremiun);
	}
	catch (PrendaNotFound e) {
		std::cout << "Error: " << e.what() << std::endl;
		return nullptr;
	}
}

Camisa* Presenter::buscarCamisa(bool isCuelloMao, bool isMangaCorta, bool isPremiun) {
	try {
		return m_vendedor->buscarCamisa(isCuelloMao, isMangaCorta, isPremiun);
	}
	catch (PrendaNotFound& e) {
		std::cout << "Error: " << e.what() << std::endl;

		return nullptr;
	}
}

Cotizacion Presenter::hacerCotizacionPantalon(Pantalon* p, int cantidad, int codigoCotizacion) {
	try {
		return m_vendedor->hacerCotizacionPantalon(p, cantidad, codigoCotizacion);
		
	}
	catch (PrendaNoStock& e) {
		std::cout << "Error: " << e.what() << std::endl;
		Cotizacion c;
		return c;
	}
}

Cotizacion Presenter::hacerCotizacionCamisa(Camisa* c, int cantidad, int codigoCotizacion) {
	try {
		return m_vendedor->hacerCotizacionCamisa(c, cantidad, codigoCotizacion);

	}
	catch (PrendaNoStock& e) {
		std::cout << "Error: " << e.what() << std::endl;
		Cotizacion c;
		return c;
	}
}

string Presenter::verHistorialCotizaciones() {
	string result;
	if (m_vendedor->getCotizaciones().empty()) {
		result = "Ups! El vendedor : " + m_vendedor->getNombre() + " No tiene cotizaciones aun :D";
	}
	for (Cotizacion c : m_vendedor->getCotizaciones()) {
		result += c.toString() + "\n";
	}
	return result;
}
