#pragma once

#include "Board.h"


class Player
{
private:
	char symbol;
	Board *board;

public:
	Player();
	Player(char symbol, Board *board);
	~Player();

	void play(int x, int y);
	const char getSymbol();
	//friend bool operator==(Player &p1, Player &p2);
};

