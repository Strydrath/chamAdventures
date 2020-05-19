#include "Turtle.h"
#include <iostream>
#include "View.h"
using namespace std;

void Turtle::draw(std::ostream& out) const {
	View widok;
	widok.textcolor(7, 9);
	cout << this->getSymbol();
}
Turtle::Turtle() {
	this->setStrength(2);
	this->setInitiative(1);
	this->setSymbol('Z');
	this->setIsDead(false);
	this->setAge(0);
	this->setName("Zolw");
	this->setNameB("zolwia");
	this->setNameN("zolwiem");

}

Position Turtle::action() {
	int r = rand() % 4;
	if (r ==3) {
		Position newPosition;
		do
		newPosition= this->getPosition() + randomPosition();
		while (!goodPosition(newPosition));
		return newPosition;
	}
	return this->getPosition();
	
}

int Turtle::collision(Organism* other,bool attack) {
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
			log += " rozmnozyl sie z ";
			log += other->getNameN();
			getWorld()->showLog(log);
		}
		return 3;
	}
	if (other->getStrength() < 5 &&attack==0) {
		return 1;
	}
	return 0;
}

bool Turtle::sameSpecies(Organism* other) {
	Turtle* check = dynamic_cast<Turtle*>(other);
	if (check)
		return true;
	else return false;
}

Organism* Turtle::createNew() {
	return new Turtle();
}

string Turtle::giveVerb(Organism* other) {
	Animal* animalCheck = dynamic_cast<Animal*>(other);
	if (animalCheck) {
		if (other->getStrength() < 5)
			return "odstraszyl";
		return "pokonal w walce";
	}	
	return "zjadl";
}