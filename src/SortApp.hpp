#pragma once

#ifndef _SORT_APP_HPP
#define _SORT_APP_HPP

#include "UI/PauseIndicator.hpp"
#include "UI/Button.hpp"
#include "Element.hpp"
#include "RandomArrayGenerator.hpp"



class Application {
private:
	sf::Event event;
	sf::RenderWindow& targetWindow;

	// To be replaced by navigation bar class
	sf::RectangleShape topNavBar;
	Button backBtn;
	Button selectionSortBtn;
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
	short unsigned numOfElements;
	short unsigned numOfSwaps;
	short unsigned numOfComparisions;
	float animationSpeed;
	sf::Text elementsSizeIndicator;
	sf::Text swapIndicator;
	sf::Text comparisionIndicator;
	sf::Text animationSpeedIndicator;

	std::vector <Element/*, ARR_SIZE*/>& elements;
	RandomArrayGenerator randomElementsArr;
	float singleElementWidth;
	//

	sf::Clock deltaClock;
	sf::Int64 dt;

	void setSortFrame();

	// Sets elements at the centre of the frame (window) by setting the elements
	// width from 5 to 200 && gap from 2 to 60
	void alignElements();

	void randomize(const short unsigned& _numOfElements);


	// Swaps elements with animation while sorting
	void swapElements(Element& leftElem, Element& rightElem, bool);


	// Insertion Algorithm
	// checks for larger element to the left
	void visualizeInsertion();

	// Shell Sort Algorithm
	void visualizeShellSort();

	void visualizeBubbleSort();

	void visualizeSelection();


	void setSortedColor();


	// Sets number of elements to be rendered
	void inrElements();

	void dcrElements();

	void resetSortDetails();

	void updateSortDetails();

	void updateMovement(Element&, Element&);


	// Navigation Bar class
	void setNavBars();

	void updateMouseEvents();

	// Handles pause state
	void handlePause();

	void updateEvents();

	void drawNavBar();

	void drawSortDetails();

	void drawElements();

	void renderEverything();


public:

	// Constructor
	Application(sf::RenderWindow&);


	void update();

	// Draws all App Components on window
	void render();


};

#endif