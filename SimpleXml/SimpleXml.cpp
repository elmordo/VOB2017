// SimpleXml.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "stdafx.h"
#include "factories.h"

using namespace std;

#define __win32__

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef __win32__
	WriterFactory *fac = new FileFactory();
#endif
#ifdef __unix__
	WriterFactory *fac = new ConsoleFactory();
#endif

	IXmlWriter *writer = fac->createWriter("");

	delete fac;
	return 0;
}

