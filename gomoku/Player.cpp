#include "Player.h"

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
bool operator==(Player &p1, Player &p2) {
	return p1.getSymbol() == p2.getSymbol() && p1.board == p2.board;
}*/