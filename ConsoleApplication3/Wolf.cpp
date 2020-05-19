#include "Wolf.h"
#include <iostream>
#include "View.h"
using namespace std;

void Wolf::draw(std::ostream& out) const {
	View widok;
	widok.textcolor(0, 7);
	cout << this->getSymbol();
}
Wolf::Wolf(){
	this->setStrength(9);
	this->setInitiative(5);
	this->setSymbol('W');
	this->setIsDead(false);
	this->setAge(0);
	this->setName("Wilk");
	this->setNameB("wilka");
	this->setNameN("wilkiem");

}

bool Wolf::sameSpecies(Organism* other) {
	Wolf* check = dynamic_cast<Wolf*>(other);
	if (check)
		return true;
	else return false;
}

Organism* Wolf::createNew() {
	return new Wolf();
}

string Wolf::giveVerb(Organism* other) {
	Animal* animalCheck = dynamic_cast<Animal*>(other);
	if (animalCheck)
		return "zagryzl i zjadl";
	return "zadeptal";

}