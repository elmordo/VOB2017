// MovingAvgFunc.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "stdafx.h"
#include "moving_avg.h"

using namespace std;

void addAndPrint(MovingAvgContext *context, double val)
{
	addValue(context, val);
	cout << "Value is: " << getAvgValue(context) << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MovingAvgContext *context = createContext(3);

	addAndPrint(context, 1.0);
	addAndPrint(context, 2.0);
	addAndPrint(context, 3.0);
	addAndPrint(context, 4.0);
	addAndPrint(context, 5.0);

	destroyContext(context);

	return 0;
}
