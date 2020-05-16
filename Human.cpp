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
	this->gnuSpeedTour = 0;
	this->setName("CHAM");
	this->setNameB("CHAM");
	this->setNameN("CHAM");
}
Position Human::humanPosition() {
	bool quit = 0;
	while (1)
	{
		int ex;
		switch (ex = _getch())
		{
		case 72:     /* H */
			return Position(0, -1);//up
			break;
		case 75:   /* K */
			return Position(-1, 0);//left
			break;
		case 77:   /* M */
			return Position(1, 0);//right
			break;
		case 80: /* P */
			return Position(0, 1);//down
			break;
		case 65:
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
	this->gnuSpeedTour = 3;
}

Position Human::action() {
	View view;
	view.changePosition(0,this->getWorld()->getM() + 1);
	cout << "Nacisnij A by aktywowac SZYBKOSC ANTYLOPY";
	view.changePosition(0, this->getWorld()->getM() + 2);
	cout << "WYBIERZ KIERUNEK" << endl;
	Position newPosition;
	int addition = 1;
	do {
		Position movement = humanPosition();
		if (this->gnuSpeedTour > 0)
			addition = 2;
		newPosition = this->getPosition() + movement*addition;
	}
	while (!goodPosition(newPosition));

	if (this->gnuSpeedTour > 0)
		this->gnuSpeedTour--;
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