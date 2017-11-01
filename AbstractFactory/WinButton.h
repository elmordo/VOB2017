#pragma once

#include "IButton.h"


class WinButton : public IButton
{
public:
	WinButton();
	virtual ~WinButton();

	virtual void printLabel() const;
};

