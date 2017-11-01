#pragma once

#include "IButton.h"

class GtkButton : public IButton
{
public:
	GtkButton();

	virtual ~GtkButton();

	virtual void printLabel() const;

};

