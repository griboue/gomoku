#include <SFML/Graphics.hpp>
#include "GameManager.h"


using namespace std;
int main()
{

	GameManager gm(5, 5);
	gm.getBoard().displayBoard();

	gm.getP1().play(0, 0);
	gm.getBoard().displayBoard();
	gm.getP2().play(4, 0);
	gm.getBoard().displayBoard();
	gm.getP1().play(4, 4);
	gm.getBoard().displayBoard();



	
	// launch a window
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!"/*, sf::Style::Fullscreen*/);
	sf::Texture texture;

	if (!texture.loadFromFile("beer.jpg"))
	{
		cout << "erro loading the sprite";
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(sprite);
		window.display();
	} 
	

	system("pause");
	return 0;
}
