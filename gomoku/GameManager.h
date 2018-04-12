#pragma once
#include "Board.h"
#include "Player.h"
#define EMPTY_CASE 'E'
#define BLACK 'X'
#define WHITE 'O'
#define BOARD_SIZE 5

class GameManager
{
private:
	Board board;
	Player *p1;
	Player *p2;

public:
	GameManager(int width, int height);
	~GameManager();

	Board getBoard();
	Player* getP1();
	Player* getP2();

	bool isFinish();
	bool isDraw();
	int checkWinner();
};
