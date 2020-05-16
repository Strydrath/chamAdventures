#pragma once
#include "Animal.h"

class Turtle : public Animal {
private:
	void draw(std::ostream& out) const override;
public:
	Turtle();
	Position action() override;
	int collision(Organism*,bool) override;
	Organism* createNew() override;
	bool sameSpecies(Organism*) override;
	virtual string giveVerb(Organism*) override;
};
