#pragma once
#include "Animal.h"

class Sheep : public Animal {
private:
	void draw(std::ostream& out) const override;
public:
	Sheep();
	Organism* createNew() override;
	bool sameSpecies(Organism*) override;
	virtual string giveVerb(Organism*) override;
};
