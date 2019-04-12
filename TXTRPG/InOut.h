#pragma once

#include <iostream>
#include <conio.h>

#include "Bag.h"
#include "Player.h"
#include "Area.h"

using namespace std;

class InOut
{
public:
	InOut();
	~InOut();
	void createPlayer(Player & gracz);
	void createGraphicOverlay();
	void createInfoBar(Player & gracz, Area & obj);
	string pressButton(string, string);
	void map();
	void playerMenu(Player & obj, Bag & bag);
	void txt();
	void fight(Player &, Player &);
	void nothing();
	void trade();
	void speak();
};

