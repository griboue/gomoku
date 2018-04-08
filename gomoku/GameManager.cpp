#include "GameManager.h"


GameManager::~GameManager() {}

GameManager::GameManager(int width, int height)
{
	this->board = Board(width, height);
	this->p1 = Player(BLACK, this->board);
	this->p2 = Player(WHITE, this->board);
}

Board GameManager:: getBoard()
{
	return this->board;
}

Player GameManager::getP1()
{
	return this->p1;
}

Player GameManager::getP2()
{
	return this->p2;
}


char GameManager::isOver()
{
	char** tab = this->board.getBoard();

	// for the lines
	for (int i = 0; i < this->board.getHeight(); i++)
	{
		if (tab[0][i] == 'X' && tab[1][i] == 'X' && tab[2][i] == 'X' && tab[3][i] == 'X' && tab[4][i] == 'X')
		{
			return 'X';
		}
	}
		
	// for the columns
	for (int i = 0; i < this->board.getWidth(); i++)
	{
		if (tab[i][0] == 'X' && tab[i][1] == 'X' && tab[i][2] == 'X' && tab[i][3] == 'X' && tab[i][4] == 'X')
		{
			return 'X';
		}
	}
			
	// for the diags
	if (tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X' && tab[3][3] == 'X' && tab[4][4] == 'X')
	{
		return 'X';
	}

	if (tab[4][0] == 'X' && tab[3][1] == 'X' && tab[2][2] == 'X' && tab[1][3] == 'X' && tab[0][4] == 'X')
	{
		return 'X';
	}
			
	return false;
}

