#include "ReadSave.h"



ReadSave::ReadSave()
{
}


ReadSave::~ReadSave()
{
}

void ReadSave::savePlayer(Player& obj)
{
	ofstream player;
	player.open("statistic.txt", ios::trunc);
	player << obj.getEXP()<<"\n" << obj.getHP() << "\n" << obj.getMana() << "\n" << obj.getStamina() << "\n" << obj.getGold() << "\n" << obj.getStrenght() << "\n" << obj.getDexterity() << "\n" << obj.getIntelligence() << "\n" << obj.getSpeed() << "\n" << obj.getEndurance() << "\n" << obj.getCharisma() << "\n" << obj.getLuck() << "\n" << obj.getSmartness();
	player.close();

}
string ReadSave::readPlayer()
{
	fstream player;
	string txt;
	player.open("statistic.txt");
	player >> txt;
	return txt;
}
void ReadSave::readMap()
{
	fstream mapa;
	mapa.open("map.txt");


	string k;
	int v;

	std::map<string,int> examp;
	while (mapa >> k >> v)
		examp[k] = v;

	map<string,int >::iterator itr;
	map<string, int >::iterator itr2;
	itr2 = examp.end();
	for (itr = examp.begin(); itr !=itr2; ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}


}