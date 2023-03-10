#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "View.h"
#include "Presenter.h"
#include <algorithm>
#include <vector>
#include <ctype.h>

const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opción ingresada es inválida, por favor reintente.";

View::View()
{
	SetConsoleTitleW(L"SHOP");
	setlocale(LC_ALL, "es_Es");
	m_presenter = new Presenter(this);

	m_vendedor = m_presenter->getVendedor();

	m_tienda = m_presenter->getTienda();

	showMainMenu();
}

View::~View()
{
	delete m_presenter;
}

void View::showText(const char* text)
{
	std::cout << text << std::endl;
}

// Polymorphism Rules, BUT DRY? 
void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}


void View::showMainMenu()
{
	std::string option;
	bool exitCondition = false;
	do
	{
		std::system("cls");
		showText("-== COTIZADO - MENU PRINCIPAL ==-");
		showText("------------------------------------------------------------------");
		showText(m_tienda->getNombre() + ":" + m_tienda->getDireccion());
		showText("------------------------------------------------------------------");
		showText("Nombre y Apellido del vendedor:" + m_vendedor->getNombre() + " " + m_vendedor->getApellido());
		showText("SELECCIONE UNA OPCION DEL MENU");
		showText(" ");
		showText("1) Historial de Cotizaciones");
		showText("2) Realizar Cotizaciones");
		showText("X) Salir");
		std::cin >> option;
		std::system("cls");
		runOption(option.c_str(), exitCondition);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
	} while (!exitCondition);
}

void View::runOption(const char* option, bool& exitCondition)
{
	auto str_option = std::string(option);

	if (str_option == "1")
	{
		string historial = m_presenter->verHistorialCotizaciones();
		showText(historial);
		std::cin.get();
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
		exitCondition = false;
		menuCotizarPrenda();
	}
	else if (str_option == "x" || str_option == "X")
	{
		std::cout.flush();
		exit(EXIT_SUCCESS);
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
	}
}
void View::menuCotizarPrenda()
{
	

	std::string option;
	bool exitCondition = false;
	do
	{
		//std::system("cls");
		showText("-== COTIZAR PRENDA ==-");
		showText("------------------------------------------------------------------");
		showText("Atendido por :" + m_vendedor->getNombre() + " " + m_vendedor->getApellido());
		showText("Seleccione el tipo de producto que desea cotizar:");
		showText(" ");
		showText("1) Pantalon");
		showText("2) Camisa");
		showText("X) Volver al menu principal");
		std::cin >> option;
		std::system("cls");
		runOptionPrenda(option.c_str(), exitCondition);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
	} while (!exitCondition);

	showMainMenu();
 }

void View::runOptionPrenda(const char* option, bool& exitCondition)
{
	auto str_option = std::string(option);

	if (str_option == "1")
	{
		menuPantalon();
		exitCondition = true;
	}
	else if (str_option == "2")
	{
		//menuCamisa();
		std::cin.get();
		exitCondition = false;
	}
	else if (str_option == "x" || str_option == "X")
	{
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
		exitCondition = false;
		//return to mainMenu
		showMainMenu();
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
	}
}

