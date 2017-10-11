#pragma once

#include <cstddef>

class Element;


class Node
{

	// parent element or NULL if this is root
	Element *parentElement;

	// previous node or NULL if this is the first
	Node *prevNode;

	// next node or NULL if this is the last
	Node *nextNode;

protected:

	static void setParentToNode(Element *parent, Node *node);

	static void insertAfterNode(Node *oldNode, Node *newNode);

	static void insertBeforeNode(Node *oldNode, Node *newNode);

	// set new parent element
	void setParentElement(Element *element);

	// set new previous node (and update chain)
	void insertBefore(Node *node);

	// set new next node (and update chain)
	void insertAfter(Node *node);

	// remove node from siblings
	void remove(Node *node);

public:

	Node();

	virtual ~Node();

	Element *getParentElement();

	Node *getPrevNode();

	Node *getNextNode();

};
