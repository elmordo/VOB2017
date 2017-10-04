#include "MovingAvg.h"

void MovingAvg::allocateDataItems()
{
	ValueItem *lastItem = NULL;

	for (size_t i = 0; i < length; ++i)
	{
		ValueItem *current = new ValueItem();
		current->value = 0.0;
		current->prev = lastItem;
		current->next = NULL;

		if (lastItem != NULL)
			lastItem->next = current;
		else
			first = current;

		lastItem = current;
	}

	last = lastItem;
}

void MovingAvg::deallocateDataItems()
{
	ValueItem *current = first;

	while (current != NULL)
	{
		ValueItem *next = current->next;
		delete current;
		current = next;
	}
}

MovingAvg::ValueItem *MovingAvg::nextItem()
{
	ValueItem *newFirst = last;

	last = newFirst->prev;
	last->next = NULL;
	newFirst->next = first;
	newFirst->prev = NULL;
	first->prev = newFirst;
	first = newFirst;

	return newFirst;
}

MovingAvg::MovingAvg()
{
	length = realLength = 0;
	first = last = NULL;
}

MovingAvg::MovingAvg(size_t length)
{
	this->length = length;
	realLength = 0;

	first = last = NULL;
	allocateDataItems();
}

MovingAvg::~MovingAvg()
{
	if (first != NULL)
		deallocateDataItems();
}

void MovingAvg::addValue(double value)
{
	if (length > 0)
	{
		ValueItem *item = nextItem();

		item->value = value;

		if (realLength < length)
			++realLength;
	}
}

double MovingAvg::getAverageValue() const
{
	double sum = 0.0,
		den = realLength,
		avg = 0.0;
	
	if (realLength > 0)
	{
		const ValueItem *current = first;

		for (size_t i = 0; i < realLength; ++i)
		{
			sum += current->value;
			current = current->next;
		}

		avg = sum / den;
	}

	return avg;
}

size_t MovingAvg::getLength() const
{
	return length;
}

size_t MovingAvg::getRealLength() const
{
	return realLength;
}
