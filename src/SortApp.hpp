#pragma once

#ifndef _SORT_APP_HPP
#define _SORT_APP_HPP

//#include "UI/SortFrame.hpp"
#include "UI/PauseIndicator.hpp"
#include "UI/Button.hpp"
#include "Element.hpp"
#include "RandomArrayGenerator.hpp"



class SortApp {
private:
	sf::Event event;
	sf::RenderWindow& targetWindow;

	// To be replaced by navigation bar class
	sf::RectangleShape topNavBar;
	Button backBtn;
	Button insertionSortBtn;
	Button shellSortBtn;
	Button plusBtn;
	Button minusBtn;
	Button genNewArrBtn;
	sf::RectangleShape btmNavBar;
	PauseIndicator pauseIndicator;
	//

	// Added from SortFrame
	sf::RectangleShape sortFrame;
	unsigned numOfElements;

	std::array <Element, ARR_SIZE>& elements;
	RandomArrayGenerator randomElementsArr;
	float singleElementWidth;
	//

	sf::Clock deltaClock;
	sf::Int64 dt;
	double animationSpeed;

	void setSortFrame();

	// Sets elements at the centre of the frame (window) by setting the elements
	// width from 5 to 200 && gap from 2 to 60
	void alignElements();

	void randomize();

	// Insertion Algorithm
	// checks for larger element to the left
	void visualizeInsertion();


	// Shell Sort Algorithm
	void visualizeShellSort();



	// Sets number of elements to be rendered
	void inrElements();

	void dcrElements();

	void updateMovement(Element&, Element&);

	// Swaps elements with animation while sorting
	void swapElements(Element& leftElem, Element& rightElem, bool);


	// Navigation Bar class
	void setNavBars();

	void renderNavBar();

	void updateMouseEvents();
	//


	// Handles pause state
	void handlePause();

	void updateEvents();

	void renderElements();


public:

	// Constructor
	SortApp(sf::RenderWindow&);


	void update();

	// Draws all App Components on window
	void render();


};

#endif