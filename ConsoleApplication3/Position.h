#pragma once
class Position {
private:
	int x;
	int y;
public:
	Position();
	Position(int x, int y);
	int getX();
	int getY();
	Position operator + (Position other);
	bool operator == (Position other);
	bool operator != (Position other);
	Position operator * (int other);
};
