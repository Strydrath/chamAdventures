#pragma once
#include "Organism.h"

class Animal : public Organism {
private:
	double chance;
public:
	Position action() override;
	bool sameSpecies(Organism*) override=0;
	int collision(Organism*,bool) override;
	virtual string giveVerb(Organism*) override=0;
};
