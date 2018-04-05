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

