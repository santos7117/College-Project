#pragma once

#ifndef _SORT_APP_HPP
#define _SORT_APP_HPP

#include "UI/PauseIndicator.hpp"
#include "UI/Button.hpp"
#include "Element.hpp"
#include "ElementsGenerator.hpp"



class Application 
{

public:

	// Constructor
	Application(sf::RenderWindow&);


	void update();

	// Draws all App Components on window
	void render();

private:
	sf::Event event;
	sf::RenderWindow& targetWindow;

	// Navigation Bar 
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

	// Sort Frame
	sf::RectangleShape sortFrame;
	short unsigned numOfElements;
	short unsigned numOfSwaps;
	short unsigned numOfComparisions;
	float animationSpeed;
	sf::Text elementsSizeIndicator;
	sf::Text animationSpeedIndicator;
	sf::Text swapIndicator;
	sf::Text comparisionIndicator;

	ElementsArray& elements;
	ElementsGenerator elementsGenerator;
	float singleElementWidth;
	//

	sf::Clock deltaClock;
	sf::Int64 dt;


	// Sets up Sort Frame along with Sort Details
	void setSortFrame();

	// Aligns elements at the centre of the frame (window) by setting the elements
	void alignElements();

	// Randomizes the rendered ElementsArray with the help of ElementsGenerator
	void randomize(const short unsigned& _numOfElements);


	// Swaps elements with animation while sorting
	void swapElements(Element& leftElem, Element& rightElem, bool);

	
	// Visualizes Selection Sort Algorithm
	void visualizeSelection(ElementsArray&);

	// Visualizes Insertion Sort Algorithm
	void visualizeInsertion(ElementsArray&);

	// Visualizes Shell Sort Algorithm
	void visualizeShellSort(ElementsArray&);

	void visualizeBubbleSort(ElementsArray&);

	// Sets color of sorted elements
	void setSortedColor();


	// Increments number of elements to be rendered
	void inrElements();

	// Decrements number of elements to be rendered
	void dcrElements();

	// Resets numOfSwaps and numOfComparisions
	void resetSortDetails();

	// Updates numOfSwaps and numOfComparisions while visualizing Sort
	void updateSortDetails();


	// Sets up Navigation Bar 
	void setNavBars();

	// Handles clicks and hover events
	void updateMouseEvents();

	// Handles pause state
	void handlePause();

	// Handles all inputs
	void updateEvents();

	// Draws Navigation Bar
	void drawNavBar();

	// Draws Sort Details
	void drawSortDetails();

	// Draws Elements 
	void drawElements();

	// Renders Navigation Bars, Sort Details and Elements
	void renderEverything();

};

#endif