#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "GraphicManager.h"

using namespace std;

int main()
{
	GameManager *gm = new GameManager(BOARD_SIZE, BOARD_SIZE);
	Player *turn;	
	turn = gm->getP1();


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
	bool gameEnded = false;
	while (window.isOpen())
	{
		if (gameEnded)
		{
			switch (gm->checkWinner()) {
			case 1:
				cout << "Black stone wins" << endl;
				grm.popup("Game terminated", 400, 300, "Black stone wins");
				currentWindow = "menu";
				break;
			case 0:
				cout << "White stone wins" << endl;
				grm.popup("Game terminated", 400, 300, "White stone wins");
				currentWindow = "menu";
				break;
			default:
				cout << "Error." << endl;
				break;
			}
			gameEnded = false;
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
				
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

					/*if (!turn->getRetract()) {	// check for retraction
						cout << "Do you want to retract your action ?(y/n)" << endl;
						char reponse;
						cin >> reponse;
						if (reponse == 'y')
							turn->doRetract();
					}*/

					// Check if the game is over (throw exception for the moment if it is the case)
					if (gm->isDraw()) {
						cout << "Draw." << endl;
					}
					else if (gm->isFinish()) {
						gameEnded = true;
					}
					else {
						// Change player turn
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
