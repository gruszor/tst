#pragma once
#include "Player.h"
#include "Area.h"
#include"InOut.h"
#include "Bag.h"
#include "Item.h"
#include "npc2item.h"
#include <map>
#include <iostream>
#include <cstdlib>
#include <ctime>



class Game /*: public InOut*/
{
	static Game* instance;
	Game();

public:

	static Game* getInstance();

	~Game();
	void result2(Player &, Area &);
	void result(Player &,Area &);
	Area areaMaker(Area &,int);
	Player NPCmaker(Area);
	Bag &bagMaker(Area obj, Player * npc);
	bool fight(Player &gamer, Player *npc, int actionType, Bag &playerEq);
	bool trade(Player &gamer, Player *npc, int actionType, Bag & npcEq, Bag &playerEq);
	bool speak(Player &gamer, Player *npc, int actionType);
};




