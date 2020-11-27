#pragma once 

#ifndef _MAIN_MENU_CPP
#define _MAIN_MENU_CPP


#include "../config.hpp"
#include "Button.hpp"


class MainMenu 
{
private:
	sf::Event mainMenuEvent;
	sf::RenderWindow& targetWindow;
	sf::Sprite background;

	sf::Text appTitleText;
	Button sortOptionText;
	Button treeOptionText;
	Button exitOptionText;

	void setUp();

public:
	MainMenu(sf::RenderWindow&);


	void updateMouseEvents();

	void updateEvents();

	void render();
};


#endif