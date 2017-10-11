#pragma once

#include <string>
#include <vector>
#include <map>

#include "Node.h"
#include "Attribute.h"


using namespace std;


class Element : public Node
{
public:

	// hold child nodes
	typedef vector<Node *> NodeList;

	typedef map<int, NodeList> MyMap;

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

	virtual ~Element();

	bool hasAttribute(string name) const;

	void setAttribute(string name, string value);

	void removeAttribute(string name);

	const AttrList &getAttributes() const;

	void appendChild(Node *newChild);

	void removeChild(Node *child);

	void insertChildBefore(Node *newChild, Node *beforeChild);

	const NodeList &getChildren() const;

};
