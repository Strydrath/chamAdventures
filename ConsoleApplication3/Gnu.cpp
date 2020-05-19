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

int Gnu::collision(Organism* other,bool attack) {
	if (sameSpecies(other)) {
		int r;
		Position pos;
		string log = "";
		for (int i = 0; i < 20; i++) {
			r = rand() % 2;
			if (r == 0) {
				do
					pos = this->getPosition() + randomPosition();
				while (!goodPosition(pos));
			}
			if (r == 1) {
				do
					pos = other->getPosition() + randomPosition();
				while (!goodPosition(pos));
			}
			if (getWorld()->checkOrg(pos) == nullptr)
				break;
		}
		if (getWorld()->checkOrg(pos) == nullptr) {
			this->getWorld()->addOrg(pos, this->createNew());
			log += this->getName();
			log += " rozmnozyla sie z ";
			log += other->getNameN();
			getWorld()->showLog(log);
		}
		return 3;
	}
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
		return "pokonala w walce";
	}
	return "zjadla";
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
