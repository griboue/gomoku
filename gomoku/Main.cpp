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

	int size = BOARD_SIZE;
	int windowWidth = 800;
	int windowHeight = 800;
	
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Gomoku Game", sf::Style::Titlebar | sf::Style::Close);

	GraphicManager grm(&window, size, windowWidth, windowHeight);

	
	int xClicked = 999;
	int yClicked = 999;
	int loopNumber = 0;

	string currentWindow = "menu";
	grm.generateCells();
	grm.generateMenu();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (currentWindow == "menu") // MENU
			{
				if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed)
				{
					grm.menuClick(xClicked, yClicked, currentWindow);
				}
			}
			else if (currentWindow == "game") // GAME
			{
				if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed)
				{
					
					grm.mouseClick(xClicked, yClicked, turn->getSymbol());
					if (xClicked >= gm->getBoard().getWidth() || xClicked < 0
						|| yClicked >= gm->getBoard().getHeight() || yClicked < 0) {
						continue;	// if the player clicks out of the board, redo the loop
					}

					// Check if clicked cell is empty
					if (!gm->getBoard().isEmpty(xClicked, yClicked)) {
						continue;	// if that happens then redo the loop
					}

					// play in the gameManager if the the cell is empty
					turn->play(xClicked, yClicked);

					// Check if the game is over (throw exception for the moment if it is the case)
					if (gm->isDraw()) {
						cout << "Draw." << endl;
					}
					else if (gm->isFinish()) {
						switch (gm->checkWinner()) {
							case 1:
								cout << "Black stone wins" << endl;
								break;
							case 0:
								cout << "White stone wins" << endl;
								break;
							default:
								cout << "Error." << endl;
								break;
						}
					}
					else {	// Else change player turn	
						turn = turn == gm->getP1() ? gm->getP2() : gm->getP1();
					}
				}
			}
		}
		// Clear and display the window
		window.clear();
		currentWindow == "game" ? grm.renderGame() : grm.renderMenu();
		window.display();
	}

	return 0;
}
