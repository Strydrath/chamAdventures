#include "Dandelion.h"
#include <iostream>
using namespace std;

class Organism;
void Dandelion::draw(std::ostream& out) const {
	cout << this->getSymbol();
}
Dandelion::Dandelion(){
	this->setStrength(0);
	this->setInitiative(0);
	this->setSymbol('m');
	this->setChance(0.2);
	this->setAge(0);
	this->setName("Mlecz");
	this->setNameB("mlecz");
	this->setNameN("mleczem");
}

Position Dandelion::action() {
	Position newPosition;
	for(int i=0; i<3;i++){
		newPosition = this->getPosition() + randomPosition();
		do {
			newPosition = this->getPosition() + randomPosition();
		}while (!goodPosition(newPosition));

		double r = ((double)rand() / (RAND_MAX));
		if (r <=this->getChance()) {
			if (this->getWorld()->checkOrg(newPosition) == nullptr) {
				Organism* newPlant = this->createNew();
				newPlant->setPosition(newPosition);
				this->getWorld()->addOrg(newPosition, newPlant);
			}
		}
	}
	return this->getPosition();
}

bool Dandelion::sameSpecies(Organism* other) {
	Dandelion* check = dynamic_cast<Dandelion*>(other);
	if (check)return true;
	return false;
}

string Dandelion::giveVerb(Organism*) {
	return "";
}

Organism* Dandelion::createNew() {
	return new Dandelion();
}
