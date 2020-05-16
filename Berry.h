#pragma once
#include "Plant.h"

class Organism;

class Berry : public Plant {
private:
	void draw(std::ostream& out) const override;
public:
	Berry();
	Organism* createNew() override;
	int collision(Organism*,bool) override;
	virtual string giveVerb(Organism*) override;
	bool sameSpecies(Organism*) override;
};
