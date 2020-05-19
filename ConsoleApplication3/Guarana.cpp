#include <iostream>
#include "Guarana.h"
#include "View.h"
using namespace std;
class Organism;
class Plant;
void Guarana::draw(std::ostream& out) const {
	View view;
	view.textcolor(7, 5);
	cout << this->getSymbol();
}
Guarana::Guarana() {
	this->setStrength(0);
	this->setInitiative(0);
	this->setSymbol('g');
	this->setChance(0.2);
	this->setIsDead(false);
	this->setAge(0);
	this->setName("Guarana");
	this->setNameB("guarane");
	this->setNameN("guarana");
}

Organism* Guarana::createNew() {
	return new Guarana();
}

bool Guarana::sameSpecies(Organism* other) {
	Guarana* check  = dynamic_cast<Guarana*>(other);
	if (check)return true;
	return false;
}

int Guarana::collision(Organism* other,bool attack) {
	other->setStrength(other->getStrength() + 3);
	return 0;
}

string Guarana::giveVerb(Organism* other) {
	return "";

}