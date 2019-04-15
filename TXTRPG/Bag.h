#pragma once
#include<vector>
#include<string>
#include<algorithm>    
#include<iostream>
#include<map>
#include"Item.h"
#include"Player.h"
using namespace std;

class Bag
{
	vector<Item> container;
	int capacity;
	Player *owner;
public:
	Bag();
	Bag(Player * pl = nullptr, int cap = 10);
	~Bag();
	int getCap();
	void setCap(int);
	void pushItem(Item it);
	void eraseItem(int pos);
	void wearItem(Item &);
	void takeOffItem(Item &);
	Item& number2item(int);
	vector<string> info();
	bool sortByType(Item it, Item it2);
	bool sortByPower(Item it, Item it2);
	bool sortByDressed(Item it, Item it2);
	void sorting(int);
};

