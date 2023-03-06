#ifndef IVIEW_H
#define IVIEW_H
#include <string>


class IView
{
public:
	virtual ~IView() = default;
	virtual void showText(const char* text) = 0;
	virtual void showText(const std::string& text) = 0;
};
#endif // IVIEW_H

