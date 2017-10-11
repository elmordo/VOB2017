#include "Element.h"


Element::Element()
{
}

Element::Element(const string &type)
{
	this->type = type;
}


Element::~Element()
{
}

bool Element::hasAttribute(const string &name) const
{
	// function find is part of STL (algorithms)
	return find(attributes.cbegin(), attributes.cend(), name) != attributes.cend();
}

void Element::setAttribute(const string &name, const string &value)
{
	Attribute &attr = getAttribute(name);
	attr.setValue(value);
}

Attribute &Element::getAttribute(const string &name)
{
	AttrList::iterator pos = find(attributes.begin(), attributes.end(), name);

	if (pos == attributes.end())
	{
		Attribute attr;
		attr.setName(name);
		attributes.push_back(attr);
		pos = --attributes.end();
	}

	return *pos;
}

void Element::removeAttribute(const string &name)
{
	AttrList::iterator pos = find(attributes.begin(), attributes.end(), name);
	attributes.erase(pos, attributes.end());
}

const Element::AttrList &Element::getAttributes() const
{
	return attributes;
}

void Element::appendChild(Node *newChild)
{
	setParentToNode(this, newChild);
	childNodes.push_back(newChild);

	if (childNodes.size())
		insertAfterNode(childNodes.back(), newChild);
}

void Element::removeChild(Node *child)
{
	NodeList::iterator pos = find(childNodes.begin(), childNodes.end(), child);

	if (pos != childNodes.end())
	{
		childNodes.erase(pos);
		remove(child);
		setParentToNode(NULL, child);
	}
}

void Element::insertChildBefore(Node *newChild, Node *beforeChild)
{
	NodeList::iterator pos = find(childNodes.begin(), childNodes.end(), beforeChild);

	if (pos != childNodes.end())
	{
		setParentToNode(this, newChild);
		insertBeforeNode(*pos, newChild);
		childNodes.insert(pos, newChild);
	}
}

const Element::NodeList &Element::getChildren() const
{
	return childNodes;
}

const string &Element::getType() const
{
	return type;
}

