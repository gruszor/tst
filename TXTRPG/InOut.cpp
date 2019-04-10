#include "InOut.h"


InOut::InOut()
{
}


InOut::~InOut()
{
}

void InOut::createPlayer(Player & gracz)///**/
{
	string a;
	cout << "Nazwij swojego bohatera: ";
	cin >> a;
	gracz.setName(a);


	int pressKey = 0;
	int j = 5;
	int tab[13] = { 0,100,100,100,0,0,0,0,0,0,0,0,0 };


	do
	{
		system("cls");
		createGraphicOverlay();
		for (int i = 5; i < 13; i++)
		{
			if (j==i)
			{
				cout << "<"+gracz.statNames[i] << " is: " << tab[i]<<">" << endl;
				
			}
			else
			{
				cout << gracz.statNames[i] << " is: " << tab[i] << endl;
			}
		}

		int sum = tab[5] + tab[6] + tab[7] + tab[8] + tab[9] + tab[10] + tab[11] + tab[12];

		cout << "\n==============================================================================" << endl;
		cout << "Maximum amount of assigned points is 10. You have " << 10 - sum << " points left. " << endl;
		cout << "Press: " << pressButton("w", "up") << pressButton("s", "down") << pressButton("a", "decrement") << pressButton("d", "increment") << pressButton("c", "next step") << endl;

		pressKey = _getch();

		if ((pressKey == 'd')&&(sum<10)) tab[j]++;
		else if ((pressKey == 'a') && (tab[j]>0))tab[j]--;
		else if (pressKey == 'w')
			{
				if (j > 5)j--;
				else j = 12;
			}
		else if (pressKey == 's')
			{
				if (j < 12)j++;
				else j = 5;
			}
	} while (pressKey != 'c');

	gracz.setEXP(tab[0]);
	gracz.setHP(tab[1]);
	gracz.setMana(tab[2]);
	gracz.setStamina(tab[3]);
	gracz.setGold(tab[4]);
	gracz.setStrenght(tab[5]);
	gracz.setDexterity(tab[6]);
	gracz.setIntelligence(tab[7]);
	gracz.setSpeed(tab[8]);
	gracz.setEndurance(tab[9]);
	gracz.setCharisma(tab[10]);
	gracz.setLuck(tab[11]);
	gracz.setSmartness(tab[12]);
	
}
void InOut::createGraphicOverlay()
{
	cout << "===============================================================================" << endl;
	cout << "||||||||||||||||||||||||||||||: txtRPG: TheGame :||||||||||||||||||||||||||||||" << endl;
	cout << "===============================================================================" << endl;
	//cout << "-------------------------------------------------------------------------------" << endl;
}
void InOut::createInfoBar(Player & gracz, Area & obj)
{
	cout <<"                  "<< "Location name: " << obj.getAreaName() << " Location Type: " << obj.getAreaType() << endl;
	//cout << "-------------------------------------------------------------------------------" << endl;
	cout <<"                 " << "HP: " << gracz.getHP() << " Mana: " << gracz.getMana() << " Stamina: " << gracz.getStamina() << " EXP: " << gracz.getEXP() << " Gold: " << gracz.getGold() << endl;
	//cout << "===============================================================================" << endl;
}
string InOut::pressButton(string button, string info)
{
	return " [" + button + "] - " + info;
}



//void InOut::map()
//{
//	system("cls");
//
//	createGraphicOverlay();
//	createInfoBar(gamer, newArea);
//
//	Area prevArea = newArea;
//	newArea = (*round).areaMaker(prevArea, dir);
//
//}
void InOut::playerMenu(Player & obj,Bag & bag )
{
	int j = 0;
	int pressKey = 0;
	do
	{
		system("cls");
		createGraphicOverlay();
		for (int i = 0; i < 3; i++)
		{
			if (i == j)
				cout << obj.statNames[i] << "<-->" << obj.getStat(i) << "    /////    <" << (bag.getItemEQ(i)).getName() << " " << (bag.getItemEQ(i)).getBuffType() << "/" << (bag.getItemEQ(i)).getBuffPower() << ">" << endl;
			else
				cout << obj.statNames[i] << "<-->" << obj.getStat(i) << "    /////    " << (bag.getItemEQ(i)).getName() << " " << (bag.getItemEQ(i)).getBuffType() << "/" << (bag.getItemEQ(i)).getBuffPower() << endl;
		}
		for (int i = 3; i < 12; i++)
		{
			if (i == j)
				cout << obj.statNames[i] << "<-->" << obj.getStat(i) << "    /////    <" << (bag.getItemBP(i - 3)).getName() << " " << (bag.getItemBP(i - 3)).getBuffType() << "/" << (bag.getItemBP(i - 3)).getBuffPower() << ">" << endl;
			else
				cout << obj.statNames[i] << "<-->" << obj.getStat(i) << "    /////    " << (bag.getItemBP(i - 3)).getName() << " " << (bag.getItemBP(i - 3)).getBuffType() << "/" << (bag.getItemBP(i - 3)).getBuffPower() << endl;
		}

		cout << "\n==============================================================================" << endl;
		cout << "Remember if you throw away your item it will disapear forever!" << endl;
		cout << "Press: " << pressButton("w", "up") << pressButton("s", "down") << pressButton("a", "throw item away!") << pressButton("d", "move to EQ/BP") << pressButton("i", "map") << pressButton("p", "action") << endl;

		pressKey = _getch();
		if (pressKey == 's')
		{
			if (j == 12) j = 0;
			else j++;
		}
		else if (pressKey == 'w')
		{
			if (j == 0)j = 12;
			else j--;
		}
		else if ((pressKey == 'a') && ((!((bag.getVectorBP()).empty())) && (!((bag.getVectorEQ()).empty()))))
		{
			if ((j >= 0) && (j < 3))
			{
				bag.removeEQ(j,obj);
			}
			else bag.removeBP(j - 3);
		}
		else if (pressKey == 'd')
		{
			if ((j >= 0) && (j < 3))
			{
				if (!(((bag.getVectorEQ()).size()) < 3))cout << "no coz :(" << endl;
				else
				{
					Item tmp(bag.getItemEQ(j));
					(bag.getVectorEQ()).push_back(tmp);
					(bag.getVectorEQ()).erase((bag.getVectorEQ()).begin() + j);
				}

			}
			else
			{
				if (!(((bag.getVectorBP()).size()) < 10))cout << "no coz :(" << endl;
				else
				{
					Item tmp(bag.getItemBP(j-3));
					(bag.getVectorBP()).push_back(tmp);
					(bag.getVectorBP()).erase((bag.getVectorBP()).begin() + (j-3));
				}
			}
		}
	} while (!((pressKey == 'i') || (pressKey == 'p')));
}
//void InOut::fight(Player &obj1, Player &obj2)
//{
//	int pressKey;
//
//	do {
//		system("cls");
//		createGraphicOverlay();
//		pressKey = _getch();
//		switch (pressKey)
//		{
//		case 1:
//			break;
//		case 2:
//			break;
//
//		}
//	} while (pressKey||);
//}