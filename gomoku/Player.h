#pragma once
#include "Board.h"
#define BLACK 'X'
#define WHITE 'O'

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
