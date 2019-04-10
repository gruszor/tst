#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Area
{
	string areaName;
	string areaType;
	int action;
	int eventLevel;
	int posX;
	int posY;
public:
	Area();
	Area(int,int,int);
	~Area();
	string getAreaName();
	string getAreaType();
	int getAction();
	int getEventLevel();
	int getPosX();
	int getPosY();
	
};

