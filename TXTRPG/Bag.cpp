#include "Bag.h"
using namespace std;


Bag::Bag()
{
}
Bag::Bag(Player * pl = nullptr)
{
	owner = pl;
}

Bag::~Bag()
{
}


void Bag::wearItem(Item it)
{
	if (!it.getDressed())
	{
		owner->setStat(it.getBuffType(), it.getBuffPower());  //SMART POINTERY ASFUK!!!!!!!!! ZABAWA WSKAZNIKIEM https://www.learncpp.com/cpp-tutorial/103-aggregation/
		it.setDressed(true);
	}
}
void Bag::takeOffItem(Item it)
{
	if (it.getDressed())
	{
		owner->setStat(it.getBuffType(), (-it.getBuffPower()));
		it.setDressed(false);
	}
}
Item Bag::number2item(int index)
{
	return container[index];
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

bool Bag::sortByType(Item it, Item it2)
{
	return it.getBuffType() < it2.getBuffType();
}
bool Bag::sortByPower(Item it, Item it2)
{
	return it.getBuffPower() < it2.getBuffPower();
}
//bool Bag::sortByDressed(Item it, Item it2)
//{
//
//}
void Bag::sorting(int k)
{
	switch (k)
	{
	case 1:
		sort(container.begin(), container.end(),sortByType);
		break;
	case 2:
		sort(container.begin(), container.end(), sortByPower);
		break;
	}
}























//void Bag::putOnEQ(Item it, Player &obj)
//{
//	if(size(equipment)<3)
//	this->equipment.push_back(it);
//	obj.setStat(it.getBuffType(), it.getBuffPower());
//
//}
//void Bag::putOnBP(Item it)
//{
//	if (size(equipment) < 10)
//	this->backpack.push_back(it);
//}
//void Bag::removeEQ(int x,Player &obj)
//{
//	Item it(equipment[x]);
//	obj.setStat(it.getBuffType(), (-it.getBuffPower()));
//	equipment.erase(equipment.begin() + x);
//}
//void Bag::removeBP(int x)
//{
//	backpack.erase(backpack.begin() + x);
//}
//void Bag::seeEQ()
//{
//	for (int i = 0; i < size(equipment); i++)
//	{
//		cout << equipment[i].getName() <<" /// "<< equipment[i].getBuffType() <<" -- "<< equipment[i].getBuffPower() << endl;
//	}
//
//}
//void Bag::seeBP()
//{
//	for (int i = 0; i < size(backpack); i++)
//	{
//		cout << backpack[i].getName() << " /// " << backpack[i].getBuffType() << " -- " << backpack[i].getBuffPower() << endl;
//	}
//
//}
//Item Bag::getItemEQ(int x)
//{
//	return equipment[x];
//}
//Item Bag::getItemBP(int x)
//{
//	return backpack[x];
//}
//vector<Item> Bag::getVectorEQ()
//{
//	return equipment;
//}
//vector<Item> Bag::getVectorBP()
//{
//	return backpack;
//}
