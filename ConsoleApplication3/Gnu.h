#pragma once
#include "Animal.h"

class Gnu: public Animal {
private:
	void draw(std::ostream& out) const override;
public:
	Gnu();
	Position action() override;
	int collision(Organism*,bool attack) override;
	Organism* createNew() override;
	bool sameSpecies(Organism*) override;
	virtual string giveVerb(Organism*) override;
};
