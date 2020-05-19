#pragma once
#include <iostream>
#include <vector>
#include "Organism.h"
#include "OrganismBase.h"
#include <fstream>
class Organism;
class Position; 
class OrganismBase;

using namespace std;
class World{
private:
	Organism*** organisms;
	vector <Organism* > orgList;
	vector <Organism*> nextList;
	int m;
	int n;
	int logRow;
	int round;
	void sortList();
	void arena(Organism* a, Organism*b,Position p);
	Position randomPosition();
public:
	World(int, int );
	int getM();
	int getN();
	void addOrg(Position, Organism *);
	void deleteOrg(Organism *);
	void moveOrg(Position, Organism*);
	void nextRound();
	void drawWorld();
	void createWorld(OrganismBase);
	Organism ***getOrgs();
	void showLog(string);
	void saveWorld(ofstream&);
	void loadWorld(ifstream&,OrganismBase);
	void setRound(int);
	int getRound();
	Organism* checkOrg(Position);
};
