#pragma once

#include "Element.h"


class IXmlWriter
{
public:

	virtual void saveXml(const Element *rootElement) const = 0;

};
