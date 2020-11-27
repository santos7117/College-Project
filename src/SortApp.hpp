#pragma once

#ifndef _SORT_APP_HPP
#define _SORT_APP_HPP

#include "UI/SortFrame.hpp"
#include "UI/PauseIndicator.hpp"
#include "UI/Button.hpp"



class SortApp {
private:
	sf::Event event;
	sf::RenderWindow& targetWindow;

	sf::Color theme;

	sf::RectangleShape topNavBar;
	Button backBtn;
	Button insertionSortBtn;
	Button shellSortBtn;
	Button plusBtn;
	Button minusBtn;
	Button genNewArrBtn;
	SortFrame sortFrame;
	sf::RectangleShape btmNavBar;

	PauseIndicator pauseIndicator;
	unsigned animationTime;


	void setNavBars();

	void renderNavBar();

	void updateMouseEvents();

	void updateEvents();


public:

	// Constructor
	SortApp(sf::RenderWindow&);


	// Handles pause state
	void handlePause();

	void update();

	// Draws all App Components on window
	void render();


};

#endif