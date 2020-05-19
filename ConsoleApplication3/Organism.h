
#pragma once
#include <iostream>
#include "World.h"
#include "Position.h"

class World;
using namespace std;
class Organism {
private:

	int strength;
	int initiative;
	int age;
	int indeks;
	Position position;
	World *world;
	char symbol;
	bool isDead;
	string name;
	string nameBiernik;
	string nameNarzednik;
	virtual void draw(std::ostream& out) const = 0;
public:
	friend std::ostream& operator<<(std::ostream& os, const Organism&org);
	int getStrength() const;
	void setStrength(int s);
	int getInitiative() const;
	void setInitiative(int i);
	World* getWorld();
	void setWorld(World* w);
	bool goodPosition(Position);
	int getAge() const;
	void setAge(int);
	int getIndeks() const;
	void setIndeks(int);
	char getSymbol() const;
	void setSymbol(char);
	bool getIsDead() const;
	void setIsDead(bool);
	Position getPosition()const;
	void setPosition(Position);
	string getName() const;
	void setName(string);
	string getNameB() const;
	void setNameB(string);
	string getNameN() const;
	void setNameN(string);


	virtual Position action() = 0;
	virtual int collision(Organism*,bool) = 0;
	virtual bool sameSpecies(Organism*) = 0;
	virtual string giveVerb(Organism*) = 0;

	virtual Organism* createNew() = 0;
	Position randomPosition() const;
};