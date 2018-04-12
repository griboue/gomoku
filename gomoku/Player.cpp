#include "Player.h"
#include "GameManager.h"

Player::Player() {}

Player::~Player() {}

Player::Player(char symbol, Board *board)
{
	this->symbol = symbol;
	this->board = board;
}

void Player::play(int x, int y)
{
	this->board->setCell(x, y, this->symbol);
	this->board->setLastMovedPos(x, y);
}

const char Player::getSymbol() {
	return this->symbol;
}

/*
bool Player::isRetract() {
	return this->retract;
}

void Player::retract() {
	this->board->setCell(this->board->getLastX(), this->board->getLastY(), EMPTY_CASE);
	this->retract = true;
}
*/