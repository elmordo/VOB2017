#include "Attribute.h"


Attribute::Attribute()
{
}


Attribute::~Attribute()
{
}

const string &Attribute::getName() const
{
	return name;
}

void Attribute::setName(const string &val)
{
	name = val;
}

const string &Attribute::getValue() const
{
	return value;
}

void Attribute::setValue(const string &val)
{
	value = val;
}
