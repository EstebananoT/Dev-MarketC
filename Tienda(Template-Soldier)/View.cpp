#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "View.h"
#include "Presenter.h"
#include <algorithm>
#include <vector>

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
		menuCotizarPrenda();
		std::cin.get();
		exitCondition = false;
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
		std::system("cls");
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
 }

void View::runOptionPrenda(const char* option, bool& exitCondition)
{
	auto str_option = std::string(option);

	if (str_option == "1")
	{
		//menuPantalon();
		std::cin.get();
		exitCondition = false;
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