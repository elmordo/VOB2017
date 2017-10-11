#pragma once

#include <string>

#include "Node.h"

using namespace std;


class Text : public Node
{

	// content
	string text;

public:

	Text();

	virtual ~Text();

	// get current text
	const string &getText() const;

	// set new text value
	void setText(const string &val);

};

