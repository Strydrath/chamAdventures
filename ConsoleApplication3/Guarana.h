#pragma once
#include "Plant.h"

class Organism;

class Guarana: public Plant {
private:
	void draw(std::ostream& out) const override;
public:
	Guarana();
	Organism* createNew() override;
	int collision(Organism*,bool) override;
	virtual string giveVerb(Organism*) override;
	bool sameSpecies(Organism*) override;
};
