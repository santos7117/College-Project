#pragma once

#ifndef _SORT_APP_CPP
#define _SORT_APP_CPP

#include "UI/SortFrame.hpp"
#include "UI/PauseIndicator.hpp"



class SortApp {
private:
	sf::Event event;
	sf::RenderWindow& targetWindow;

	sf::Color theme;

	sf::RectangleShape topNavBar;
	sf::Text backBtnText;
	sf::Text insertionSortBtnText;
	sf::Text shellSortBtnText;
	sf::Text plusBtn;
	sf::Text minusBtn;
	sf::Text genNewArrBtnText;
	SortFrame sortFrame;
	sf::RectangleShape btmNavBar;

	PauseIndicator pauseIndicator;
	unsigned animationTime;



public:

	// Constructor
	SortApp(sf::RenderWindow& _window);


	void setNavBars();

	// Handles pause state
	void handlePause();


	void updateEvents();


	void update();



	void renderNavBar();

	// Draws all App Components on window
	void render();


};

#endif