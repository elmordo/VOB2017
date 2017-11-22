// PoolExample.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "stdafx.h"
#include "FixedPool.h"
#include "DynamicPool.h"


void cloneAndDestroy(IPool *pool)
{
	IPool *cloned = pool->clone();
	delete cloned;
}


int _tmain(int argc, _TCHAR* argv[])
{
	DynamicPool fixedHotel;
	cloneAndDestroy(&fixedHotel);

	Room *r1 = fixedHotel.acquireRoom();
	Room *r2 = fixedHotel.acquireRoom();
	Room *r3 = fixedHotel.acquireRoom();
	Room *r4 = fixedHotel.acquireRoom();
	Room *r5 = fixedHotel.acquireRoom();

	fixedHotel.releaseRoom(r1);

	try
	{
		Room *r6 = fixedHotel.acquireRoom();
	}
	catch (int e)
	{
		cout << "TEST PROSEL" << endl;
	}

	return 0;
}

