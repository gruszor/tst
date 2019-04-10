#include "Bag.h"
using namespace std;


Bag::Bag()
{
}


Bag::~Bag()
{
}
void Bag::putOnEQ(Item it, Player &obj)
{
	if(size(equipment)<3)
	this->equipment.push_back(it);
	obj.setStat(it.getBuffType(), it.getBuffPower());

}
void Bag::putOnBP(Item it)
{
	if (size(equipment) < 10)
	this->backpack.push_back(it);
}
void Bag::removeEQ(int x,Player &obj)
{
	Item it(equipment[x]);
	obj.setStat(it.getBuffType(), (-it.getBuffPower()));
	equipment.erase(equipment.begin() + x);
}
void Bag::removeBP(int x)
{
	backpack.erase(backpack.begin() + x);
}
void Bag::seeEQ()
{
	for (int i = 0; i < size(equipment); i++)
	{
		cout << equipment[i].getName() <<" /// "<< equipment[i].getBuffType() <<" -- "<< equipment[i].getBuffPower() << endl;
	}

}
void Bag::seeBP()
{
	for (int i = 0; i < size(backpack); i++)
	{
		cout << backpack[i].getName() << " /// " << backpack[i].getBuffType() << " -- " << backpack[i].getBuffPower() << endl;
	}

}
Item Bag::getItemEQ(int x)
{
	return equipment[x];
}
Item Bag::getItemBP(int x)
{
	return backpack[x];
}
vector<Item> Bag::getVectorEQ()
{
	return equipment;
}
vector<Item> Bag::getVectorBP()
{
	return backpack;
}
