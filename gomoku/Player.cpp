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
}