#include "GraphicManager.h"
#include "GameManager.h"
#include <string>
#include <iostream>


using namespace std;
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
	if (!textureStart.loadFromFile("startButton.png"))
	{
		std::cout << "error loading the sprite";
	}
	if (!textureLogo.loadFromFile("gomoku_logo.png"))
	{
		std::cout << "error loading the sprite";
	}
	if (!textureBackground.loadFromFile("gomoku_dark_background.jpg"))
	{
		std::cout << "error loading the sprite";
	}
	pCellTexture = &textureCell;
	pCrossedCellTexture = &textureCrossedCell;
	pRoundedCellTexture = &textureRoundedCell;
	pStartTexture = &textureStart;
	pLogoTexture = &textureLogo;
	pBackgroundTexture = &textureBackground;
}

sf::RenderWindow * GraphicManager::getWindow()
{
	return window;
}

void GraphicManager::generateCells()
{
		int y = (0.00625) * height;
		for (int i = 0; i < size; i++)
		{
			int x =  0.00625 * width;
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

void GraphicManager::mouseClick(int &xClicked, int &yClicked, char player)
{
	int width = this->width;
	int height = this->height;
	sf::Vector2i localPosition = sf::Mouse::getPosition(*(this->window));
	for (size_t i = 0; i < cells.size(); i++)
	{
		
		if (localPosition.x > cells[i].getPosition().x && localPosition.x < cells[i].getPosition().x + 0.1875*width
			&& localPosition.y > cells[i].getPosition().y && localPosition.y < cells[i].getPosition().y + 0.1875*height
			&& !(std::find(alreadyCliked.begin(), alreadyCliked.end(), i) != alreadyCliked.end()))
		{
			if (player == WHITE)
			{
				cells[i].setTexture(pRoundedCellTexture);
			}
			else if (player == BLACK)
			{
				cells[i].setTexture(pCrossedCellTexture);
			}
			this->alreadyCliked.push_back(i);

	
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


void GraphicManager::menuClick(int &xClicked, int &yClicked, std::string &currentWindow)
{
	int width = this->width;
	int height = this->height;

	sf::Vector2i localPosition = sf::Mouse::getPosition(*(this->window));
	
	if (localPosition.x > startButton.getPosition().x && localPosition.x < startButton.getPosition().x + startButton.getLocalBounds().width
			&& localPosition.y > startButton.getPosition().y && localPosition.y < startButton.getPosition().y + startButton.getLocalBounds().height)
	{
		currentWindow = "game";
	}

}

void GraphicManager::generateMenu()
{
	int width = this->width;
	int height = this->height;

	int y = (0.5) * height;
	int x = (0.5) * width;

	sf::RectangleShape start;
	start.setSize(sf::Vector2f(125, 50));
	start.setPosition((x - 62), y - 25);
	start.setTexture(pStartTexture);
	startButton = start;


	sf::RectangleShape logo;
	logo.setSize(sf::Vector2f(500, 200));
	logo.setPosition((x - 250), y - (0.3*height));
	logo.setTexture(pLogoTexture);
	gameLogo = logo;

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	background.setPosition(0, 0);
	background.setTexture(pBackgroundTexture);
	this->background = background;
}

void GraphicManager::renderGame()
{
	
	generateMenu();
	window->draw(background);
	for (sf::RectangleShape r : cells) {
		window->draw(r);
	}
	
}


void GraphicManager::renderMenu()
{

	window->draw(background);
	window->draw(startButton);
	window->draw(gameLogo);
}




