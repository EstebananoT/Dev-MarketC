#ifndef VIEW_H
#define VIEW_H

#include "IView.h"
#include "PrendaFactory.h"
#include <string>
#include "Vendedor.h"

class Presenter;

class View : public IView
{
private:
	Presenter* m_presenter;
	Vendedor* m_vendedor;
	Tienda* m_tienda;

	//Menus
	void showMainMenu();
	void menuCotizarPrenda();

	//Opciones
	void runOption(const char* option, bool& exitCondition);
	void runOptionPrenda(const char* option, bool& exitCondition);
public:
	View();
	~View() override;
	void showCotizaciones();
	
	
	void showText(const char* text) override;
	void showText(const std::string& text) override;

};
#endif //VIEW_H