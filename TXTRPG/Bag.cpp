#include "Bag.h"
using namespace std;


Bag::Bag()
{
}
Bag::Bag(Player * pl , int cap)
{
	this->owner = pl;
	this->capacity = cap;
}

Bag::~Bag()
{
}
void Bag::pushItem(Item it)
{
	if (size(container) < capacity)
	{
		this->container.push_back(it);
	}
}

void Bag::eraseItem(int pos)
{
	this->container.erase(container.begin() + pos);
}

void Bag::wearItem(Item &it)
{
	if (!it.getDressed())
	{
		owner->setStat(it.getBuffType(), it.getBuffPower());  //SMART POINTERY ASFUK!!!!!!!!! ZABAWA WSKAZNIKIEM https://www.learncpp.com/cpp-tutorial/103-aggregation/
		it.setDressed(true);
	}
}
void Bag::takeOffItem(Item &it)
{
	if (it.getDressed())
	{
		owner->setStat(it.getBuffType(), (-it.getBuffPower()));
		it.setDressed(false);
	}
}
Item &Bag::number2item(int index)
{
	Item &tmp = container[index];
	return tmp;
}
vector<string> Bag::info()
{
	string tmp;
	vector<string> data;
	for (int i = 0; i < size(container); i++)
	{
		tmp = to_string(container[i].getBuffPower()) + to_string(container[i].getBuffType()) + to_string(container[i].getDressed()) + container[i].getName();
		data.push_back(tmp);
	}
	return data;
}

int Bag::getCap()
{
	return this->capacity;
}
void Bag::setCap(int cap)
{
	this->capacity = cap;
}

struct myclass {
	bool operator() (Item it, Item it2) { return it.getBuffType() > it2.getBuffType(); }
} myobject;

struct myclass2 {
	bool operator() (Item it, Item it2) { return it.getBuffPower() > it2.getBuffPower(); }
} myobject2;

struct myclass3 {
	bool operator() (Item it, Item it2) { return it.getName() > it2.getName(); }   //comparing strings (?)
} myobject3;

void Bag::sorting(int k)
{
	switch (k)
	{
	case 1:
		sort(container.begin(), container.end(),myobject);
		break;
	case 2:
		sort(container.begin(), container.end(), myobject2);
		break;
	case 3:
		sort(container.begin(), container.end(), myobject3);
		break;
	}
}

