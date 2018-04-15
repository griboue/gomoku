#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <algorithm>

class GraphicManager
{
private:
	std::vector<sf::RectangleShape> cells;
	std::vector<int> alreadyCliked;
	sf::RenderWindow* window;
	int width;
	int height;
	int size;

	sf::RectangleShape startButton;
	sf::RectangleShape gameLogo;
	sf::RectangleShape background;

	sf::Texture textureCell;
	const sf::Texture *pCellTexture;

	sf::Texture textureCrossedCell;
	const sf::Texture *pCrossedCellTexture;

	sf::Texture textureRoundedCell;
	const sf::Texture *pRoundedCellTexture;

	sf::Texture textureStart;
	const sf::Texture *pStartTexture;

	sf::Texture textureLogo;
	const sf::Texture *pLogoTexture;

	sf::Texture textureBackground;
	const sf::Texture *pBackgroundTexture;


public:
	GraphicManager(sf::RenderWindow* window, int size, int width, int height);
	sf::RenderWindow* getWindow();
	void generateCells();
	void mouseClick(int &width, int &height, char player);
	void menuClick(int &width, int &height, std::string &currentwindow);
	void renderGame();
	void renderMenu();
	void generateMenu();
	void popup(std::string title, int width, int height, std::string message);
	void clearBoard();
};


