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
	cout <<"                 " << "HP: " << gracz.getHP() << " Mana: " << gracz.getMana() << " Stamina: " << gracz.getStamina() << " EXP: " << gracz.getEXP() << " Gold: " << gracz.getGold() << endl;
	//cout << "===============================================================================" << endl;
}
string InOut::pressButton(string button, string info)
{
	return " [" + button + "] - " + info;
}
void InOut::actionManager(Area &obj, Player &gamer, Game game, Bag &plEq)
{
	int pressKey=0;
	std::map<int, int> actionKeys;
	actionKeys['w'] = 0;
	actionKeys['s'] = 1;
	actionKeys['a'] = 2;
	actionKeys['d'] = 3;


	Player *npc = game.NPCmaker(obj);
	Bag &npcEq = game.bagMaker(obj);
	
	switch (obj.getAction())
	{
	case 0:
		do
		{
			system("cls");
			createGraphicOverlay();

			//cout << gamer.getName() << "          " << npc->getName() << endl;
			cout << gamer.getHP() << "          " << npc->getHP() << endl;
			cout << gamer.getStamina() << "          " << npc->getStamina() << endl;
			cout << gamer.getMana() << "          " << npc->getMana() << endl;


			cout << "speaking" << endl;


			cout << "\n==============================================================================" << endl;
			cout << "You are speaking right now" << endl;
			cout << "Press: " << pressButton("w", "stop speaking") << pressButton("s", "continue speaking") << endl;
			pressKey = _getch();
		} while (!game.speak(gamer, npc, actionKeys[pressKey]));
	case 1:
		do
		{
			system("cls");
			createGraphicOverlay();
			//cout << gamer.getName() << "          " << npc->getName() << endl;
			cout << gamer.getHP() << "          " << npc->getHP() << endl;
			cout << gamer.getStamina() << "          " << npc->getStamina() << endl;
			cout << gamer.getMana() << "          " << npc->getMana() << endl;

			cout << "\n==============================================================================" << endl;
			cout << "You are during fightt right now!" << endl;
			cout << "Press: " << pressButton("w", "melee") << pressButton("s", "distance") << pressButton("a", "escape") << pressButton("d", "defend") << endl;
			pressKey = _getch();
		} while (!game.fight(gamer, npc, actionKeys[pressKey]));
		break;
	case 2:
		do
		{
			system("cls");
			createGraphicOverlay();

			//cout << gamer.getName() << "          " << npc->getName() << endl;
			cout << gamer.getHP() << "          " << npc->getHP() << endl;
			cout << gamer.getStamina() << "          " << npc->getStamina() << endl;
			cout << gamer.getMana() << "          " << npc->getMana() << endl;


			cout << "trading" << endl;


			cout << "\n==============================================================================" << endl;
			cout << "You are during trading right now!" << endl;
			cout << "Press: " << pressButton("w", "stop trading") << pressButton("s", "continue trading")<< endl;
			pressKey = _getch();
		} while (!game.trade(gamer, npc, actionKeys[pressKey], npcEq, plEq));
		break;
	case 3:
		do
		{
			system("cls");
			createGraphicOverlay();

			//cout << gamer.getName() << "          " << npc->getName() << endl;
			cout << gamer.getHP() << "          " << npc->getHP() << endl;
			cout << gamer.getStamina() << "          " << npc->getStamina() << endl;
			cout << gamer.getMana() << "          " << npc->getMana() << endl;


			cout << "speaking" << endl;


			cout << "\n==============================================================================" << endl;
			cout << "You are speaking right now" << endl;
			cout << "Press: " << pressButton("w", "stop speaking") << pressButton("s", "continue speaking") << endl;
			pressKey = _getch();
		} while (!game.speak(gamer, npc, actionKeys[pressKey]));
	}
}








