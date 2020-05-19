#include "OrganismBase.h"
#include <iostream>
#include <vector>
#include "Dandelion.h"
#include "Fox.h"
#include "Grass.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Gnu.h"
#include "Turtle.h"
#include "Guarana.h"
#include "Human.h"
#include "Berry.h"
#include "Barszcz.h"
#include "View.h"

using namespace std;
OrganismBase::OrganismBase() {
	animalsTable.push_back(new Fox);
	animalsTable.push_back(new Wolf);
	animalsTable.push_back(new Sheep);
	animalsTable.push_back(new Gnu);
	animalsTable.push_back(new Turtle);
	plantsTable.push_back(new Dandelion);
	plantsTable.push_back(new Grass);
	plantsTable.push_back(new Guarana);
	plantsTable.push_back(new Berry);
	plantsTable.push_back(new Barszcz);
	animalCount = animalsTable.size();
	plantCount = plantsTable.size();
}

int OrganismBase::getAnimalCount() {
	return this->animalCount;
}

int OrganismBase::getPlantCount() {
	return this->plantCount;
}

Organism* OrganismBase::iterateAnimals(int iterator) {
	if (iterator < animalsTable.size())
		return animalsTable[iterator]->createNew();
	return nullptr;
}
Organism* OrganismBase::iteratePlants(int iterator) {
	if (iterator < plantsTable.size())
		return plantsTable[iterator]->createNew();
	return nullptr;
}

Organism* OrganismBase::decodeSymbol(char symbol) {
	if (symbol == '&')return new Human;
	for (int i = 0; i < animalsTable.size(); i++) {
		if (symbol == animalsTable[i]->getSymbol())
			return animalsTable[i]->createNew();
	}
	for (int i = 0; i < plantsTable.size(); i++) {
		if (symbol == plantsTable[i]->getSymbol())
			return plantsTable[i]->createNew();
	}
	return nullptr;
}

void OrganismBase::introduceOrganisms(int startX, int startY) {
	View view;
	for (int i = 0; i < animalsTable.size(); i++) {
		view.changePosition(startX, startY + i);
		cout << *animalsTable[i];
		view.textcolor(7, 0);
		cout << " - " << animalsTable[i]->getName();
	}
	for (int i = 0; i < plantsTable.size(); i++) {
		view.changePosition(startX, startY+animalsTable.size()+ i);
		cout << *plantsTable[i];
		view.textcolor(7, 0);
		cout << " - " << plantsTable[i]->getName();
	}
}