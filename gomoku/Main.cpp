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
	string windowTitle = "Hello world";

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), windowTitle);
	GraphicManager grm(&window, 5, windowWidth, windowHeight);

	
	int xClicked = 999;
	int yClicked = 999;
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
			grm.MouseClick(xClicked, yClicked);
			cout << "position number: " << "(" << xClicked << "," << yClicked << ")" << endl;
		}

		window.clear();
		grm.render();
		window.display();
	}

	return 0;
}
