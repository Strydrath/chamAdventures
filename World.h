#pragma once
#include <iostream>
#include <vector>
#include "Organism.h"
class Organism;
class Position; 
using namespace std;
class World{
private:
	Position* a;
	Organism*** organisms;
	vector <Organism* > orgList;
	vector <Organism*> nextList;
	int m;
	int n;
	int logRow;
public:
	World(int, int );
	int getM();
	int getN();
	void nextRound();
	void drawWorld();
	void sortList();
	void addOrg(Position, Organism *);
	void createWorld(vector<Organism*>,vector <Organism*>);
	void deleteOrg(Organism *);
	void moveOrg(Position, Organism*);
	Organism ***getOrgs();
	void showLog(string);
	void arena(Organism* a, Organism*b,Position p);
	Organism* checkOrg(Position);
	Position randomPosition();
};
