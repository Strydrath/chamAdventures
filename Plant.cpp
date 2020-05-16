#include "Plant.h"
#include"World.h"
#include <iostream>
using namespace std;

class World;

Position Plant::action() {
	Position newPosition;
	do
		newPosition = this->getPosition() + randomPosition();
	while (!goodPosition(newPosition));

	double r = ((double)rand() / (RAND_MAX));
	if (r <= this->chance&&this->getWorld()->checkOrg(newPosition)==nullptr) {
		Organism* newPlant = this->createNew();
		newPlant->setPosition(newPosition);
		this->getWorld()->addOrg(newPosition,newPlant);
	}
	return this->getPosition();
}
int Plant::collision(Organism* other, bool attack) {
	return 0;
}

double Plant::getChance() {
	return this->chance;
}
void Plant::setChance(double c) {
	this->chance =c;
}