#pragma once
#include "Plant.h"

class Organism;

class Grass : public Plant {
private:
	void draw(std::ostream& out) const override;
public:
	Grass();
	Organism* createNew() override;
	virtual string giveVerb(Organism*) override;
	bool sameSpecies(Organism*) override;
};
