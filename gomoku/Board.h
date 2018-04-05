#pragma once
#include <iostream>

class Board
{
private:
	 int width;
	 int height;

	 char** board;


public:
	// Constructors, Getters and Setters
	Board();
	Board(int width, int height);
	int getWidth();
	int getHeight();
	char** getBoard();

	// Methods
	void boardFirstInitialization();
	void displayBoard();

};
