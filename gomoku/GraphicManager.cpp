#include "GraphicManager.h"
#include "GameManager.h"
#include <string>
#include <iostream>


using namespace std;
GraphicManager::GraphicManager(sf::RenderWindow* window, int size, int width, int height)
{
	
	this->window = window;

	this->window->setFramerateLimit(10);
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
	cout << size << endl;
	float y = (0.03125 / size) * height;
	for (int i = 0; i < size; i++)
	{
		float x = (0.03125 / size) * height;
			for (int j = 0; j < size; j++)
			{
				sf::RectangleShape rectangle;
				rectangle.setSize(sf::Vector2f(((float)0.9375/size)*width, ((float)0.9375 / size)*height));
				rectangle.setPosition(x, y);
				rectangle.setTexture(pCellTexture);
				cells.push_back(rectangle);
				x += (((float)1 / size)*height);
			}
			y += (((float)1 / size)*height);
	}
}

void GraphicManager::mouseClick(int &xClicked, int &yClicked, char player)
{
	int width = this->width;
	int height = this->height;
	sf::Vector2i localPosition = sf::Mouse::getPosition(*(this->window));
	for (size_t i = 0; i < cells.size(); i++)
	{
		
		if (localPosition.x > cells[i].getPosition().x && localPosition.x < cells[i].getPosition().x + cells[i].getLocalBounds().width
			&& localPosition.y > cells[i].getPosition().y && localPosition.y < cells[i].getPosition().y + cells[i].getLocalBounds().height
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

			xClicked = i % size;
			yClicked = i / size;
			yClicked = ((size-1) - yClicked);
		}
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

void GraphicManager::popup(std::string title, int width, int height, std::string message)
{
	sf::RenderWindow popupWindow(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close);
	popupWindow.setFramerateLimit(10);

	// Create a text
	sf::Font font;
	font.loadFromFile("micross.ttf");
	sf::Text text(message, font);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setPosition(sf::Vector2f(0.5*width - 0.5*text.getLocalBounds().width, 0.5*height - (0.5*text.getLocalBounds().height)));


	// run the program as long as the window is open
	while (popupWindow.isOpen())
	{
		sf::Event event;
		while (popupWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				popupWindow.close();
			}
		}
		popupWindow.clear(sf::Color(255, 255, 255));
		popupWindow.draw(text);
		popupWindow.display();
	}

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




