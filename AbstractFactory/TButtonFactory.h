#pragma once

#include "IButton.h"
#include "GtkButton.h"
#include "QtButton.h"
#include "WinButton.h"

class IFactory
{
public:

	virtual IButton *createButton() const = 0;
};


template<class T>
class TFactory : public IFactory
{

public:

	TFactory()
	{
	}

	virtual ~TFactory()
	{
	}

	IButton *createButton() const
	{
		return new T();
	}
};


typedef TFactory<GtkButton> GtkFactory;
typedef TFactory<QtButton> QtFactory;
typedef TFactory<WinButton> WinFactory;
