#include "GraphicManager.h"
#include <string>
#include <iostream>

GraphicManager::GraphicManager(std::string name, int size, int width, int height, bool fs)
{
	if (fs) 
	{

		this->window = &sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Fullscreen);
	}
	else 
	{
		this->window = &sf::RenderWindow(sf::VideoMode(width, height), name);
	}

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

	pCellTexture = &textureCell;
	pCrossedCellTexture = &textureCrossedCell;
	
}

sf::RenderWindow * GraphicManager::getWindow()
{
	return window;
}

void GraphicManager::generateCells()
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
				rectangle.setTexture(pCellTexture);
				cells.push_back(rectangle);
				x += 0.2*width;
			}
			y += 0.2*height;
		}
}

void GraphicManager::MouseClick(int &xClicked, int &yClicked)
{
	int width = window->getSize().x;
	int height = window->getSize().y;


	// incorrect (must pass window through getPosition function
	sf::Vector2i localPosition = sf::Mouse::getPosition();

	for (size_t i = 0; i < cells.size(); i++)
	{
		if (localPosition.x > cells[i].getPosition().x && localPosition.x < cells[i].getPosition().x + 0.1875*width
			&& localPosition.y > cells[i].getPosition().y && localPosition.y < cells[i].getPosition().y + 0.1875*height)
		{

			cells[i].setTexture(pCellTexture);

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
		throw std::invalid_argument("USER CLICKED BETWEEN CELLS");
	}
}




