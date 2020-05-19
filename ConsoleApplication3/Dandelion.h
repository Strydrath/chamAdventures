#pragma once
#include "Plant.h"

class Organism;

class Dandelion : public Plant {
private:
	void draw(std::ostream& out) const override;
public:
	Dandelion();
	Position action() override;
	Organism* createNew() override;
	bool sameSpecies(Organism*) override;
	virtual string giveVerb(Organism*) override;
};
