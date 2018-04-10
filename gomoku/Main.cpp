#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "GraphicManager.h"



using namespace std;


void generateCells(int width, int height, vector<sf::RectangleShape> &cells, int size, const sf::Texture *pTexture)
{
	int y = 0.00625 * height;
	for (int i = 0; i < size; i++)
	{
		int x = 0.00625 * width;
		for (int j = 0; j < size; j++)
		{
			sf::RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(0.1875*width, 0.1875*height));
			rectangle.setPosition(x, y);
			rectangle.setTexture(pTexture);
			cells.push_back(rectangle);
			x += 0.2*width;
		}
		y += 0.2*height;
	}
}


void MouseClick(int &xClicked, int &yClicked, vector<sf::RectangleShape> &cells, sf::RenderWindow &window, const sf::Texture *pTexture)
{
	int width = window.getSize().x;
	int height = window.getSize().y;


	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
	for (size_t i = 0; i < cells.size(); i++)
	{
		if (localPosition.x > cells[i].getPosition().x && localPosition.x < cells[i].getPosition().x + 0.1875*width
			&& localPosition.y > cells[i].getPosition().y && localPosition.y < cells[i].getPosition().y + 0.1875*height)
		{

			cells[i].setTexture(pTexture);

			xClicked = i % (int)(0.00625 * width);
			if (i < (int)(0.00625 * height))
				yClicked = 4;
			else if (i < (int)(0.0125 * height))
				yClicked = 3;
			else if (i < (int)(0.01875 * height))
				yClicked = 2;
			else if (i < (int)(0.025 * height))
				yClicked = 1;
			else if (i < (int)(0.03125 * height))
				yClicked = 0;
		}
	}
	if (xClicked > 4 || yClicked >> 4)
	{
		//throw std::invalid_argument("USER CLICKED BETWEEN CELLS");
	}
}

int main()
{
	GameManager gm(BOARD_SIZE, BOARD_SIZE);
	gm.getBoard().displayBoard();

	gm.getP1().play(0, 0);
	gm.getBoard().displayBoard();

	int size = 5;
	int windowWidth = 1920;
	int windowHeight = 1080;

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

	generateCells(windowWidth, windowHeight, cells, size, pCellTexture);


	// launch a window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!"/*,sf::Style::Fullscreen*/);
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
