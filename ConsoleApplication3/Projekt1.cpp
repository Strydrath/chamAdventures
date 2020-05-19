#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include "World.h"
#include "Human.h"
#include "OrganismBase.h"
#include "View.h"
int main()
{	
	srand(time(NULL));
	View view;
	World* Swiat = new World(0,0);
	Human* testHuman = new Human;
	OrganismBase orgBase;
	bool quit =0;
	char polecenie;
	view.changePosition(15, 12);
	cout << "CHAM ADVENTURES";
	view.changePosition(15, 13);
	cout << "Projekt - symulacja swiata, C++";
	view.changePosition(15, 14);
	cout << "Autor: Marianna Jucewicz, 180377";
	Sleep(4000);
	system("cls");
	view.changePosition(15, 12);
	cout << "nowa gra - n     wczytaj gre - l";
	cin >> polecenie;
	if (polecenie == 'l') {
		ifstream loadFile("save.txt");
		if (loadFile) {
			int loadM, loadN, loadRound;
			loadFile >> loadM >> loadN >> loadRound;
			Swiat = new World(loadM, loadN);
			Swiat->loadWorld(loadFile, orgBase);
			Swiat->setRound(loadRound);
			loadFile.close();
		}
		else {
			system("cls");
			view.changePosition(15, 12);
			cout << "Brak pliku z zapisem, rozpoczecie nowej gry";
			Sleep(3000);
			polecenie = 'n';
		}

	}
	if(polecenie=='n') {
		system("cls");
		view.changePosition(15, 12);
		cout << "Czy chcesz zobaczyc wstep? (y/n)";
		cin >> polecenie;
		if (polecenie == 'y') {
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
			cout << "wszyscy, tak jak i wiekszosc zwierzat nie zyje";
			Sleep(4000);
			system("cls");
			view.changePosition(15, 12);
			cout << "Przestraszone zwierzeta rozbiegly sie po wyspie";
			Sleep(4000);
			system("cls");
			view.changePosition(15, 12);
			cout << "Chamowi nie pozostaje nic innego niz walczyc o przezycie na";
			view.changePosition(15, 13);
			cout << "wyspie, wraz z zwierzetami, ktore nigdy go nie lubily";
			Sleep(4000);
			system("cls");
			view.changePosition(15, 13);
			cout << "Poruszasz sie na wyspie jako Cham -";
			cout << *testHuman;
			view.textcolor(7, 0);
			cout << "  za pomoca strzalek";
			Sleep(4000);
			system("cls");
			view.changePosition(15, 5);
			orgBase.introduceOrganisms(15,5);
			Sleep(4000);
		}
		system("cls");
		view.changePosition(15, 12);
		cout << "Jak duza jest wyspa, ktora widzisz przed soba? (dlugosc szerokosc)";
		int m, n;
		cin >> m >> n;
		system("cls");
		while (m * n < 16) {
			system("cls");
			cout << "ZA MALY SWIAT, PODAJ WIEKSZE WYMIARY (min 16 pol)";
			cin >> m >> n;
		}
		Swiat =new World(m, n);
		Swiat->createWorld(orgBase);
	}
	Swiat->drawWorld();
	while(!quit) {
		
			cout << "NACISNIJ n BY URUCHOMIC NASTEPNA RUNDE"<<endl;
			cout << "NACISNIJ s BY ZAPISAC I ZAKONCZYC GRE" << endl;
		do {
			cin >> polecenie;
			if (polecenie == 'q') {
				quit = 1;
				break;
			}
			if (polecenie == 's') {
				quit = 1;
				ofstream saveFile("save.txt");
				Swiat->saveWorld(saveFile);
				saveFile.close();
				break;
			}
		} while (polecenie != 'n');
		if (polecenie == 'n') {
			view.clearPart(0, Swiat->getM() + 3, 40, Swiat->getM() + 10);
			Swiat->nextRound();
			Swiat->drawWorld();
		}
	}



}
