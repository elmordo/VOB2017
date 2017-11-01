#pragma once

#include "TButtonFactory.h"


class ButtonAbstractFactory
{
public:

	ButtonAbstractFactory();

	virtual ~ButtonAbstractFactory();

	IFactory *getFactory(const string &uiLibType) const;
};

