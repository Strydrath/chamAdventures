#pragma once
#include <iostream>
#include <vector>
#include "Organism.h"

class Organism;
using namespace std;
class OrganismBase
{
private:
	vector <Organism*> animalsTable;
	vector <Organism*> plantsTable;
	int animalCount;
	int plantCount;

public:
	OrganismBase();
	int getAnimalCount();
	int getPlantCount();
	Organism* iterateAnimals(int iterator);
	Organism* iteratePlants(int iterator);
	Organism* decodeSymbol(char symbol);
	void introduceOrganisms(int,int);
};

