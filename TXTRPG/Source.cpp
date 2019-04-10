//#include "Bag.h"
//#include "Item.h"
#include "ReadSave.h"
#include "Player.h"
#include "Statistics.h"
#include "Game.h"
#include "InOut.h"
#include "Area.h"
#include <conio.h>
#include <iostream>

using namespace std;


int main()
{

	Game* round = Game::getInstance();

	InOut menu;
	Player gamer("xyz");
	Area newArea;						//initialization location

	ReadSave wpis;						//TEMPORARY
	Bag bag;
	Item i1("nwm", 1, 2);
	Item i2("nwm", 1, 2);
	Item i3("nwm", 1, 2);
	Item i4("nwm", 1, 2);
	Item i51("nwm", 1, 2);
	Item i6("nwm", 1, 2);
	Item i7("nwm", 1, 2);
	Item i8("nwm", 1, 2);
	Item i9("nwm", 1, 2);
	Item i01("nwm", 1, 2);
	Item i11("nwm", 1, 2);
	Item i12("nwm", 1, 2);
	bag.putOnEQ(i1, gamer);
	bag.putOnEQ(i2, gamer);
	bag.putOnEQ(i3, gamer);
	bag.putOnBP(i4);
	bag.putOnBP(i51);
	bag.putOnBP(i6);
	bag.putOnBP(i7);
	bag.putOnBP(i8);
	bag.putOnBP(i9);
	bag.putOnBP(i01);
	bag.putOnBP(i11);
	bag.putOnBP(i12);
	bag.putOnBP(i1);
	menu.createGraphicOverlay();
	menu.createPlayer(gamer);

	do
	{
		wpis.readMap();
		break;
		//menu.playerMenu(gamer, bag);
		//system("cls");

		//menu.createGraphicOverlay();
		//menu.createInfoBar(gamer,newArea);

		// //wpis.savePlayer(gamer);

		//(*round).result(gamer, newArea);		// here will be action soon

		//Area prevArea = newArea;			//KONSTRUKTOR KOPIUJACY?????????

		//int dir;							// temporary changing area machine // in future in InOut class
		//cout << "\n\n\n\n\n\n\n===============================================================================" << endl;
		//cout << "choose directon by pressing 0/1/2/3: ";
		//cin >> dir;
		//

		//
		//newArea = (*round).areaMaker(prevArea, dir);			//creating new area

	} while (1);							// infinity loop //in future in InOutClass 



	system("pause");
	return 0;
}