#include <iostream>
#include "Position.h"

using namespace std;
Position::Position(){}
Position::Position(int x, int y) :x(x), y(y) {}

Position Position::operator + (Position other) {
	return Position(x + other.x, y + other.y);
}

Position Position::operator * (int other) {
	return Position(x * other, y * other);
}

bool Position::operator == (Position other) {
	if (x == other.x &&y == other.y)
		return true;
	return false;
}
bool Position::operator != (Position other) {
	if (x == other.x &&y == other.y)
		return false;
	return true;
}

int Position::getX() {
	return this->x;
}
int Position::getY() {
	return this->y;
}
