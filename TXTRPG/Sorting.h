#pragma once
#include<vector>
#include<string>
#include <algorithm>    
#include<iostream>
#include<map>
#include"Item.h"
#include"Player.h"
#include"Bag.h"
using namespace std;

class Sorting
{
public:
	Sorting();
	~Sorting();
	void srt(int,Bag &);
	bool f1(Item a, Item b);
	bool f2(Item a, Item b);
	bool f3(Item a, Item b);
};

