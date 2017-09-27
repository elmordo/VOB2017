#include "moving_avg.h"

MovingAvgContext *createContext(size_t length)
{
	MovingAvgContext *context = (MovingAvgContext*)malloc(sizeof(MovingAvgContext));

	context->length = length;
	context->realLength = 0;
	context->buffer = (double*)calloc(length, sizeof(double));

	return context;
}

void destroyContext(MovingAvgContext *context)
{
	free(context->buffer);
	free(context);
}

double getAvgValue(const MovingAvgContext *context)
{
	if (context->realLength == 0)
		return 0.0;

	double sum = 0.0;

	for (size_t i = 0; i < context->realLength; ++i)
		sum += context->buffer[i];

	return sum / context->realLength;
}

void addValue(MovingAvgContext *context, double value)
{
	if (context->length == context->realLength)
		removeFirstValue(context);

	context->buffer[context->realLength] = value;
	++context->realLength;
}

void removeFirstValue(MovingAvgContext *context)
{
	if (context->realLength > 0)
	{
		for (size_t i = 1; i < context->realLength; ++i)
			context->buffer[i - 1] = context->buffer[i];

		--context->realLength;
	}
}
