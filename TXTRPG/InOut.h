#pragma once

#include <iostream>
#include <conio.h>

#include "Game.h"
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
	Area mapManager(Area prevArea, Game game);
	void actionManager(Area &obj, Player &gamer, Game game, Bag &plEq);
	void bagManager(Bag &eq);
};

