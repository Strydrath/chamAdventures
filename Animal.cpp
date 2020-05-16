#include "Animal.h"
#include"World.h"
#include <iostream>
#include "Position.h"
using namespace std;

class World;

Position Animal::action() {
	Position newPosition;
	do
		newPosition = this->getPosition() + randomPosition();
	while (!goodPosition(newPosition));
	return newPosition;
}

int Animal::collision(Organism* other,bool attack) {

	if (sameSpecies(other)) {
		int r = rand() % 2;
		Position pos;
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
			this->getWorld()->addOrg(pos, this->createNew());
		return 1;
	}
	return 0;
}