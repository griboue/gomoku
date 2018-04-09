#include "Player.h"

Player::Player() {}

Player::Player(char symbol, Board board)
{
	this->symbol = symbol;
	this->board = board;
}

void Player::play(int x, int y)
{
	this->board.getBoard()[x][y] = this->symbol;
	this->lastX = x;
	this->lastY = y;
}

const char Player::getSymbol() {
	return this->symbol;
}

int Player::getLastX() {
	return this->lastX;
}

int Player::getLastY() {
	return this->lastY;
}