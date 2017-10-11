#pragma once

#include <string>

#include "Node.h"

using namespace std;


class Attribute : public Node
{

	// name of the attribute
	string name;

	// value of the attribute
	string value;

public:

	Attribute();

	virtual ~Attribute();

	const string &getName() const;

	void setName(const string &val);

	const string &getValue() const;

	void setValue(const string &val);

};

