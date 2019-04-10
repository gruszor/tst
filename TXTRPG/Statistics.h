#pragma once
#include <string>
using namespace std;
class Statistics
{
	int stats[13];
	//int EXP;
	//int HP;
	//int Mana;
	//int Stamina;
	//int Gold;
	//int Strenght;
	//int Dexterity;
	//int Intelligence;
	//int Speed;
	//int Endurance;
	//int Charisma;
	//int Luck;
	//int Smartness;
public:
	Statistics();
	Statistics(int,int,int,int,int,int,int,int,int,int,int,int,int);
	~Statistics();
	string statNames[13] = { "EXP","HP", "Mana", "Stamina", "Gold", "Strenght", "Dexterity", "Intelligence", "Speed", "Endurance", "Charisma", "Luck", "Smartness" };
	void setEXP(int);
	void setHP(int);
	void setMana(int);
	void setStamina(int);
	void setGold(int);
	void setStrenght(int);
	void setDexterity(int);
	void setIntelligence(int);
	void setSpeed(int);
	void setEndurance(int);
	void setCharisma(int);
	void setLuck(int);
	void setSmartness(int);
	int getEXP();
	int getHP();
	int getMana();
	int getStamina();
	int getGold();
	int getStrenght();
	int getDexterity();
	int getIntelligence();
	int getSpeed();
	int getEndurance();
	int getCharisma();
	int getLuck();
	int getSmartness();


	void setStat(int  x, int y);
	int getStat(int x);

};

