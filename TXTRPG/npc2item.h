#pragma once
#include "Item.h"
#include"Player.h"
#include <cstdlib>
#include <ctime>

class npc2item 
{
	
public:
	Item itemFromNpc;
	npc2item();
	npc2item(Player &);
	~npc2item();
};

