#pragma once

#include "Board.h"

class Player
{
private:
	char symbol;
	Board board;

public:
	Player(char symbol, Board board);
	Player();

	void play(int x, int y);
};

