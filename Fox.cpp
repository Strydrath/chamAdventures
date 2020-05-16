#include "Fox.h"
#include <iostream>
#include "Organism.h"
#include "Plant.h"
#include "View.h"
using namespace std;
class Organism;
class Plant;

void Fox::draw(std::ostream& out) const {
	View widok;
	widok.textcolor(7, 12);
	cout << this->getSymbol();
}
Fox::Fox() {
	this->setStrength(3);
	this->setInitiative(7);
	this->setSymbol('L');
	this->setIsDead(false);
	this->setAge(0);
	this->setName("Lis");
	this->setNameB("lisa");
	this->setNameN("lisem");
}

Position Fox::action() {
	Position newPosition;
	for (int i = 0; i < 10; i++) {
		do
			newPosition = this->getPosition() + randomPosition();
		while (!goodPosition(newPosition));
		if (this->getWorld()->checkOrg(newPosition) == nullptr) {
			break;
		}
		else if (this->getWorld()->checkOrg(newPosition)->getStrength() > this->getStrength()) {
			newPosition = this->getPosition();
		}
		else {
			break;
		}
	}
	return newPosition;
}

bool Fox::sameSpecies(Organism* other) {
	Fox* check = dynamic_cast<Fox*>(other);
	if (check)
		return true;
	else return false;
}

string Fox::giveVerb(Organism* other) {
	Animal* animalCheck = dynamic_cast<Animal*>(other);
	if (animalCheck)
		return "pokonal w walce";
	return "zjadl";

}

Organism* Fox::createNew() {
	return new Fox();
}