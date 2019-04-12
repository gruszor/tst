#pragma once
#include "Player.h"
#include "Area.h"
#include"InOut.h"
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
};




