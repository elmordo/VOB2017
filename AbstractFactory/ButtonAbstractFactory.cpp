#include "ButtonAbstractFactory.h"


ButtonAbstractFactory::ButtonAbstractFactory()
{
}


ButtonAbstractFactory::~ButtonAbstractFactory()
{
}

IFactory *ButtonAbstractFactory::getFactory(const string &uiLibType) const
{
	if (uiLibType == "gtk")
		return new GtkFactory();
	else if (uiLibType == "qt")
		return new QtFactory();
	else if (uiLibType == "win")
		return new WinFactory();
	else
		throw "Unsupported UI lib type";
}

