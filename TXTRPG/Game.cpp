#include "Game.h"
using namespace std;

Game* Game::instance = 0;

Game* Game::getInstance()
{
	if (instance == 0)
	{
		instance = new Game();
	}

	return instance;
}

Game::Game()
{

}


Game::~Game()
{
}

void Game::result(Player & obj1, Area & obj2)
{
	int sum = obj1.getStrenght() + obj1.getDexterity() + obj1.getIntelligence() + obj1.getSpeed() + obj1.getEndurance() + obj1.getCharisma() + obj1.getLuck() + obj1.getSmartness();
	if (sum < (obj2.getEventLevel() + 5))						// need change to be more flexible
	{
		if (obj2.getAction() == 0)cout << "nothing changed" << endl;
		else if (obj2.getAction() == 1)cout << "you lose" << endl;
		else if (obj2.getAction() == 2)cout << "the transaction fell through" << endl;
		else if (obj2.getAction() == 3)cout << "this guy didnt like you" << endl;
	}
	if (sum >= (obj2.getEventLevel() + 5))						// need change to be more flexible
	{
		if (obj2.getAction() == 0)cout << "nothing changed" << endl;
		else if (obj2.getAction() == 1)cout << "you win" << endl;
		else if (obj2.getAction() == 2)cout << "the trade was succesfull" << endl;
		else if (obj2.getAction() == 3)cout << "he really likes you!" << endl;
	}
}

Area Game::areaMaker(Area& obj,int dir)
{
	int x = obj.getPosX();
	int y = obj.getPosY();
	Area newArea(x, y, dir);
	return newArea;
}

Player Game::NPCmaker(Area obj)
{
	srand(time(NULL));

	Player character("random name");
	Player *npc = &character;

	npc->setEXP(0);
	npc->setHP(100);
	npc->setMana(100);
	npc->setStamina(100);
	npc->setGold(0);

	npc->setStrenght(0);
	npc->setDexterity(0);
	npc->setIntelligence(0);
	npc->setSpeed(0);
	npc->setEndurance(0);
	npc->setCharisma(0);
	npc->setLuck(0);
	npc->setSmartness(0);
	switch (obj.getAction())
	{
	case 0:			//nothing

		//really nothing bro

		break;
	case 1:			//fight
		npc->setStrenght(rand()%(obj.getEventLevel()+1));
		npc->setDexterity(rand() % (obj.getEventLevel() + 1));
		npc->setSpeed(rand() % (obj.getEventLevel() + 1));
		npc->setEndurance(rand() % (obj.getEventLevel() + 1));
		break;
	case 2:			//trade
		npc->setCharisma(rand() % (obj.getEventLevel() + 1));
		npc->setLuck(rand() % (obj.getEventLevel() + 1));
		break;
	case 3:		//interaction
		npc->setIntelligence(rand() % (obj.getEventLevel() + 1));
		npc->setSmartness(rand() % (obj.getEventLevel() + 1));
		break;
	//default:							THROW EXCEPTION SHOULD BE HERE
	}

	return *npc;
}


Bag& Game::bagMaker(Area obj,Player * npc)
{
	srand(time(NULL));

	Bag bag(npc,10);
	Item it1("random item name", rand() % 13, obj.getEventLevel(),false);
	bag.pushItem(it1);														//a bit temporary
	return bag;
}


bool Game::fight(Player &gamer, Player *npc, int actionType)
{
	srand(time(NULL));

	int difficulty = 3;								//SHOULD BE A CLASS POLE 
	int bonus = rand() % difficulty -1;

	bool escapeSuccess = false;

	switch (actionType)
	{
	case 0:										// melee combat
		if (bonus >= 0)
		{
			if (gamer.getStrenght() + gamer.getLuck() >= npc->getStrenght())
			{
				npc->setHP((npc->getHP())-(gamer.getStrenght() + gamer.getLuck() - npc->getStrenght() + bonus));
			}
			else gamer.setHP((gamer.getHP()) - (npc->getStrenght() - gamer.getStrenght() + bonus));
		}
		else 
		{
			if (npc->getStrenght() + npc->getLuck() >= gamer.getStrenght())
			{
				gamer.setHP((gamer.getHP()) - (npc->getStrenght() + npc->getLuck() - gamer.getStrenght() + bonus));
			}
			else npc->setHP((npc->getHP()) - (gamer.getStrenght() - npc->getStrenght() + bonus));
		}
		break;
	case 1:											//fight at a distance
		if (bonus >= 0)
		{
			if (gamer.getDexterity() + gamer.getLuck() >= npc->getDexterity())
			{
				npc->setHP((npc->getHP()) - (gamer.getDexterity() + gamer.getLuck() - npc->getDexterity() + bonus));
			}
			else gamer.setHP((gamer.getHP()) - (npc->getDexterity() - gamer.getDexterity() + bonus));
		}
		else
		{
			if (npc->getDexterity() + npc->getLuck() >= gamer.getDexterity())
			{
				gamer.setHP((gamer.getHP()) - (npc->getDexterity() + npc->getLuck() - gamer.getDexterity() + bonus));
			}
			else npc->setHP((npc->getHP()) - (gamer.getDexterity() - npc->getDexterity() + bonus));
		}
		break;
	case 2:											//defending
		if (bonus >= 0)
		{
			if (gamer.getEndurance() + gamer.getLuck() >= npc->getEndurance())
			{
				npc->setHP((npc->getHP()) - (gamer.getEndurance() + gamer.getLuck() - npc->getEndurance() + bonus));
			}
			else gamer.setHP((gamer.getHP()) - (npc->getEndurance() - gamer.getEndurance() + bonus));
		}
		else
		{
			if (npc->getEndurance() + npc->getLuck() >= gamer.getEndurance())
			{
				gamer.setHP((gamer.getHP()) - (npc->getEndurance() + npc->getLuck() - gamer.getEndurance() + bonus));
			}
			else npc->setHP((npc->getHP()) - (gamer.getEndurance() - npc->getEndurance() + bonus));
		}
		break;
	case 3:
		if (gamer.getLuck() + gamer.getSpeed() > npc->getSpeed()) escapeSuccess = true;
		else gamer.setHP((gamer.getHP()) - (npc->getSpeed() + npc->getLuck()));
		break;
	}


	if (!(npc->getHP()>=0) || !(gamer.getHP()>=0) || escapeSuccess)
	{
		gamer.setEXP(rand());
		return false;
	}
	else return true;
}


bool Game::trade(Player &gamer, Player *npc, int actionType, Bag & npcEq, Bag &playerEq)
{
	//cout << "trading" << endl;
	if (actionType) return true;
	else return false;
}
bool Game::speak(Player &gamer, Player *npc, int actionType)
{
	//cout << "speaking" << endl;
	if (actionType) return true;
	else return false;
}