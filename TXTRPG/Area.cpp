#include "Area.h"




Area::Area()
{
	this->areaName="none";
	this->areaType="none";
	this->action=0;									// 0 noth, 1 fight, 2 trade, 3 speak
	this->eventLevel=0;
	this->posX=0;
	this->posY=0;
}
Area::Area(int X, int Y, int dir)
{


	srand(time(NULL));								// is it good place for that?


	this->areaName = "losowo";
	this->areaType = "losowo";
	this->action = rand()%4;
	this->eventLevel = rand()%10+1;					//random difficulty level	
	if (dir == 0)									// 0 right, 1 up, 2 left, 3 down
	{
		this->posX = X + 1;
		this->posY = Y;
	}
	if (dir == 1)
	{
		this->posX = X;
		this->posY = Y + 1;
	}
	if (dir == 2)
	{
		this->posX = X - 1;
		this->posY = Y;
	}
	if (dir == 3)
	{
		this->posX = X;
		this->posY = Y - 1;
	}
}


Area::~Area()
{
}

string Area::getAreaName() { return areaName; }
string Area::getAreaType() { return areaType; }
int Area::getAction() { return action; }
int Area::getEventLevel() { return eventLevel; }
int Area::getPosX() { return posX; }
int Area::getPosY() { return posY; }