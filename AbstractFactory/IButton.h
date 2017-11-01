#pragma once

#include <iostream>

using namespace std;


class IButton
{
public:
	IButton();
	virtual ~IButton();

	virtual void printLabel() const = 0;

};

