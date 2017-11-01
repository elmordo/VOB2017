#include "PlayerBuilder.h"

void PlayerBuilder::assertInstanceIsSet() const
{
	if (instance == NULL)
		throw "Instance is not set";
}

void PlayerBuilder::reportCheater()
{
	cout << "CHEATER! IT IS CHEATER!!!" << endl;
}

PlayerBuilder::PlayerBuilder()
{
	instance = NULL;
}


PlayerBuilder::~PlayerBuilder()
{
}

void PlayerBuilder::createInstance()
{
	if (instance)
		delete instance;

	instance = new Player();
}

void PlayerBuilder::setName(const string &name)
{
	assertInstanceIsSet();
	instance->setName(name);
}


void PlayerBuilder::setAge(int age)
{
	assertInstanceIsSet();
	instance->setAge(age);
}

void PlayerBuilder::setLevel(int level)
{
	assertInstanceIsSet();
	if (level != 1)
		reportCheater();

	instance->setLevel(level);
}

Player *PlayerBuilder::getInstance()
{
	Player *result = instance;
	instance = NULL;
	return result;
}