void View::menuPantalon() {
	std::string option;
	bool exitCondition = false;
	do
	{
		//std::system("cls");
		showText("-== COTIZAR PRENDA ==-");
		showText("------------------------------------------------------------------");
		showText("Atendido por :" + m_vendedor->getNombre() + " " + m_vendedor->getApellido());
		showText("El pantalon a cotizar, Es chupin?");
		showText(" ");
		showText("1) Si");
		showText("2) No");
		showText("X) Volver al menu principal");
		std::cin >> option;
		std::system("cls");
		if (option == "1")
		{

			//std::system("cls");
			//Busca la prenda en la Tienda
			bool isPremiun = menuPremiun();
			Pantalon* pantalonAcotizar = m_presenter->buscarPantalon(true,isPremiun);
			if (pantalonAcotizar != nullptr) {
				showText("Cantidad de Unidades: " + std::to_string(pantalonAcotizar->getCantidadUnidades()));
			}
			else {
				showText("Error: objeto pantalonAcotizar no válido.");
			}
			//Setea el valor dado por el usuario a la prenda para poder hacer la cotizacion
			double valorPrenda = precioPrenda();
			
			pantalonAcotizar->setPrecioUnitario(valorPrenda);
			
			showText("Cantidad de Unidades :"+pantalonAcotizar->getCantidadUnidades());
			int cantidadPrenda = cantidadPrendas();
			//La cotizada me la ag*rra
			//DIOS MIO QUE ACOPLADO ESTA ESTE CODIGO :'0
			try {
				Cotizacion c = m_presenter->hacerCotizacionPantalon(pantalonAcotizar, cantidadPrenda);
				showText("Cotizacion realizada con exito!");
				showText(c.toString());
				std::cin.get();
				exitCondition = true;
			}
			catch (PrendaNoStock& e) {
				showText("Lo sentimos no pudimos realizar la cotizacion...");
				showText("Volviendo al menu principal....");
				std::cin.get();
				exitCondition = true;
			}
			
		}
		else if (option == "2")
		{
			//std::system("cls");
			//Busca la prenda en la Tienda
			bool isPremiun = menuPremiun();
			Pantalon* pantalonAcotizar = m_presenter->buscarPantalon(false, isPremiun);
			if (pantalonAcotizar != nullptr) {
				showText("Cantidad de Unidades: " + std::to_string(pantalonAcotizar->getCantidadUnidades()));
			}
			else {
				showText("Error: objeto pantalonAcotizar no válido.");
			}
			//Setea el valor dado por el usuario a la prenda para poder hacer la cotizacion
			double valorPrenda = precioPrenda();

			pantalonAcotizar->setPrecioUnitario(valorPrenda);

			showText("Cantidad de Unidades :" + pantalonAcotizar->getCantidadUnidades());
			int cantidadPrenda = cantidadPrendas();
			//La cotizada me la ag*rra
			//DIOS MIO QUE ACOPLADO ESTA ESTE CODIGO :'0
			try {
				Cotizacion c = m_presenter->hacerCotizacionPantalon(pantalonAcotizar, cantidadPrenda);
				showText("Cotizacion realizada con exito!");
				showText(c.toString());
				std::cin.get();
				exitCondition = true;
			}
			catch (PrendaNoStock& e) {
				showText("Lo sentimos no pudimos realizar la cotizacion...");
				showText("Volviendo al menu principal....");
				std::cin.get();
				exitCondition = true;
			}
		}
		else if (option == "x" || option == "X")
		{
			showText("");
			showText(ANY_KEY_MESSAGE);
			std::cin.get();
			exitCondition = false;
			//return to mainMenu
			showMainMenu();
		}
		else
		{
			showText(INVALID_OPTION_MESSAGE);
			std::cin.get();
			exitCondition = false;
		}
	} while (!exitCondition);
}


bool View::menuPremiun() {
	std::string option;
	bool exitCondition = false;
	bool isPremiun;
	do
	{
		//std::system("cls");
		showText("-== COTIZAR PRENDA ==-");
		showText("------------------------------------------------------------------");
		showText("Atendido por :" + m_vendedor->getNombre() + " " + m_vendedor->getApellido());
		showText("Seleccione la calidad de la prenda");
		showText(" ");
		showText("1) Standar");
		showText("2) Premuin");
		showText("X) Volver al menu principal");
		std::cin >> option;
		if (option == "1")
		{
			isPremiun = true;
			exitCondition = true;
		}
		else if (option == "2")
		{
			isPremiun = false;
			exitCondition = true;
		}
		else if (option == "x" || option == "X")
		{
			showText("");
			showText(ANY_KEY_MESSAGE);
			std::cin.get();
			exitCondition = false;
			//return to mainMenu
			showMainMenu();
		}
		else
		{
			showText(INVALID_OPTION_MESSAGE);
			std::cin.get();
			exitCondition = false;
		}
	} while (!exitCondition);

	return isPremiun;
}

double View::precioPrenda() {
	double num;
	bool valido;
	do {
		//std::system("cls");
		showText("-== COTIZAR PRENDA ==-");
		showText("------------------------------------------------------------------");
		showText("Atendido por :" + m_vendedor->getNombre() + " " + m_vendedor->getApellido());
		showText("Ingrese el precio unitario de la prenda a cotizar");
		showText(" ");
		cin >> num;

		if (cin.fail()) {
			cout << "Error: entrada no valida." << endl;
			cin.clear();
			valido = false;
		}
		else {
			valido = true;
		}
	} while (!valido);

	return num;
}

int View::cantidadPrendas() {
	double num;
	bool valido;
	do {
		showText("-== COTIZAR PRENDA ==-");
		showText("------------------------------------------------------------------");
		showText("Atendido por :" + m_vendedor->getNombre() + " " + m_vendedor->getApellido());
		showText("Ingrese la cantidad de prendas a cotizar");
		showText(" ");
		cin >> num;

		if (cin.fail()) {
			cout << "Error: entrada no valida." << endl;
			cin.clear();
			valido = false;
		}
		else {
			valido = true;
		}
	} while (!valido);

	return num;
}