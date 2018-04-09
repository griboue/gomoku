#include <SFML/Graphics.hpp>
#include "GameManager.h"


using namespace std;


void generateCells(vector<sf::RectangleShape> &cells, int size, const sf::Texture *pTexture)
{
	int y = 5;
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
		y += 160;
	}
}


void MouseClick(int &xClicked, int &yClicked, vector<sf::RectangleShape> &cells, sf::RenderWindow &window, const sf::Texture *pTexture)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
	for (size_t i = 0; i < cells.size(); i++)
	{
		if (localPosition.x > cells[i].getPosition().x && localPosition.x < cells[i].getPosition().x + 150
			&& localPosition.y > cells[i].getPosition().y && localPosition.y < cells[i].getPosition().y + 150)
		{

			cells[i].setTexture(pTexture);

			xClicked = i % 5;
			if (i < 5)
				yClicked = 4;
			else if (i < 10)
				yClicked = 3;
			else if (i < 15)
				yClicked = 2;
			else if (i < 20)
				yClicked = 1;
			else if (i < 25)
				yClicked = 0;
		}
	}
	if (xClicked > 4 || yClicked >> 4)
	{
		throw std::invalid_argument("USER CLICKED BETWEEN CELLS");
	}
}

int main()
{
	int size = 5;
	int windowWidth = 800;
	int windowHeight = 800;

	vector<sf::RectangleShape> cells;

	sf::Texture textureCell;
	sf::Texture textureCrossedCell;
	if (!textureCell.loadFromFile("cellSprite.jpg"))
	{
		cout << "error loading the sprite";
	}
	if (!textureCrossedCell.loadFromFile("crossedCellSprite.jpg"))
	{
		cout << "error loading the sprite";
	}
	const sf::Texture *pCellTexture = &textureCell;
	const sf::Texture *pCrossedCellTexture = &textureCrossedCell;

	generateCells(cells, size, pCellTexture);


	// launch a window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!"/*, sf::Style::Fullscreen*/);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		int xClicked = 999;
		int yClicked = 999;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			MouseClick(xClicked, yClicked, cells, window, pCrossedCellTexture);
			cout << "position number: " << "(" << xClicked << "," << yClicked << ")" << endl;
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