Area InOut::map(Area prevArea,Game game)
{
	int pressKey = 0;
	std::map<int, int> actionKeys;
	actionKeys['d'] = 0;
	actionKeys['w'] = 1;
	actionKeys['a'] = 2;
	actionKeys['s'] = 3;

	system("cls");

	createGraphicOverlay();
//	createInfoBar(gamer, prevArea);
	cout << "map" << endl;					//GRAPHIC INTERPRETATION SOON
	cout << "\n==============================================================================" << endl;
	cout << "You are traveling right now!" << endl;
	cout << "Press: " << pressButton("w", "up") << pressButton("s", "down") << pressButton("a", "left") << pressButton("d", "right") << endl;
	pressKey = _getch();
	return game.areaMaker(prevArea, actionKeys[pressKey]);

}
void InOut::playerMenu(Player & obj,Bag & bag )
{
	//int j = 0;
	//int pressKey = 0;
	//do
	//{
	//	system("cls");
	//	createGraphicOverlay();


	//	for (int i = 0; i < size(bag.getVectorEQ()); i++)
	//	{
	//		if (i == j)
	//			cout << obj.statNames[i] << "<-->" << obj.getStat(i) << "    /////    <" << (bag.getItemEQ(i)).getName() << " " << (bag.getItemEQ(i)).getBuffType() << "/" << (bag.getItemEQ(i)).getBuffPower() << ">" << endl;
	//		else
	//			cout << obj.statNames[i] << "<-->" << obj.getStat(i) << "    /////    " << (bag.getItemEQ(i)).getName() << " " << (bag.getItemEQ(i)).getBuffType() << "/" << (bag.getItemEQ(i)).getBuffPower() << endl;
	//	}
	//	for (int i = size(bag.getVectorEQ()); i < size(bag.getVectorEQ())+size(bag.getVectorBP()); i++)
	//	{
	//		if (i == j)
	//			cout << obj.statNames[i] << "<-->" << obj.getStat(i) << "    /////    <" << (bag.getItemBP(i - 3)).getName() << " " << (bag.getItemBP(i - 3)).getBuffType() << "/" << (bag.getItemBP(i - 3)).getBuffPower() << ">" << endl;
	//		else
	//			cout << obj.statNames[i] << "<-->" << obj.getStat(i) << "    /////    " << (bag.getItemBP(i - 3)).getName() << " " << (bag.getItemBP(i - 3)).getBuffType() << "/" << (bag.getItemBP(i - 3)).getBuffPower() << endl;
	//	}


	//	cout << "\n==============================================================================" << endl;
	//	cout << "Remember if you throw away your item it will disapear forever!" << endl;
	//	cout << "Press: " << pressButton("w", "up") << pressButton("s", "down") << pressButton("a", "throw item away!") << pressButton("d", "move to EQ/BP") << pressButton("i", "map") << pressButton("p", "action") << endl;


	//	pressKey = _getch();

	//	if (pressKey == 's')
	//	{
	//		if (j == 12) j = 0;
	//		else j++;
	//	}

	//	else if (pressKey == 'w')
	//	{
	//		if (j == 0)j = 12;
	//		else j--;
	//	}

	//	else if ((pressKey == 'a') && ((!((bag.getVectorBP()).empty())) && (!((bag.getVectorEQ()).empty()))))
	//	{
	//		if ((j >= 0) && (j < 3))
	//		{
	//			bag.removeEQ(j,obj);
	//		}
	//		else bag.removeBP(j - 3);
	//	}


	//	else if (pressKey == 'd')
	//	{
	//		if ((j >= 0) && (j < 3))
	//		{
	//			if (!(((bag.getVectorEQ()).size()) < 3))cout << "no coz :(" << endl;
	//			else
	//			{
	//				Item tmp(bag.getItemEQ(j));
	//				(bag.getVectorEQ()).push_back(tmp);
	//				(bag.getVectorEQ()).erase((bag.getVectorEQ()).begin() + j);
	//			}

	//		}
	//		else
	//		{
	//			if (!(((bag.getVectorBP()).size()) < 10))cout << "no coz :(" << endl;
	//			else
	//			{
	//				Item tmp(bag.getItemBP(j-3));
	//				(bag.getVectorBP()).push_back(tmp);
	//				(bag.getVectorBP()).erase((bag.getVectorBP()).begin() + (j-3));
	//			}
	//		}
	//	}

	//} while (!((pressKey == 'i') || (pressKey == 'p')));
}
