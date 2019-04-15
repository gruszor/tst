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
	bool tmp;
	bool &condition=tmp;

	int pressKey=0;
	std::map<int, int> actionKeys;
	actionKeys['w'] = 0;
	actionKeys['s'] = 1;
	actionKeys['a'] = 2;
	actionKeys['d'] = 3;
	actionKeys['q'] = 4;

	Player npc(game.NPCmaker(obj));
	Player*npcPointer = &npc;
	Bag &npcEq = game.bagMaker(obj,npcPointer);
	



	switch (obj.getAction())


	{
	case 0:
		do
		{
			system("cls");
			createGraphicOverlay();

			//cout << gamer.getName() << "          " << npc->getName() << endl;
			cout << gamer.getHP() << "          " << npc.getHP() << endl;
			cout << gamer.getStamina() << "          " << npc.getStamina() << endl;
			cout << gamer.getMana() << "          " << npc.getMana() << endl;


			cout << "in fact there is nothing here" << endl;


			cout << "\n==============================================================================" << endl;
			cout << "You are doing nothing right now" << endl;
			cout << "Press: " << pressButton("w", "stop speaking") << pressButton("s", "continue speaking") << endl;
			pressKey = _getch();
			condition = game.speak(gamer, npcPointer, actionKeys[pressKey]);
		} while (condition);
	case 1:
		do
		{
			system("cls");
			createGraphicOverlay();
			//cout << gamer.getName() << "          " << npc.getName() << endl;
			cout << gamer.getHP() << "          " << npc.getHP() << endl;
			cout << gamer.getStamina() << "          " << npc.getStamina() << endl;
			cout << gamer.getMana() << "          " << npc.getMana() << endl;

			cout << "\n==============================================================================" << endl;
			cout << "You are during fightt right now!" << endl;
			cout << "Press: " << pressButton("w", "melee") << pressButton("s", "distance") << pressButton("a", "defend") << pressButton("d", "escape") << endl;
			pressKey = _getch();
			condition = game.fight(gamer, npcPointer, actionKeys[pressKey],plEq);
		} while (condition);
		break;
	case 2:
		do
		{
			system("cls");
			createGraphicOverlay();

			//cout << gamer.getName() << "          " << npc.getName() << endl;
	/*		cout << gamer.getHP() << "          " << npc.getHP() << endl;
			cout << gamer.getStamina() << "          " << npc.getStamina() << endl;
			cout << gamer.getMana() << "          " << npc.getMana() << endl;*/


			cout << "trading" << endl;


			cout << "\n==============================================================================" << endl;
			cout << "You are during trading right now!" << endl;
			cout << "Press: " << pressButton("w", "stop trading") << pressButton("s", "continue trading")<< endl;
			pressKey = _getch();
			condition = game.trade(gamer, npcPointer, actionKeys[pressKey], npcEq, plEq);
		} while (condition);
		break;
	case 3:
		do
		{
			system("cls");
			createGraphicOverlay();

			//cout << gamer.getName() << "          " << npc.getName() << endl;
			/*cout << gamer.getHP() << "          " << npc.getHP() << endl;
			cout << gamer.getStamina() << "          " << npc.getStamina() << endl;
			cout << gamer.getMana() << "          " << npc.getMana() << endl;*/


			cout << "speaking" << endl;


			cout << "\n==============================================================================" << endl;
			cout << "You are speaking right now" << endl;
			cout << "Press: " << pressButton("w", "stop speaking") << pressButton("s", "continue speaking") << endl;
			pressKey = _getch();
			condition = game.speak(gamer, npcPointer, actionKeys[pressKey]);
		} while (condition);
	}
}
void InOut::bagManager(Bag &eq)
{
	std::map<int, int> sortingType;
	sortingType['j'] = 1;
	sortingType['k'] = 2;
	sortingType['l'] = 3;

	int pressKey = 0;
	int j = 0;

	do
	{
		vector<string> bagStat(eq.info());
		system("cls");
		createGraphicOverlay();
		cout << "buff power//buff type//dressed or not//name" << endl;
		for (int i = 0; i < size(bagStat); i++)
		{
			if (j == i)
			{
				cout << "<"<<bagStat[i][0] << " / " << bagStat[i][1]<<" / "<< bagStat[i][2]<<" / ";
				for (int k = 3; k < size(bagStat[i]); k++ ) cout<<bagStat[i][k];
				cout<<">"<<endl;
			}
			else
			{
				cout<< bagStat[i][0] << " / " << bagStat[i][1] << " / " << bagStat[i][2] << " / ";
				for (int k = 3; k < size(bagStat[i]); k++) cout << bagStat[i][k];
				cout << endl;
			}
		}

		cout << "\n==============================================================================" << endl;
		cout << "Here is your bag, you can wear and take off your items " << endl;
		cout << "Press: " << pressButton("w", "up") << pressButton("s", "down") << pressButton("a", "take off") << pressButton("d", "wear") << pressButton("c", "close this window") << endl;
		cout << "       " << pressButton("j", "sort by buff type") << pressButton("k", "sort by buff power") << pressButton("l", "sort by name")<< endl;
		cout << "       " << pressButton("r", "remove item") << endl;

		pressKey = _getch();

		if (pressKey == 'd')
		{
			eq.wearItem(eq.number2item(j));
		}
		else if (pressKey == 'a')
		{
			eq.takeOffItem(eq.number2item(j));
		}
		else if (pressKey == 'w')
		{
			if (j > 0)j--;
			else j = size(bagStat);
		}
		else if (pressKey == 's')
		{
			if (j < size(bagStat))j++;
			else j = 0;
		}
		else if ((pressKey == 'j')||(pressKey == 'k')||(pressKey == 'l'))
		{
			eq.sorting(sortingType[pressKey]);
		}
		else if (pressKey == 'r')
		{
			eq.eraseItem(j);
		}
	} while (pressKey != 'c');
}
Area InOut::mapManager(Area prevArea,Game game)
{
	Area &tmp = prevArea;
	int pressKey = 0;
	int i=0;
	std::map<int, int> actionKeys;
	actionKeys['d'] = 0;
	actionKeys['w'] = 1;
	actionKeys['a'] = 2;
	actionKeys['s'] = 3;


	do {
		system("cls");

		createGraphicOverlay();
		//	createInfoBar(gamer, prevArea);
		cout << "map" <<i++<< endl;					//GRAPHIC INTERPRETATION SOON
		cout << "\n==============================================================================" << endl;
		cout << "You are traveling right now!" << endl;
		cout << "Press: " << pressButton("w", "up") << pressButton("s", "down") << pressButton("a", "left") << pressButton("d", "right") << pressButton("c", "close") << endl;
		pressKey = _getch();
		tmp = game.areaMaker(tmp, actionKeys[pressKey]);

	} while (pressKey != 'c');
	return tmp;

}

