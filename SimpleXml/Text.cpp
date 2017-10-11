#include "Text.h"


Text::Text()
{
}


Text::~Text()
{
}


const string &Text::getText() const
{
	return text;
}

void Text::setText(const string &val)
{
	text = val;
}

