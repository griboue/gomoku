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
	Player p1;
	Player p2;
	Player* lastMovedPlayer;

public:
	GameManager(int width, int height);
	~GameManager();

	Board getBoard();
	Player getP1();
	Player getP2();
	Player* getLastMovedPlayer();

	bool isFinish();
	friend void setLastMovePlayer(Player p);
};
