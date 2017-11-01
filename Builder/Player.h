#pragma once

#include <string>

using namespace std;


class Player
{

	string name;

	int age;

	int level;

public:
	Player();
	virtual ~Player();

	const string &getName() const;

	void setName(const string &val);

	int getAge() const;

	void setAge(int val);

	int getLevel() const;

	void setLevel(int val);

};

