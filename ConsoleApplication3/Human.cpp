#include "Human.h"
#include <iostream>
#include <conio.h>
#include "Organism.h"
#include "View.h"
using namespace std;
class Organism;
void Human::draw(std::ostream& out) const {
	View widok;
	widok.textcolor(0, 11);
	cout << this->getSymbol();
}
Human::Human() {
	this->setStrength(5);
	this->setInitiative(4);
	this->setSymbol('&');
	this->setIsDead(false);
	this->setAge(0);
	this->gnuSpeedTour = -5;
	this->setName("Cham");
	this->setNameB("Chama");
	this->setNameN("Chamem");
}
int Human::getGnuSpeedTour() {
	return this->gnuSpeedTour;
}
void Human::setGnuSpeedTour(int s) {
	this->gnuSpeedTour = s;
}

Position Human::humanPosition() {
	bool quit = 0;
	while (1)
	{
		int ex;
		ex =_getch();
		if (ex == 97) {
			this->GnuSpeed();
			cout << "Aktywowano szybksc Antylopy" << endl;
		}
		switch (ex = _getch())
		{
		case 72: 
			return Position(0, -1);//up
			break;
		case 75:  
			return Position(-1, 0);//left
			break;
		case 77:  
			return Position(1, 0);//right
			break;
		case 80: 
			return Position(0, 1);//down
			break;
		case 97:
			this->GnuSpeed();
			cout << "Aktywowano szybksc Antylopy" << endl;
			break;
		default:
			break;
		}
		
	}
	return Position(0, 0);
}

void Human::GnuSpeed() {
	this->gnuSpeedTour = 5;
}

Position Human::action() {
	View view;
	view.clearPart(0, this->getWorld()->getM()+2, 40, this->getWorld()->getM() + 7);
	view.changePosition(0,this->getWorld()->getM() + 4);
	if (this->gnuSpeedTour > 0)
		cout << "SZYBKOSC ANTYLOPY aktywna";
	else if (this->gnuSpeedTour > -5)
		cout << "SZYBKOSC ANTYLOPY dostepna za "<<this->gnuSpeedTour+5<<" rund";
	else
		cout << "Nacisnij a by aktywowac SZYBKOSC ANTYLOPY";
	view.changePosition(0, this->getWorld()->getM() + 5);
	cout << "Wybierz kierunek" << endl;
	Position newPosition;
	int addition = 1;
	do {
		Position movement = humanPosition();
		if (this->gnuSpeedTour > 2)
			addition = 2;
		if (this->gnuSpeedTour > 0) {
			int r = rand() % 2;
			if (r == 0)addition = 2;
		}
		newPosition = this->getPosition() + movement*addition;
	}
	while (!goodPosition(newPosition));

	if (this->gnuSpeedTour > -5)
		this->gnuSpeedTour--;
	view.clearPart(0, this->getWorld()->getM() + 2, 40, this->getWorld()->getM() + 8);
	view.clearPart(0, this->getWorld()->getM() + 5,40,this->getWorld()->getM()+5);
	return newPosition;
}


Organism* Human::createNew() {
	return new Human();
}

bool  Human::sameSpecies(Organism* other) {
	Human* check = dynamic_cast<Human*>(other);
	if (check)
		return true;
	else return false;
}

string Human::giveVerb(Organism* other) {
	Animal* animalCheck = dynamic_cast<Animal*>(other);
	if (animalCheck)
		return "pokonal w walce";
	return "zadeptal";

}