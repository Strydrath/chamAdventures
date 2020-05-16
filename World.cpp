#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "World.h"
#include "Organism.h"
#include "Position.h"
#include "Plant.h"
#include "View.h"
#include "Human.h"


using namespace std;

class Organism;
class Plant;
class Position;

World::World(int m, int n):m(m),n(n) {
	organisms = new Organism**[m];
	for (int i = 0; i < m; i++)
	{
		organisms[i] = new Organism*[n];
		for (int j = 0; j < n; j++) {
			organisms[i][j] = nullptr;
		}
	}
	logRow++;

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
	if (logRow > 20)logRow = 1;
	view.changePosition((n*2)+3,this->logRow);
	cout << log;
	this->logRow++;
}

void World::nextRound() {
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
void World::createWorld(vector<Organism*>animals, vector<Organism*> plants) {
	Position pos = randomPosition();
	addOrg(pos, new Human);
	for (int i = 0; i < animals.size(); i++) {
		do
			pos = randomPosition();
		while (checkOrg(pos) != nullptr);
		addOrg(pos, animals[i]->createNew());
		do
			pos = randomPosition();
		while (checkOrg(pos) != nullptr);
		addOrg(pos, animals[i]->createNew());
	}
	for (int i = 0; i < plants.size(); i++) {
		do
			pos = randomPosition();
		while (checkOrg(pos) != nullptr);
		addOrg(pos, plants[i]->createNew());
	}
}

void World::drawWorld() {
	View widok;
	widok.clearPart(0, m , 60, m + 4);
	widok.changePosition(0, 0);
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
	int collisionB = b->collision(a, 0);
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