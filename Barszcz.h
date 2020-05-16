#pragma once
#include "Plant.h"

class Organism;

class Barszcz : public Plant {
private:
	void draw(std::ostream& out) const override;
public:
	Barszcz();
	Organism* createNew() override;
	Position action()override;
	int collision(Organism*, bool) override;
	string giveVerb(Organism*) override;
	bool sameSpecies(Organism*) override;
};
