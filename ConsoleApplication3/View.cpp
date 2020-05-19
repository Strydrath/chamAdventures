#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <wchar.h>
#include <fcntl.h>
#include "View.h"

using namespace std;
void View::textcolor(int color, int bg) {
	CONSOLE_SCREEN_BUFFER_INFO buffer;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &buffer);

	SetConsoleTextAttribute(h, color + (bg << 4));
}

void View::changePosition(int column, int line) {
	COORD where;
	where.X = column;
	where.Y = line;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!SetConsoleCursorPosition(h, where))
	{
		printf("something went wrong");
	}
}

void View::clearPart(int startx, int starty, int endx, int endy){
	changePosition(startx, starty);
	for (int i = starty; i <= endy; i++) {
		for (int j = startx; j <= endx; j++) {
			cout << " ";
		}
	}
}