#pragma once

#include <iostream>

class Board
{
private:
	 int width;
	 int height;
	 int lastX;
	 int lastY;
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
	int getLastX();
	int getLastY();
	void setLastMovedPos(int x, int y);
	void setCell(int x, int y, char piece);
};

