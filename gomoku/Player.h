#pragma once

#include "Board.h"


class Player
{
private:
	char symbol;
	Board *board;
	bool retract;

public:
	Player();
	Player(char symbol, Board *board);
	~Player();

	void play(int x, int y);
	const char getSymbol();
	bool getRetract();
	void doRetract();
};

