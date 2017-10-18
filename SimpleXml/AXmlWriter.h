#pragma once

#include <string>

#include "IXmlWriter.h"
#include "Text.h"

using namespace std;


class AXmlWriter : public IXmlWriter
{

	string toString(const Attribute *attr) const;

	string toString(const Element *rootElement) const;

	string childrenToString(const Element::NodeList &children) const;

	string nodeToString(const Node *node) const;

	string attributesToString(const Element::AttrList &attrs) const;

protected:

	virtual void storeXmlString(const string &xml) const = 0;

public:
	
	AXmlWriter();

	virtual ~AXmlWriter();

	virtual void saveXml(const Element *rootElement) const;

};

