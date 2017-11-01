#pragma once

#include <iostream>

#include "Player.h"

using namespace std;

class PlayerBuilder
{
	Player *instance;

	void assertInstanceIsSet() const;

	void reportCheater();

public:
	PlayerBuilder();
	virtual ~PlayerBuilder();

	void createInstance();

	void setName(const string &name);

	void setAge(int age);

	void setLevel(int level);

	Player *getInstance();

};

