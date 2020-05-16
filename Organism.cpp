#include <iostream>
#include <ctime>
#include <cstdlib>
#include "World.h"
#include "Position.h"
#include "Organism.h"

class Organism;
std::ostream& operator<<(std::ostream& os, const Organism& organism) {
	organism.draw(os);
	return os;
}

int Organism::getStrength() const {
	return this->strength;
}
void Organism::setStrength(int s) {
	this->strength = s;
}

int Organism::getAge() const {
	return this->age;
}
void Organism::setAge(int a) {
	this->age= a;
}

int Organism::getIndeks() const {
	return this->indeks;
}
void Organism::setIndeks(int i) {
	this->indeks = i;
}

bool Organism::getIsDead() const {
	return this->isDead;
}
void Organism::setIsDead(bool i) {
	this->isDead = i;
}

int Organism::getInitiative() const {
	return this->initiative;
}
void Organism::setInitiative(int i) {
	this->initiative = i;
}

char Organism::getSymbol() const {
	return this->symbol;
}
void Organism::setSymbol(char s) {
	this->symbol = s;
}


Position Organism::getPosition() const {
	return this->position;
}
void Organism::setPosition(Position p){
	this->position = p;
}

string Organism::getName() const{ 
	return this->name; 
}
void Organism::setName(string n){
	this->name = n;
}

string Organism::getNameB() const {
	return this->nameBiernik;
}
void Organism::setNameB(string n) {
	this->nameBiernik = n;
}

string Organism::getNameN() const {
	return this->nameNarzednik;
}
void Organism::setNameN(string n) {
	this->nameNarzednik = n;
}

World* Organism::getWorld() {
	return this->world;
}
void Organism::setWorld(World* w) {
	this->world=w;
}

bool Organism::goodPosition(Position position) {
	if (position.getX() < 0 || position.getY() < 0 || position.getX() >= world->getN() || position.getY() >= world->getM())
		return false;
	return true;

}

Position Organism::randomPosition()const {
	int a=rand()%4;
	if (a == 0) {
		return Position(0, -1);
	}
	if (a == 1) {
		return Position(0, 1);
	}
	if (a == 2) {
		return Position(-1, 0);
	}
	return Position(1, 0);
}
 
