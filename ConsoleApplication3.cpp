#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include "World.h"
#include "Dandelion.h"
#include "Fox.h"
#include "Grass.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Gnu.h"
#include "Turtle.h"
#include "Guarana.h"
#include "Human.h"
#include "Berry.h"
#include "Barszcz.h"
#include "View.h"
int main()
{	
	srand(time(NULL));
	View view;
	view.changePosition(15, 12);
	cout << "Po wielu dniach plyniecia po bezbrzeznym oceanie";
	Sleep(4000);
	system("cls");
	view.changePosition(15, 12);
	cout << "W srodku nocy Arka zatrzesla sie, rozleglo sie bardzo glosne uderzenie";
	Sleep(4000);
	system("cls");
	view.changePosition(15, 12);
	cout << "Cham, syn Noego, wyrwany z glebokiego snu wybiegl na poklad";
	Sleep(4000);
	system("cls");
	view.changePosition(15, 12);
	cout << "W swietle ksiezyca zobaczyl wyspe, o ktora rozbila sie Arka";
	Sleep(4000);
	system("cls");
	view.changePosition(8, 12);
	cout << "Duza czesc Arki, ta gdzie spala rodzina Chama jest zawalona";
	view.changePosition(15, 13);
	cout<< "wszyscy, tak jak i wiekszosc zwierzat nie zyje";
	Sleep(4000);
	system("cls");
	view.changePosition(15, 12);
	cout << "Przestraszone zwierzeta rozbiegly sie po wyspie";
	Sleep(4000);
	system("cls");
	view.changePosition(15, 12);
	cout << "Chamowi nie pozostaje nic innego niz walczyc o przezycie na";
	view.changePosition(15, 13);
	cout<< "wyspie, wraz z zwierzetami, ktore nigdy go nie lubily";
	Sleep(4000);
	system("cls");
	view.changePosition(15, 12);
	cout << "Jak duza jest wyspa, ktora widzisz przed soba? (dlugosc szerokosc)";
	char polecenie;
	vector<Organism*> animals;
	vector<Organism*> plants;
	animals.push_back(new Fox);
	animals.push_back(new Wolf);
	animals.push_back(new Sheep);
	animals.push_back(new Gnu);
	animals.push_back(new Turtle);

	plants.push_back(new Dandelion);
	plants.push_back(new Grass);
	plants.push_back(new Guarana);
	plants.push_back(new Berry);
	plants.push_back(new Barszcz);

	int m, n;
	cin >> m >> n;
	system("cls");
	if (m*n < 16)
		cout << "ZA MALY SWIAT, PODAJ WIEKSZE WYMIARY (min 16 pol)";
	World Swiat(m,n);
	Swiat.createWorld(animals, plants);

	Swiat.drawWorld();
	for (int i = 0; i < 500; i++) {
		Swiat.nextRound();
		Swiat.drawWorld();
		do {
			cout << "NACIŚNIJ n BY URUCHOMIC NASTEPNA RUNDE";
			cin >> polecenie;
		} while (polecenie != 'n');
	}



}
