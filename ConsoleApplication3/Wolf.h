#pragma once
#include "Animal.h"
class Organism;
class Wolf : public Animal{
private:
	void draw(std::ostream& out) const override;
public:
	Wolf();
	Organism* createNew() override;
	bool sameSpecies(Organism*) override;
	virtual string giveVerb(Organism*) override;
};
