#pragma once
#include<fstream>
#include <map>
#include<iostream>
//#include<ofstream>
#include "Player.h"
using namespace std;


class ReadSave
{

public:
	ReadSave();
	~ReadSave();
	void savePlayer(Player&);
	void readMap();
	string readPlayer();
};

