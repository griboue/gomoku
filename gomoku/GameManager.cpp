#include "GameManager.h"


GameManager::~GameManager() {}

GameManager::GameManager(int width, int height)
{
	this->board = Board(width, height);
	this->p1 = Player('X', this->board);
	this->p2 = Player('O', this->board);
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


bool GameManager::isFinish()
{
	char** tab = this->board.getBoard();

	//lignes
	for (int i = 0; i < this->board.getWidth(); i++)
	{
		if (tab[0][i] == 'X' && tab[1][i] == 'X' && tab[2][i] == 'X' && tab[3][i] == 'X' && tab[4][i] == 'X')
		{
			return true;
		}
	}
		
			
	/*
	//columns
	for (size_t i = 0; i <  this->board.getWidth; i++)
		if (tab[0][i] == playerSign && tab[1][i] == playerSign && tab[2][i] == playerSign && tab[3][i] == playerSign && tab[4][i] == playerSign)
			return true;

	//diags
	if (tab[0][0] == playerSign && tab[1][1] == playerSign && tab[2][2] == playerSign && tab[3][3] == playerSign && tab[4][4] == playerSign)
		return true;
	if (tab[4][0] == playerSign && tab[3][1] == playerSign && tab[2][2] == playerSign && tab[1][3] == playerSign && tab[0][4] == playerSign)
		return true;
		*/
	return false;
}

