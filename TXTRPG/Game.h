#pragma once
#include "Player.h"
#include "Area.h"
#include"InOut.h"
#include "Bag.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Game : public InOut
{
	static Game* instance;
	Game();

public:

	static Game* getInstance();

	~Game();
	void result2(Player &, Area &);
	void result(Player &,Area &);
	Area areaMaker(Area &,int);
	Player* NPCmaker(Area);
	Bag &bagMaker(Area);
};




