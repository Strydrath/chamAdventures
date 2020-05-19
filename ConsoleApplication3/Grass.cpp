#include <iostream>
#include "Grass.h"
#include "View.h"
using namespace std;
class Organism;
class Plant;
void Grass::draw(std::ostream& out) const {
	View view;
	view.textcolor(7, 10);
	cout << this->getSymbol();
}
Grass::Grass() {
	this->setStrength(0);
	this->setInitiative(0);
	this->setSymbol('t');
	this->setChance(0.3);
	this->setIsDead(false);
	this->setAge(0);
	this->setName("Trawa");
	this->setNameB("trawe");
	this->setNameN("trawa");

}

Organism* Grass::createNew() {
	return new Grass();
}

bool Grass::sameSpecies(Organism* other) {
	Grass* check = dynamic_cast<Grass*>(other);
	if (check)return true;
	return false;
}

string Grass::giveVerb(Organism*) {
	return"";
}