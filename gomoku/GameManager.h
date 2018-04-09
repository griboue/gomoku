#pragma once

#include "Board.h"
#include "Player.h"
#define EMPTY_CASE 'E'
#define BLACK 'X'
#define WHITE 'O'


class GameManager
{
private:
	Board board;
	Player p1;
	Player p2;

public:
	GameManager(int width, int height);
	~GameManager();

	Board getBoard();
	Player getP1();
	Player getP2();

	char isOver();
};

