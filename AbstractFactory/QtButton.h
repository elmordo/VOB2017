#pragma once

#include "IButton.h"

class QtButton : public IButton
{
public:
	QtButton();
	virtual ~QtButton();

	virtual void printLabel() const;
};

