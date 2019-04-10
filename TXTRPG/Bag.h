#pragma once
#include<vector>
#include<string>
#include <algorithm>    
#include<iostream>
#include<map>
#include"Item.h"
#include"Player.h"
using namespace std;

class Bag
{
	vector<Item> equipment;
	vector<Item> backpack;
public:
	Bag();
	~Bag();
	void putOnEQ(Item, Player &);
	void putOnBP(Item);
	void removeEQ(int ,Player &);
	void removeBP(int x);
	void seeEQ();
	void seeBP();
	Item getItemEQ(int);
	Item getItemBP(int);
	vector<Item> getVectorEQ();
	vector<Item> getVectorBP();
	void changeStats(Player);
	void sorting(int k);


};

