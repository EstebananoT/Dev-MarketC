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
	SetConsoleTitleW(L"The Soldier");
	setlocale(LC_ALL, "es_Es");
	m_presenter = new Presenter(this);
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
	Vendedor* v = m_presenter->getVendedor();
	Tienda* t = v->getTienda();
	do
	{
		std::system("cls");
		showText("-== COTIZADO - MENU PRINCIPAL ==-");
		showText("------------------------------------------------------------------");
		showText(t->getNombre()+":"+t->getDireccion() );
		showText("------------------------------------------------------------------");
		showText("Nombre y Apellido del vendedor:"+v->getNombre()+" "+v->getApellido());
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
		exitCondition = false;
	}
	else if (str_option == "2")
	{
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
