#include "Board.h"
#include "GameManager.h"

Board::Board ()
{

}

Board::Board (int width, int height)
{
	this->width = width;
	this->height = height;

	// initialize the board 2d array with
	// correct size and with E (for empty)
	boardFirstInitialization();
}


int Board::getWidth()
{
	return this->width;
}

int Board::getHeight()
{
	return this->height;
}

int Board::getMaxChessNum() {
	return this->width * this->height;
}

char** Board::getBoard()
{
	return this->board;
}

void Board::boardFirstInitialization()
{
	// size allocation of the array
	this->board = new char*[width];
	for (int i = 0; i < width; ++i)
	{
		board[i] = new char[height];
	}

	// fill the array with E (for Empty)
	this->clear();
}

void Board::clear() {
	// fill the array with E (for Empty)
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			this->board[i][j] = EMPTY_CASE;
		}
	}
	this->resetCounter();
	this->setLastMovedPos(0, 0);
}

void Board::displayBoard()
{
	// displaying the board in a certain format
	// the bottom left hand corner is (0,0)
	// the top right hand corner is (4,4)

	for (int i = (width-1); i > -1; i--)
	{
		for (int j = 0; j < height; j++)
		{
			std::cout << this->board[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "lastPos : " << this->lastX << ", " << this->lastY << std::endl;
	std::cout << "Chess count : " << this->chessCounter << std::endl << std::endl;
}

int Board::getLastX() {
	return this->lastX;
}

int Board::getLastY() {
	return this->lastY;
}

char Board::getLastChess() {
	return this->board[this->lastX][this->lastY];
}

void Board::setLastMovedPos(int x, int y) {
	this->lastX = x;
	this->lastY = y;
}

void Board::setCell(int x, int y, char piece) {
	
	// place a chess
	if (this->board[x][y] == EMPTY_CASE && piece != EMPTY_CASE) {
		this->chessCounter++;
	}

	// case when a player do a retraction action
	else if (this->board[x][y] != EMPTY_CASE && piece == EMPTY_CASE) {
		this->chessCounter--;
	}

	this->board[x][y] = piece;
}

// fonction to check if the given case coordinate in the board is empty
bool Board::isEmpty(int x, int y) {
	return this->board[x][y] == EMPTY_CASE;
}

bool Board::isFull() {
	return this->chessCounter == this->getMaxChessNum();
}

void Board::resetCounter() {
	this->chessCounter = 0;
}