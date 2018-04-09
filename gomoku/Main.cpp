#include <SFML/Graphics.hpp>
#include "GameManager.h"


using namespace std;
int main()
{
	int size = 5;
	GameManager gm(size, size);
	gm.getBoard().displayBoard();

	gm.getP1().play(0, 0);
	gm.getBoard().displayBoard();
	gm.getP1().play(1, 1);
	gm.getBoard().displayBoard();
	gm.getP1().play(2, 2);
	gm.getBoard().displayBoard();
	gm.getP1().play(3, 3);
	gm.getBoard().displayBoard();
	if (gm.isOver() == 'X') {
		cout << "game finish";
	}
	gm.getP1().play(4, 4);
	gm.getBoard().displayBoard();
	if (gm.isOver() == 'X') {
		cout << "game finish";
	}



	
	// launch a window
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!"/*, sf::Style::Fullscreen*/);

	vector<sf::RectangleShape> cells;
	int y = 5;
	cout << endl << endl;
	sf::Texture texture;
	if (!texture.loadFromFile("cellSprite.jpg"))
	{
		cout << "erro loading the sprite";
	}

	const sf::Texture *pTexture = &texture;

	for (int i = 0; i < size; i++)
	{
		int x = 5;
		for (int j = 0; j < size; j++)
		{
			sf::RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(150, 150));
			rectangle.setPosition(x, y);
			rectangle.setTexture(pTexture);
			cells.push_back(rectangle);
			x += 160;
		}
		y += 160
			;
	}

	cout << cells.size();
	
	for (sf::RectangleShape r : cells) {
		cout << r.getPosition().x;
		cout << r.getPosition().y;

		cout << "----" << endl;
	}



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		for (sf::RectangleShape r : cells) {
			window.draw(r);
		}


		window.display();
	} 
	

	system("pause");
	return 0;
}
