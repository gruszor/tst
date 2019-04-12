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

void Game::result2(Player & obj1, Area & obj2)
{
	srand(time(NULL));

	Player nonpl("cdsa");

	nonpl.setEXP(0);
	nonpl.setHP(100);
	nonpl.setMana(100);
	nonpl.setStamina(100);
	nonpl.setGold(rand()%obj2.getEventLevel());
	nonpl.setStrenght(rand() % obj2.getEventLevel());
	nonpl.setDexterity(rand() % obj2.getEventLevel());
	nonpl.setIntelligence(rand() % obj2.getEventLevel());
	nonpl.setSpeed(rand() % obj2.getEventLevel());
	nonpl.setEndurance(rand() % obj2.getEventLevel());
	nonpl.setCharisma(rand() % obj2.getEventLevel());
	nonpl.setLuck(rand() % obj2.getEventLevel());
	nonpl.setSmartness(rand() % obj2.getEventLevel());

	//switch (obj2.getAction())
	//{
	//case 0:
	//	InOut::nothing();
	//	break;
	//case 1:
	//	InOut::fight(obj1,nonpl);
	//		break;
	//case 2:
	//	InOut::trade();
	//	break;
	//case 3:
	//	InOut::speak();
	//	break;
	//}
}

