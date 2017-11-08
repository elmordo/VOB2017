// ServiceManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <functional>
#include <memory>

using namespace std;

class MyClass
{
public:

	int x;

	MyClass()
	{}

	virtual ~MyClass()
	{
		cout << "delted" << endl;
	}

	void printX()
	{
		cout << x << endl;
	}

};

void printConst()
{
	cout << 800 << endl;
}


typedef function<void ()> PrintFn;


int _tmain(int argc, _TCHAR* argv[])
{
	MyClass mc;
	mc.x = 100;

	shared_ptr<MyClass> cls1(new MyClass());
	shared_ptr<MyClass> cls2 = cls1;

	mc.printX();

	PrintFn myFn = printConst;
	myFn();

	PrintFn myFn2 = bind(&MyClass::printX, mc);
	myFn2();

	return 0;
}
