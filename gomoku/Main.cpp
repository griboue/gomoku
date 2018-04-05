#include <SFML/Graphics.hpp>
#include "GameManager.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!"/*, sf::Style::Fullscreen*/);

	GameManager gm(5, 5);
	gm.getBoard().displayBoard();

	gm.getP1().play(0, 0);
	gm.getBoard().displayBoard();
	gm.getP2().play(4, 0);
	gm.getBoard().displayBoard();
	gm.getP1().play(4, 4);
	gm.getBoard().displayBoard();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}

	return 0;
}
