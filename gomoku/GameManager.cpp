#include "GameManager.h"

GameManager::GameManager(int width, int height)
{
	this->board = Board(width, height);
	this->p1 = Player(BLACK, this->board);
	this->p2 = Player(WHITE, this->board);
}

GameManager::~GameManager() {}

Board GameManager::getBoard()
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
	int x = this->board.getLastX();
	int y = this->board.getLastY();
	int counter = 1;	// counter of the linked stones
	char* piece = &tab[x][y]; // the last placed piece to be checked

	/* horizontal line stones count */
	while (y > 0)	// counting backward 
	{
		y--;
		if (tab[x][y] == *piece) {
			counter++;	// if the left stone of the current are the same than p1, increment counter
		}
		else {
			break;	// if the left stone of the current are different than p1, exit the loop 
		}
	}

	if (counter >= 5) {
		return true;	//check if there are already 5 stones in a line
	}

	y = this->board.getLastY();	// reset the vertical axis 
	while (y < BOARD_SIZE)	// counting forward
	{
		y++;
		if (tab[x][y] == *piece) {
			counter++;	// if the right stone of the current are the same than p1, increment counter
		}
		else {
			break;	// if the right stone of the current are different than p1, exit the loop 
		}
	}

	if (counter >= 5) {
		return true;
	}
	/* horizontal line stones count */

	/* vertical line stones count */
	counter = 1;	// reset the counter
	y = this->board.getLastY();	// reset the vertical axis 
	while (x > 0)	// counting upward 
	{
		x--;
		if (tab[x][y] == *piece) {
			counter++;	
		}
		else {
			break;	
		}
	}

	if (counter >= 5) {
		return true;
	}

	x = this->board.getLastX();	// reset the axis 
	while (x < BOARD_SIZE)	// counting downward
	{
		x++;
		if (tab[x][y] == *piece) {
			counter++;
		}
		else {
			break;
		}
	}

	if (counter >= 5) {
		return true;
	}
	/* vertical line stones count */

	/* left diagonal lines stones count */
	counter = 1;	// reset the counter
	x = this->board.getLastX();	// reset the axis 
	while (x > 0 && y > 0)	// counting left upper incline 
	{
		x--;
		y--;
		if (tab[x][y] == *piece) {
			counter++;
		}
		else {
			break;
		}
	}

	if (counter >= 5) {
		return true;
	}

	x = this->board.getLastX();	// reset the axis
	y = this->board.getLastY();	// reset the vertical axis
	while (x < BOARD_SIZE && y < BOARD_SIZE)	// counting downward
	{
		x++;
		y++;
		if (tab[x][y] == *piece) {
			counter++;
		}
		else {
			break;
		}
	}

	if (counter >= 5) {
		return true;
	}
	/* left diagonal line stones count */
	
	/* right diagonal lines stones count */
	counter = 1;	// reset the counter
	x = this->board.getLastX();	// reset the axis
	y = this->board.getLastY();	// reset the vertical axis
	while (y > 0 && x < BOARD_SIZE)	// counting left
	{
		x++;
		y--;
		if (tab[x][y] == *piece) {
			counter++;
		}
		else {
			break;
		}
	}

	if (counter >= 5) {
		return true;
	}

	x = this->board.getLastX();	// reset the axis
	y = this->board.getLastY();	// reset the vertical axis
	while (x > 0 && y < BOARD_SIZE)	// counting right
	{
		x--;
		y++;
		if (tab[x][y] == *piece) {
			counter++;
		}
		else {
			break;
		}
	}

	if (counter >= 5) {
		return true;
	}
	/* right diagonal line stones count */
	
	/*//lignes
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

/*	Function to check which color of pieces won,
	return 1 when black piece won, return 0 when 
	white chess won. Else return -1 as error message
*/
int GameManager::checkWinner() {
	char** board = this->board.getBoard();
	char piece = board[this->board.getLastX()][this->board.getLastY()];
	if (piece == BLACK) {
		return 1;
	}
	else if (piece == WHITE) {
		return 0;
	}
	return -1;
}
