#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "GraphicManager.h"

using namespace std;

int main()
{
	GameManager *gm = new GameManager(BOARD_SIZE, BOARD_SIZE);
	Player *turn;	// pointer for giving the turn alternatively to the players
	turn = gm->getP1();
	//gm.getBoard().displayBoard();
	//gm.getP1().play(0, 0);
	//gm.getBoard().displayBoard();

	int size = 5;
	int windowWidth = 800;
	int windowHeight = 800;
	
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Gomoku Game");
	GraphicManager grm(&window, 5, windowWidth, windowHeight);

	
	int xClicked = 999;
	int yClicked = 999;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// If the user close the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			// If the user left click
			if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed)
			{
				grm.MouseClick(xClicked, yClicked, turn->getSymbol());
				if (xClicked >= gm->getBoard().getWidth() || xClicked < 0
					|| yClicked >= gm->getBoard().getHeight() || yClicked < 0) {
					continue;	// if the player clicks out of the board, redo the loop
				}

				// Check if clicked cell is empty
				if (gm->getBoard().isEmpty(xClicked, yClicked)) {

					// play in the gameManager if the the cell is empty
					turn->play(xClicked, yClicked);

					// Check if the game is over (throw exception for the moment if it is the case)
					if (gm->isFinish()) {
						if (gm->checkWinner() == 1) {
							cout << "Black stone wins" << endl;
						}
						else if (gm->checkWinner() == 0) {
							cout << "White stone wins" << endl;
						}
						else cout << "Error, there's maybe a draw." << endl;
					}

					else {	// Else change player turn	
						turn = turn == gm->getP1() ? gm->getP2() : gm->getP1();
						//cout << (turn == gm->getP1()) << endl;
						//cout << (turn == gm->getP2()) << endl;
					}
				}
				else {
					continue;	// else redo the loop
				}
			}
				
		}

		// Clear and display the window
		window.clear();
		grm.render();
		window.display();
	}

	return 0;
}
