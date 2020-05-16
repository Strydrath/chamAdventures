#include "Sheep.h"
#include <iostream>
#include "View.h"
using namespace std;

void Sheep::draw(std::ostream& out) const {
	View view;
	view.textcolor(0, 15);
	cout << this->getSymbol();
}
Sheep::Sheep() {
	this->setStrength(4);
	this->setInitiative(4);
	this->setSymbol('O');
	this->setIsDead(false);
	this->setAge(0);
	this->setName("Owca");
	this->setNameB("owce");
	this->setNameN("owca");

}


bool Sheep::sameSpecies(Organism* other) {
	Sheep* check = dynamic_cast<Sheep*>(other);
	if (check)
		return true;
	else return false;
}

Organism* Sheep::createNew() {
	return new Sheep();
}

string Sheep::giveVerb(Organism* other) {
	Animal* animalCheck = dynamic_cast<Animal*>(other);
	if (animalCheck)
		return "pokonala w walce";
	return "zjadla";

}