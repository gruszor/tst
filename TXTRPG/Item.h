#pragma once
#include <string>
using namespace std;
class Item
{
	string name;
	int buffType;
	int buffPower;
	int place;

public:
	Item();
	Item(string, int, int);
	~Item();
	string getName();
	void setName(string);
	int getBuffType();
	void setBuffType(int);
	int getBuffPower();
	void setBuffPower(int);
	int getPlace();
	void setPlace(int);
};

