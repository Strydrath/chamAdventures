#pragma once
#include "Organism.h"
class Plant : public Organism {
private:
	double chance;
public:
	Position action() override;
	int collision(Organism*,bool) override;
	virtual Organism* createNew() override =0;
	double getChance();
	void setChance(double);
	bool sameSpecies(Organism*) override =0;
	virtual string giveVerb(Organism*) override =0;
};
