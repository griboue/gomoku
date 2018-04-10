#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>



class GraphicManager
{
private:
	std::vector<sf::RectangleShape> cells;
	sf::RenderWindow* window;
	int width;
	int height;
	int size;

	sf::Texture textureCell;
	const sf::Texture *pCellTexture;

	sf::Texture textureCrossedCell;
	const sf::Texture *pCrossedCellTexture;

	sf::Texture textureRoundedCell;
	const sf::Texture *pRoundedCellTexture;


public:
	GraphicManager(sf::RenderWindow* window, int size, int width, int height);
	sf::RenderWindow* getWindow();
	void generateCells();
	void MouseClick(int &width, int &height, char player);
	void render();

};


