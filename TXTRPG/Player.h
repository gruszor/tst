#pragma once
#include <string>
#include  "Statistics.h"

using namespace std;
class Player : public Statistics 
{
	friend class Bag;
	friend class Game;
	string Name;
public:
	Player(string);
	~Player();
	void setName(string);
	string getName();
};

