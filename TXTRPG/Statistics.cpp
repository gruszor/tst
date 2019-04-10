#include "Statistics.h"



Statistics::Statistics(
	int EXP = 0,
int HP = 0,
int Mana = 0,
int Stamina = 0,
int Gold = 0,
int Strenght = 0,
int Dexterity = 0,
int Intelligence = 0,
int Speed = 0,
int Endurance = 0,
int Charisma = 0,
int Luck = 0,
int Smartness = 0
)
{
	
	this-> stats[0] = EXP;
	this->stats[1] =HP;
	this->stats[2] =Mana;
	this->stats[3] =Stamina;
	this->stats[4] =Gold;
	this->stats[5] =Strenght;
	this->stats[6] =Dexterity;
	this->stats[7] =Intelligence;
	this->stats[8] =Speed;
	this->stats[9] =Endurance;
	this->stats[10] =Charisma;
	this->stats[11] =Luck;
	this->stats[12] =Smartness;
};

Statistics::Statistics()
{
}

Statistics::~Statistics()
{
}

void Statistics::setEXP(int x) { this->stats[0] = x; };
void Statistics::setHP(int x) { this->stats[1] = x; };
void Statistics::setMana(int x) { this->stats[2] = x; };
void Statistics::setStamina(int x) { this->stats[3] = x; };
void Statistics::setGold(int x) { this->stats[4] = x; };
void Statistics::setStrenght(int x) { this->stats[5] = x; };
void Statistics::setDexterity(int x) { this->stats[6] = x; };
void Statistics::setIntelligence(int x) { this->stats[7] = x; };
void Statistics::setSpeed(int x) { this->stats[8] = x; };
void Statistics::setEndurance(int x) { this->stats[9] = x; };
void Statistics::setCharisma(int x) { this->stats[10] = x; };
void Statistics::setLuck(int x) { this->stats[11] = x; };
void Statistics::setSmartness(int x) { this->stats[12] = x; };
int Statistics::getEXP() { return stats[0]; };
int Statistics::getHP() { return stats[1]; };
int Statistics::getMana() { return stats[2]; };
int Statistics::getStamina() { return stats[3]; };
int Statistics::getGold() { return stats[4]; };
int Statistics::getStrenght() { return stats[5]; };
int Statistics::getDexterity() { return stats[6]; };
int Statistics::getIntelligence() { return stats[7]; };
int Statistics::getSpeed() { return stats[8]; };
int Statistics::getEndurance() { return stats[9]; };
int Statistics::getCharisma() { return stats[10]; };
int Statistics::getLuck() { return stats[11]; };
int Statistics::getSmartness() { return stats[12]; };

void Statistics::setStat(int x, int y)
{
	this->stats[x] += y;
}
int Statistics::getStat(int x)
{
	return stats[x];
}