#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include "World.h"
#include "OrganismBase.h"
#include "Organism.h"
#include "Position.h"
#include "Plant.h"
#include "View.h"
#include "Human.h"


using namespace std;

class Organism;
class Plant;
class Position;
class OrganismBase;

World::World(int m, int n):m(m),n(n),round(0),logRow(0) {
	organisms = new Organism**[m];
	for (int i = 0; i < m; i++)
	{
		organisms[i] = new Organism*[n];
		for (int j = 0; j < n; j++) {
			organisms[i][j] = nullptr;
		}
	}

}
int World::getRound() {
	return this->round;
}
void World::setRound(int r) {
	this->round = r;
}
void World::sortList() {
	
	int n = orgList.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++) {
			if (orgList[j]->getInitiative() > orgList[j + 1]->getInitiative()) {
				swap(orgList[j], orgList[j + 1]);
				orgList[j]->setIndeks(j);
			}
			if (orgList[j]->getInitiative()== orgList[j + 1]->getInitiative()) {
				if (orgList[j]->getAge() > orgList[j + 1]->getAge()) {
					swap(orgList[j], orgList[j + 1]);
				}
			}
		}

	for (int i = 0; i < n; i++) {
		orgList[i]->setIndeks(i);
	}
				
	
}

void World::showLog(string log) {
	View view;
	int column = (n * 2);
	if (column < 40)column = 40;
	if (logRow > m)logRow = 0;
	view.clearPart(column + 3,logRow, column + 40, logRow);
	view.clearPart(column + 3, logRow+1, column + 40, logRow+1);
	view.changePosition(column+3,this->logRow);
	cout << log;
	this->logRow++;
}

void World::nextRound() {
	round++;
	for (int i = 0; i < nextList.size(); i++) {
		orgList.push_back(nextList[i]);
	}
	nextList.clear();
	sortList();
	int n = orgList.size();
	Position p;
	Organism* currentOrg;
	for (int i = n-1; i >=0; i--) {
		currentOrg = orgList[i];
		if (!currentOrg->getIsDead()) {
			p = currentOrg->action();
			currentOrg->setAge(currentOrg->getAge() + 1);
			if (p != currentOrg->getPosition()) {
				if (checkOrg(p) != nullptr) {
					if (!checkOrg(p)->getIsDead())
						arena(currentOrg, checkOrg(p), p);
				}
				else {
					Plant* checkP = dynamic_cast<Plant*>(currentOrg);
					if (!checkP)
						moveOrg(p, currentOrg);
				}
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		currentOrg = orgList[i];
		if (currentOrg->getIsDead())
			orgList.erase(orgList.begin() + currentOrg->getIndeks());
	}
}
Position World::randomPosition() {
	int x = rand() % n;
	int y = rand() % m;
	return Position(x, y);
}
void World::createWorld(OrganismBase orgBase) {
	Position pos = randomPosition();
	Position pos2;
	int absx, absy,licz;
	addOrg(pos, new Human);
	for (int i = 0; i < orgBase.getAnimalCount(); i++) {
		do
			pos = randomPosition();
		while (checkOrg(pos) != nullptr);
		addOrg(pos, orgBase.iterateAnimals(i));
		licz = 0;
		do {
			pos2 = randomPosition();
			absx = abs(pos.getX() - pos2.getX());
			absy = abs(pos.getY() - pos2.getY());
			licz++;
		}
		while ((checkOrg(pos2) != nullptr||absx>4||absy>4)&&licz<100);
		if (licz > 100) {
			do
				pos2 = randomPosition();
			while (checkOrg(pos2) != nullptr);
		}
		addOrg(pos2, orgBase.iterateAnimals(i));
	}
	for (int i = 0; i < orgBase.getPlantCount(); i++) {
		do
			pos = randomPosition();
		while (checkOrg(pos) != nullptr);
		addOrg(pos, orgBase.iteratePlants(i));
	}
	for (int i = 0; i < nextList.size(); i++) {
		orgList.push_back(nextList[i]);
	}
	nextList.clear();
	sortList();
}
void World::drawWorld() {
	View widok;
	int sila=0;
	Human* checkHuman;
	for (int i = orgList.size() - 1; i >= 0; i--) {
		checkHuman = dynamic_cast<Human*>(orgList[i]);
		if (checkHuman)sila = orgList[i]->getStrength();
	}
	widok.changePosition(0, 0);
	cout << "Nacisnij q by opuscic gre";
	widok.changePosition(0, 1);
	cout << "RUNDA: " << round;
	widok.changePosition(15, 1);
	cout << "SILA: " << sila;
	widok.clearPart(0, m+1, 40, m + 10);
	widok.changePosition(0, 2);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (organisms[i][j] == nullptr)
				cout << "  ";
			else {
				cout<<*organisms[i][j];
				cout<< " ";
				widok.textcolor(7, 0);
				
			}
		}
		cout << endl;
	}
	Sleep(200);
}

