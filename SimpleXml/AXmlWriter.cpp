#include "AXmlWriter.h"


string AXmlWriter::toString(const Attribute *attr) const
{
	return attr->getName() + "=\"" + attr->getValue() + "\"";
}

string AXmlWriter::nodeToString(const Node *node) const
{
	string result;
	const Element *childElelement = dynamic_cast<const Element *>(node);
	const Text *childText = dynamic_cast<const Text *>(node);

	if (childText != NULL)
	{
		result += childText->getText();
	}
	else if (childElelement != NULL)
	{
		result += toString(childElelement);
	}
	else
	{
		throw "Unsupported node type";
	}

	return result;
}

string AXmlWriter::childrenToString(const Element::NodeList &children) const
{
	string result;

	for (auto c : children)
	{
		result += nodeToString(c);
	}

	return result;
}


string AXmlWriter::attributesToString(const Element::AttrList &attrs) const
{
	string result;

	for (auto a : attrs)
	{
		result += " " + toString(&a);
	}

	return result;
}


string AXmlWriter::toString(const Element *rootElement) const
{
	string result = "<" + rootElement->getType() + " ";
	result += attributesToString(rootElement->getAttributes());
	result += ">";
	result += childrenToString(rootElement->getChildren());
	result += "</" + rootElement->getType() + ">";

	return result;
}


AXmlWriter::AXmlWriter()
{
}


AXmlWriter::~AXmlWriter()
{
}

void AXmlWriter::saveXml(const Element *rootElement) const
{
	string xml = toString(rootElement);
	storeXmlString(xml);
}
