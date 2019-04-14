#include "Player.h"



Player::Player(string name = "Name is undefined") 
{
	this->Name = name;
}


Player::~Player()
{
}

void Player::setName(string name)
{
	this->Name = name;
}
string Player::getName()
{
	return this->Name;
}