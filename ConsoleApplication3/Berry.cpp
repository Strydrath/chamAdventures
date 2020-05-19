#include <iostream>
#include "Berry.h"
#include "View.h"
using namespace std;
class Organism;
class Plant;
void Berry::draw(std::ostream& out) const {
	View view;
	view.textcolor(7, 13);
	cout << this->getSymbol();
}
Berry::Berry() {
	this->setStrength(99);
	this->setInitiative(0);
	this->setSymbol('j');
	this->setChance(0.1);
	this->setAge(0);
	this->setName("Wilcza jagoda");
	this->setNameB("wilcza jagode");
	this->setNameN("wilcza jagoda");
}

Organism* Berry::createNew() {
	return new Berry();
}

bool Berry::sameSpecies(Organism* other) {
	Berry* check = dynamic_cast<Berry*> (other);
	if (check)return true;
	return false;
}

string Berry::giveVerb(Organism*) {
	return "zatrula";
}

int Berry::collision(Organism* other,bool) {
	return 2;
}