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


	//Game();
	~Game();
	void result2(Player &, Area &);
	void result(Player &,Area &);
	Area areaMaker(Area &,int);
};


//void readlocation();
//void writeinput();
//void writeoutput();
//void readinput();
//void readplayer();
//void writeplayer();
//void writeinput2();
//void writeoutput2();

