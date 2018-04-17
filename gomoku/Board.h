#pragma once
#include <iostream>

class Board
{
private:
	 int width;
	 int height;
	 int lastX;
	 int lastY;
	 int chessCounter;
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
	void clear();
	void displayBoard();
	int getLastX();
	int getLastY();
	char getLastChess();
	int getMaxChessNum();
	void setLastMovedPos(int x, int y);
	void setCell(int x, int y, char piece);
	bool isEmpty(int x, int y);
	bool isFull();
	void resetCounter();
};

