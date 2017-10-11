#include "Node.h"


Node::Node()
{
	parentElement = NULL;
	prevNode = NULL;
	nextNode = NULL;
}

Node::~Node()
{
}

void Node::setParentElement(Element *element)
{
	// TODO: remove this from old parent
	parentElement = element;
}

void Node::insertBefore(Node *node)
{
	if (node != prevNode)
	{
		if (prevNode != NULL)
			prevNode->nextNode = node;

		node->nextNode = this;
		prevNode = node;
	}
}

void Node::insertAfter(Node *node)
{
	if (node != nextNode)
	{
		if (nextNode != NULL)
			nextNode->prevNode = node;

		node->prevNode = this;
		nextNode = node;
	}
}

Element *Node::getParentElement()
{
	return parentElement;
}

Node *Node::getPrevNode()
{
	return prevNode;
}

Node *Node::getNextNode()
{
	return nextNode;
}

