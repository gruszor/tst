#include "Bag.h"
#include "Item.h"
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
	Player *tmp = &gamer;
	Bag playerEq(tmp);
	Area newArea;						//initialization location

	//ReadSave wpis;						//TEMPORARY
	Bag bag(tmp,20);
	Item i1("nwm0", 1, 2,false);
	Item i2("nwm1", 2, 2, false);
	Item i3("nwm2", 3, 9, false);
	Item i4("nwm3", 4, 9, false);
	Item i51("nwm4", 5, 8, false);
	Item i6("nwm5", 6, 7, false);
	Item i7("nwm6", 7, 6, false);
	Item i8("nwm7", 8, 5, false);
	Item i9("nwm8", 9, 4, false);
	Item i01("nwm9", 1, 3, false);
	Item i11("nwm10", 1, 2, false);
	Item i12("nwm11", 1, 1, false);
	bag.pushItem(i1);
	bag.pushItem(i2);
	bag.pushItem(i3);
	bag.pushItem(i4);
	bag.pushItem(i51);
	bag.pushItem(i6);
	bag.pushItem(i7);
	bag.pushItem(i8);
	bag.pushItem(i9);
	bag.pushItem(i01);
	bag.pushItem(i11);
	bag.pushItem(i12);
	menu.createGraphicOverlay();
	menu.createPlayer(gamer);

	do
	{
		//menu.bagManager(bag);



		menu.actionManager(newArea, gamer, *round, playerEq);
		Area prevArea = newArea;
		menu.bagManager(bag);
		newArea = menu.mapManager(prevArea, *round);




		//menu.playerMenu(gamer,bag);
		//wpis.readMap();
		//break;
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