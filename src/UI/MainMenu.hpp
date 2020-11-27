#pragma once 

#ifndef _MAIN_MENU_CPP
#define _MAIN_MENU_CPP


#include "../config.hpp"


class MainMenu 
{
private:
	sf::Event mainMenuEvent;
	sf::RenderWindow& targetWindow;
	sf::Sprite background;

	sf::Text appTitleText;
	sf::Text sortOptionText;
	sf::Text treeOptionText;
	sf::Text exitOptionText;


public:
	MainMenu(sf::RenderWindow& _window);


	void setUp();

	void updateMouseEvents();

	void updateEvents();

	void render();
};







#endif