// Builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "PlayerBuilder.h"


int _tmain(int argc, _TCHAR* argv[])
{
	PlayerBuilder builder;
	builder.createInstance();

	int buffer;
	string strBuffer;

	cout << "Your name: ";
	cin >> strBuffer;
	builder.setName(strBuffer);

	cout << "Your age: ";
	cin >> buffer;
	builder.setAge(buffer);

	cout << "Your level: ";
	cin >> buffer;
	builder.setLevel(buffer);

	Player *instance = builder.getInstance();

	return 0;
}
