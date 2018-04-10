#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "GraphicManager.h"

using namespace std;

int main()
{
	GameManager gm(BOARD_SIZE, BOARD_SIZE);
	gm.getBoard().displayBoard();
	gm.getP1().play(0, 0);
	gm.getBoard().displayBoard();

	int size = 5;
	int windowWidth = 800;
	int windowHeight = 800;
	
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Gomoku Game");
	GraphicManager grm(&window, 8, windowWidth, windowHeight);

	
	int xClicked = 999;
	int yClicked = 999;

	// determine player turn
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			grm.MouseClick(xClicked, yClicked, WHITE);
			cout << xClicked;
			cout << "position number: " << "(" << xClicked << "," << yClicked << ")" << endl;
		}
		

		// Check if clicked cell is empty

		// play in the gameManager if the the cell is empty

		// Check if the game is over (throw exception for the moment if it is the case)

		// Change player turn 

		window.clear();
		grm.render();
		window.display();

	}

	return 0;
}
