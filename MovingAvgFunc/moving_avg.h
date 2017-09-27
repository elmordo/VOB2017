#pragma once

#include <cstdlib>
#include <cstddef>

using namespace std;

struct MovingAvgContext
{

	/**
	 * @brief length of buffer
	 */
	size_t length;

	/**
	 * @brief real number of stored values
	 */
	size_t realLength;
	
	/**
	 * @brief buffer
	 */
	double *buffer;

};

MovingAvgContext *createContext(size_t length);

void destroyContext(MovingAvgContext *context);

double getAvgValue(const MovingAvgContext *context);

void addValue(MovingAvgContext *context, double value);

void removeFirstValue(MovingAvgContext *context);
