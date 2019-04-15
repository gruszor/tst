#include "npc2item.h"


npc2item::npc2item()
{

}
npc2item::npc2item(Player &npc)
{
	srand(time(NULL));
	Item it;
	int r = rand()%10;
	it.setName(npc.getName());
	it.setBuffType(r);
	it.setBuffPower(npc.getStat(r));
	this->itemFromNpc = it;

}


npc2item::~npc2item()
{
}
