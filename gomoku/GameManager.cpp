#include "GameManager.h"


GameManager::~GameManager() {}

GameManager::GameManager(int width, int height)
{
	this->board = Board(width, height);
	this->p1 = Player(BLACK, this->board);
	this->p2 = Player(WHITE, this->board);
	this->lastMovedPlayer = NULL;
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

Player* GameManager::getLastMovedPlayer() {
	return this->lastMovedPlayer;
}
/*
void setLastMovePlayer(Player p) {
	GameManager::lastMovedPlayer = &p;
}*/

bool GameManager::isFinish()
{
	char** tab = this->board.getBoard();
	int counter = 1;	// counter of the linked stones
	int x = this->p1.getLastX();
	int y = this->p1.getLastY();

	/* horizontal line stones count */
	while (y > 0)	// counting backward 
	{
		y--;
		if (this->board.getBoard()[x][y] == this->p1.getSymbol()) {
			counter++;	// if the left stone of the current are the same than p1, increment counter
		}
		else {
			break;	// if the left stone of the current are different than p1, exit the loop 
		}
	}

	if (counter >= 5) {
		return true;	//check if there are already 5 stones in a line
	}

	y = this->p1.getLastY();	// reset the vertical axis 
	while (y < BOARD_SIZE)	// counting forward
	{
		y++;
		if (this->board.getBoard()[x][y] == this->p1.getSymbol()) {
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
	y = this->p1.getLastY();	// reset the vertical axis 
	while (x > 0)	// counting upward 
	{
		x--;
		if (this->board.getBoard()[x][y] == this->p1.getSymbol()) {
			counter++;	
		}
		else {
			break;	
		}
	}

	if (counter >= 5) {
		return true;
	}

	x = this->p1.getLastX();	// reset the axis 
	while (x < BOARD_SIZE)	// counting downward
	{
		x++;
		if (this->board.getBoard()[x][y] == this->p1.getSymbol()) {
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
	x = this->p1.getLastX();	// reset the axis 
	while (x > 0 && y > 0)	// counting left upper incline 
	{
		x--;
		y--;
		if (this->board.getBoard()[x][y] == this->p1.getSymbol()) {
			counter++;
		}
		else {
			break;
		}
	}

	if (counter >= 5) {
		return true;
	}

	x = this->p1.getLastX();	// reset the axis
	y = this->p1.getLastY();	// reset the vertical axis
	while (x < BOARD_SIZE && y < BOARD_SIZE)	// counting downward
	{
		x++;
		y++;
		if (this->board.getBoard()[x][y] == this->p1.getSymbol()) {
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
	x = this->p1.getLastX();	// reset the axis
	y = this->p1.getLastY();	// reset the vertical axis
	while (y > 0 && x < BOARD_SIZE)	// counting left
	{
		x++;
		y--;
		if (this->board.getBoard()[x][y] == this->p1.getSymbol()) {
			counter++;
		}
		else {
			break;
		}
	}

	if (counter >= 5) {
		return true;
	}

	x = this->p1.getLastX();	// reset the axis
	y = this->p1.getLastY();	// reset the vertical axis
	while (x > 0 && y < BOARD_SIZE)	// counting right
	{
		x--;
		y++;
		if (this->board.getBoard()[x][y] == this->p1.getSymbol()) {
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

