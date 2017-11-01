#include "Player.h"


Player::Player()
{
	age = 18;
	level = 1;
}


Player::~Player()
{
}

const string &Player::getName() const
{
	return name;
}

void Player::setName(const string &val)
{
	name = val;
}

int Player::getAge() const
{
	return age;
}

void Player::setAge(int val)
{
	age = val;
}

int Player::getLevel() const
{
	return level;
}

void Player::setLevel(int val)
{
	level = val;
}
