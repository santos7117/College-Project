#pragma once

#ifndef _SORT_FRAME_HPP
#define _SORT_FRAME_HPP

#include "../Element.hpp"
#include "../RandomArrayGenerator.hpp"
#include "../ElementAnimator.cpp"



class SortFrame
{
private:
	sf::RenderWindow& target;

	sf::RectangleShape frame;
	unsigned numOfElements;
	float singleElementWidth;

	RandomArrayGenerator randomElementsArr;
	std::array <Element, ARR_SIZE>& elements;

	ElementAnimator animator;


	//unsigned sleepTime = .5;
	//std::clock_t clock;

	//void sleep(unsigned ms) {
	//	clock = std::clock() + ms * CLOCKS_PER_SEC / 1000;
	//	while (std::clock() < clock)
	//	{

	//	}
	//}

	void setSortFrame();

	void updateMovement(Element&, Element&);

	// Swaps elements with animation while sorting
	void swapElements(Element& leftElem, Element& rightElem);

public:

	SortFrame(sf::RenderWindow& _window);

	// Sets elements at the centre of the frame (window) by setting the elements
	// width from 5 to 200 && gap from 2 to 60
	void setElements();

	void randomize();

	// Insertion Algorithm
	// checks for larger element to the left
	void visualizeInsertion();


	// Shell Sort Algorithm
	void visualizeShellSort();



	// Sets number of elements to be rendered
	void inrElements();

	void dcrElements();

	void update(const float &dt);

	// Draws SortFrame 
	void render();


};

#endif