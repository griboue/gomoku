#pragma once

#include "Board.h"

class Player
{
private:
	char symbol;
	Board board;
	int lastX;
	int lastY;

public:
	Player(char symbol, Board board);
	Player();

	void play(int x, int y);
	const char getSymbol();
	int getLastX();
	int getLastY();
};

