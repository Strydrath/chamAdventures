#pragma once
#include "Animal.h"
#include "Organism.h"

class Organism;
class Fox: public Animal {
private:
	void draw(std::ostream& out) const override;
public:
	Fox();
	Position action() override;
	Organism* createNew() override;
	bool sameSpecies(Organism*) override;
	virtual string giveVerb(Organism*) override;
};