void World::saveWorld(ofstream &outputFile) {
	for (int i = 0; i < nextList.size(); i++) {
		orgList.push_back(nextList[i]);
	}
	nextList.clear();
	sortList();
	outputFile << m << " " << n << " "<<round<<endl;
	Organism* savedOrganism;
	Human* humanCheck;
	for (int i = 0; i < orgList.size(); i++) {
		savedOrganism = orgList[i];
		humanCheck = dynamic_cast<Human*>(savedOrganism);
		outputFile << savedOrganism->getSymbol() << " " << savedOrganism->getStrength()<<" ";
		outputFile << savedOrganism->getPosition().getX() << " " << savedOrganism->getPosition().getY();
		if (humanCheck)outputFile <<" "<< humanCheck->getGnuSpeedTour();
		outputFile << endl;
	}
}

void World::loadWorld(ifstream& inputFile, OrganismBase orgBase) {
	char symbol;
	int strength, x, y,tour;
	Position* position;
	Organism* loadedOrg;
	system("cls");
	Human* checkHuman;
	while (inputFile >> symbol) {
		inputFile >> strength >> x >> y;
		position=new Position(x, y);
		loadedOrg = orgBase.decodeSymbol(symbol);
		addOrg(*position, loadedOrg);
		loadedOrg->setStrength(strength);
		checkHuman = dynamic_cast<Human * > (loadedOrg);
		if (checkHuman) {
			inputFile >> tour;
			checkHuman->setGnuSpeedTour(tour);
		}

	}
	for (int i = 0; i < nextList.size(); i++) {
		orgList.push_back(nextList[i]);
	}
	nextList.clear();
	sortList();
}

void World::addOrg(Position pos, Organism* org) {
	organisms[pos.getY()][pos.getX()] = org;
	nextList.push_back(org);
	org->setPosition(pos);
	org->setWorld(this);
	org->setIsDead(false);
}
void World::deleteOrg(Organism* org) {
	Position pos = org->getPosition();
	organisms[pos.getY()][pos.getX()] = nullptr;
	org->setIsDead(true);
}

void World::moveOrg(Position pos, Organism* org) {
	Position oldPos = org->getPosition();
	organisms[oldPos.getY()][oldPos.getX()] = nullptr;
	organisms[pos.getY()][pos.getX()] = org;
	org->setPosition(pos);
}

Organism*** World::getOrgs() {
	return organisms;
}
int World::getM() {
	return m;
}
int World::getN() {
	return n;
}

void World::arena(Organism* a, Organism*b,Position p) {
	int collisionA = a->collision(b,1);
	if (collisionA ==3) {
		return;
	}
	int collisionB = b->collision(a, 0);
	Human* hcheck = dynamic_cast<Human*>(a);
	if (hcheck) {
		int abac = 9;
	}
	string log = "";
	if (collisionA == 2) {
		this->deleteOrg(b);
		this->moveOrg(p, a);
		return;
	}
	if (collisionB == 2) {
		this->deleteOrg(a);
		return;
	}
	if (collisionA==1 || collisionB == 1) {
		return;
	}
	if (a->getStrength() > b->getStrength()) {
		log += a->getName();
		log += " ";
		log += a->giveVerb(b);
		log += " ";
		log += b->getNameB(); 
		this->deleteOrg(b);
		this->moveOrg(p, a);
	}
	else {
		log += b->getName();
		log += " ";
		log += b->giveVerb(a);
		log += " ";
		log += a->getNameB();
		this->deleteOrg(a);
	}
	showLog(log);
}

Organism* World::checkOrg(Position p) {
	Organism* a= this->organisms[p.getY()][p.getX()];
	return a;
}