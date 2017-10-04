// MovingAvgObj.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stdafx.h"
#include "MovingAvg.h"

using namespace std;

void addAndPrint(MovingAvg &context, double val)
{
	context.addValue(val);
	cout << "Value is: " << context.getAverageValue() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MovingAvg avg(3);

	addAndPrint(avg, 1.0);
	addAndPrint(avg, 2.0);
	addAndPrint(avg, 3.0);
	addAndPrint(avg, 4.0);
	addAndPrint(avg, 5.0);

	return 0;
}
