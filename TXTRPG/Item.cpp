#include "Item.h"



Item::Item()
{
}

Item::Item(string x, int y, int z,bool tf=0)
{
	this->name = x;
	this->buffType = y;
	this->buffPower = z;
	this->dressed = tf;
}
Item::~Item()
{
}

void Item::setName(string x)
{
	this->name = x;
}
string Item::getName()
{
	return name;
}
int Item::getBuffType()
{
	return buffType;
}
void Item::setBuffType(int x)
{
	this->buffType = x;
}
int Item::getBuffPower()
{
	return buffPower;
}
void Item::setBuffPower(int x)
{
	this->buffPower = x;
}
bool Item::getDressed()
{
	return dressed;
}
void Item::setDressed(bool tf)
{
	this->dressed = tf;
}



//int Item::getPlace()
//{
//	return place;
//}
//void Item::setPlace(int x)
//{
//	this->place = x;
//}