// AbstractFactory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ButtonAbstractFactory.h"


int _tmain(int argc, _TCHAR* argv[])
{
	ButtonAbstractFactory abstractFactory;

	IButton *gtkBtn = abstractFactory.getFactory("gtk")->createButton();
	IButton *qtBtn = abstractFactory.getFactory("qt")->createButton();
	IButton *winBtn = abstractFactory.getFactory("win")->createButton();

	//IButton *wxBtn = abstractFactory.getFactory("wx")->createButton();

	gtkBtn->printLabel();
	qtBtn->printLabel();
	winBtn->printLabel();

	return 0;
}
