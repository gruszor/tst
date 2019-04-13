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
	Bag(Player *);
	~Bag();
	void pushItem(Item it);
	void eraseItem(int pos);
	void wearItem(Item);
	void takeOffItem(Item);
	Item number2item(int);
	vector<string> info();
	bool sortByType(Item it, Item it2);
	bool sortByPower(Item it, Item it2);
	bool sortByDressed(Item it, Item it2);
	void sorting(int);
	//void sorting(string sortMethod){ sorted } ???




	//void putOnEQ(Item, Player &);
	//void putOnBP(Item);
	//void removeEQ(int ,Player &);
	//void removeBP(int x);
	//void seeEQ();
	//void seeBP();
	//Item getItemEQ(int);
	//Item getItemBP(int);
	//vector<Item> getVectorEQ();
	//vector<Item> getVectorBP();
	//void changeStats(Player);
	//void sorting(int k);


};

