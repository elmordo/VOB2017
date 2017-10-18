#pragma once

#include <iostream>

#include "AXmlWriter.h"

using namespace std;


class ConsoleWriter : public AXmlWriter
{

protected:

	virtual void storeXmlString(const string &xml) const;

public:
	ConsoleWriter();
	~ConsoleWriter();
};

