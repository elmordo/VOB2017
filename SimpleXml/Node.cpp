#include "Node.h"
#include "Element.h"


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
	if (parentElement)
		parentElement->removeChild(this);

	parentElement = element;
}

void Node::setParentToNode(Element *element, Node *node)
{
	node->setParentElement(element);
}

void Node::insertAfterNode(Node *oldNode, Node *newNode)
{
	oldNode->insertAfter(newNode);
}

void Node::insertBeforeNode(Node *oldNode, Node *newNode)
{
	oldNode->insertBefore(newNode);
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

void Node::remove(Node *node)
{
	Node *prev = node->prevNode;
	Node *next = node->nextNode;

	if (prev) prev->nextNode = next;
	if (next) next->prevNode = prev;
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

