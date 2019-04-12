#pragma once
#include <string>
using namespace std;
class Item
{
	string name;
	int buffType;
	int buffPower;
	bool dressed;

public:
	Item();
	Item(string, int, int,bool);
	~Item();
	string getName();
	void setName(string);
	int getBuffType();
	void setBuffType(int);
	int getBuffPower();
	void setBuffPower(int);
	void setDressed(bool);
	bool getDressed();

};

