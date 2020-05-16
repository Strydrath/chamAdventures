#include <iostream>
#include "Barszcz.h"
#include "View.h"
#include "Animal.h"
using namespace std;
class Organism;
class Plant;
void Barszcz::draw(std::ostream& out) const {
	View view;
	view.textcolor(7, 13);
	cout << this->getSymbol();
}
Barszcz::Barszcz() {
	this->setStrength(10);
	this->setInitiative(0);
	this->setSymbol('b');
	this->setChance(0.1);
	this->setAge(0);
	this->setName("Barszcz");
	this->setNameB("barszcz");
	this->setNameN("barszczem");
}

Position Barszcz::action() {
	World* world = this->getWorld();
	Position checkPosition = this->getPosition() + Position(0, 1);
	Animal*check;
	if (goodPosition(checkPosition)) {
		Organism* nearAnimal = world->checkOrg(checkPosition);
		check = dynamic_cast<Animal*>(nearAnimal);
		if(check)
		world->deleteOrg(nearAnimal);
	}
	checkPosition = this->getPosition() + Position(0, -1);
	if (goodPosition(checkPosition)) {
		Organism* nearAnimal = world->checkOrg(checkPosition);
		check = dynamic_cast<Animal*>(nearAnimal);
		if (check)
			world->deleteOrg(nearAnimal);
	}
	checkPosition = this->getPosition() + Position(1, 0);
	if (goodPosition(checkPosition)) {
		Organism* nearAnimal = world->checkOrg(checkPosition);
		check = dynamic_cast<Animal*>(nearAnimal);
		if (check)
			world->deleteOrg(nearAnimal);
	}
	checkPosition = this->getPosition() + Position(-1, 0);
	if (goodPosition(checkPosition)) {
		Organism* nearAnimal = world->checkOrg(checkPosition);
		check = dynamic_cast<Animal*>(nearAnimal);
		if (check)
			world->deleteOrg(nearAnimal);
	}
	return this->getPosition();
}

Organism* Barszcz::createNew() {
	return new Barszcz();
}

string Barszcz::giveVerb(Organism*) {
	return "zatrul";
}

bool Barszcz::sameSpecies(Organism* other) {
	Barszcz* check = dynamic_cast<Barszcz*>(other);
	if (check)return true;
	return false;
}

int Barszcz::collision(Organism* other, bool) {
	return 2;
}