#include "GraphicManager.h"
#include <string>
#include <iostream>

GraphicManager::GraphicManager(sf::RenderWindow* window, int size, int width, int height)
{
	
	this->window = window;

	this->window->setFramerateLimit(60);
	this->width = width;
	this->height = height;
	this->size = size;

	if (!textureCell.loadFromFile("cellSprite.jpg"))
	{
		std::cout << "error loading the sprite";
	}
	if (!textureCrossedCell.loadFromFile("crossedCellSprite.jpg"))
	{
		std::cout << "error loading the sprite";
	}
	if (!textureRoundedCell.loadFromFile("roundedCellSprite.jpg"))
	{
		std::cout << "error loading the sprite";
	}
	pCellTexture = &textureCell;
	pCrossedCellTexture = &textureCrossedCell;
	pRoundedCellTexture = &textureRoundedCell;
	generateCells();
	
}

sf::RenderWindow * GraphicManager::getWindow()
{
	return window;
}

void GraphicManager::generateCells()
{
		int y = (int) 0.00625 * height;
		for (int i = 0; i < size; i++)
		{
			int x = (int) 0.00625 * width;
			for (int j = 0; j < size; j++)
			{
				sf::RectangleShape rectangle;
				rectangle.setSize(sf::Vector2f(0.1875*width, 0.1875*height));
				rectangle.setPosition(x, y);
				rectangle.setTexture(pCellTexture);
				cells.push_back(rectangle);
				x += 0.2*width;
			}
			y += 0.2*height;
		}
}

void GraphicManager::MouseClick(int &xClicked, int &yClicked, char player)
{
	int width = this->width;
	int height = this->height;


	// incorrect (must pass window through getPosition function
	sf::Vector2i localPosition = sf::Mouse::getPosition(*(this->window));
	for (size_t i = 0; i < cells.size(); i++)
	{
		if (localPosition.x > cells[i].getPosition().x && localPosition.x < cells[i].getPosition().x + 0.1875*width
			&& localPosition.y > cells[i].getPosition().y && localPosition.y < cells[i].getPosition().y + 0.1875*height)
		{
			if (player == 'O')
			{
				cells[i].setTexture(pRoundedCellTexture);
			}
			else if (player == 'X')
			{
				cells[i].setTexture(pCrossedCellTexture);
			}

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
	}
}

void GraphicManager::render()
{
	for (sf::RectangleShape r : cells) {
		window->draw(r);
	}
}




