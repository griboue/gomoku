#include "Board.h"



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


int Board::getWidth ()
{
	return this->width;
}

int Board::getHeight()
{
	return this->height;
}

char ** Board::getBoard()
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
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			this->board[i][j] = EMPTY_CASE;
		}
	}
	
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
}


