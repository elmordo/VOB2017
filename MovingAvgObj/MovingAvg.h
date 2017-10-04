#pragma once

#include <cstdlib>


class MovingAvg
{

	struct ValueItem
	{

		double value;

		ValueItem *next;

		ValueItem *prev;

	};

	size_t length;

	size_t realLength;

	ValueItem *first;

	ValueItem *last;

	ValueItem *nextItem();

	// data and last are NULL
	void allocateDataItems();

	// deallocate data items and set first and last to NULL
	void deallocateDataItems();

public:
	
	MovingAvg();

	MovingAvg(size_t length);

	virtual ~MovingAvg();

	void addValue(double value);

	double getAverageValue() const;

	size_t getLength() const;

	size_t getRealLength() const;

};
