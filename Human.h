#pragma once
#include "Animal.h"

class Human : public Animal {
private:
	void draw(std::ostream& out) const override;
	int gnuSpeedTour;
public:
	Human();
	Position action() override;
	//int collision(Organism*,bool) override;
	void GnuSpeed();
	Position humanPosition();
	Organism* createNew() override;
	bool sameSpecies(Organism*) override;
	virtual string giveVerb(Organism*) override;
};
