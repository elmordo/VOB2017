#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "Node.h"
#include "Attribute.h"


using namespace std;


class Element : public Node
{
public:

	// hold child nodes
	typedef vector<Node *> NodeList;

	// hold attributes related to element
	typedef vector<Attribute> AttrList;

private:

	// set of the node's attributes
	AttrList attributes;

	// content between <tag> and </tag>
	NodeList childNodes;

	// name of tag (HTML, HEAD,...)
	string type;

public:

	Element();

	Element(const string &type);

	virtual ~Element();

	// return true if element has attribute of the name
	bool hasAttribute(const string &name) const;

	// set value of the attribute
	void setAttribute(const string &name, const string &value);

	// get attribute by given name. If attribute is not set, create it
	Attribute &getAttribute(const string &name);

	void removeAttribute(const string &name);

	const AttrList &getAttributes() const;

	void appendChild(Node *newChild);

	void removeChild(Node *child);

	void insertChildBefore(Node *newChild, Node *beforeChild);

	const NodeList &getChildren() const;

	const string &getType() const;

};
