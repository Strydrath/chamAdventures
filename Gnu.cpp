#include <iostream>
#include "Gnu.h"
using namespace std;

void Gnu::draw(std::ostream& out) const {
	cout << this->getSymbol();
}

Gnu::Gnu() {
	this->setStrength(4);
	this->setInitiative(4);
	this->setSymbol('A');
	this->setIsDead(false);
	this->setAge(0);
	this->setName("Antylopa");
	this->setNameB("antylope");
	this->setNameN("antylopa");
}

Position Gnu::action() {
	Position newPosition;
	do
		newPosition = this->getPosition() + randomPosition()*2;
	while (!goodPosition(newPosition));
	return newPosition;
}

int Gnu::collision(Organism*,bool attack) {
	int r = rand() % 10;
	if (r < 5) {
		Position newPosition;
		do
			newPosition =this->getPosition() + randomPosition();
		while (!goodPosition(newPosition));
		this->getWorld()->moveOrg(newPosition, this);
		this->setPosition(newPosition);
		return 1;
	}
	return 0;
}

string Gnu::giveVerb(Organism* other) {
	Animal* animalCheck = dynamic_cast<Animal*>(other);
	if (animalCheck) {
		if (other->getStrength() > getStrength())
			return "uciekla przed";
		return "pokona?a w walce";
	}
	return "zjad?a";
}

bool Gnu::sameSpecies(Organism* other) {
	Gnu* check = dynamic_cast<Gnu*>(other);
	if (check)
		return true;
	else return false;
}

Organism* Gnu::createNew() {
	return new Gnu();
}
