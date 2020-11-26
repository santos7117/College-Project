//#include "../stdafx.hpp"
#pragma once


#include "../config.cpp"
#include "../RandomArrayGenerator.cpp"



class SortFrame
{
private:
	sf::RenderWindow& target;
	//unsigned sleepTime = .5;
	//std::clock_t clock;

	sf::RectangleShape baseLine;
	sf::RectangleShape frame;
	unsigned numOfElements;

	RandomArrayGenerator randomElementsArr;
	std::array <Element, ARR_SIZE> elements;

	float singleElementWidth;
	float gap;

	void setSortFrame() {
		frame.setFillColor(themeColor);
		frame.setPosition(framePos);
		frame.setOutlineColor(frameBorderColor);
		frame.setOutlineThickness(1.f);


	}


	//void sleep(unsigned ms) {
	//	clock = std::clock() + ms * CLOCKS_PER_SEC / 1000;
	//	while (std::clock() < clock)
	//	{

	//	}
	//}





	// Swaps elements with animation while sorting
	void swapElements(Element& leftElem, Element& rightElem) {
		float leftXPos = leftElem.getXPos();
		float rightXPos = rightElem.getXPos();
		float offset = singleElementWidth + gap;

		leftElem.setColor(sf::Color::Yellow);
		rightElem.setColor(sf::Color::Red);

		//while (leftXPos <= rightXPos) {
		//	leftElem.move(10, 0);
		//	rightElem.move(-10, 0);

		//	leftElem.drawOn(target);
		//	rightElem.drawOn(target);
		//	target.clear();

		//	leftXPos += offset;
		//}

		std::swap(leftElem, rightElem);

		rightElem.setColor(sf::Color::Green);
	}

public:

	SortFrame(sf::RenderWindow& _window) :
		target{_window},
		frame{frameSize},
		numOfElements{20}
	{
		elements = randomElementsArr.randomize();
		setSortFrame();
	}


	// Sets elements at the centre of the frame (window) by setting the elements
	// width from 5 to 200 && gap from 2 to 60
	void setElements() {
		float zoomFactor = 1100;
		float frameWidth = frame.getLocalBounds().width;

		singleElementWidth = zoomFactor / numOfElements;
		gap = 0.2f * singleElementWidth;

		float totalWidthOfElements = numOfElements * (singleElementWidth + gap) - gap;
		float iniXPos = (frameWidth - totalWidthOfElements) / 2;

		for (unsigned i{ 0 }; i < numOfElements; i++) {
			elements[i].setRect(iniXPos + (i * (singleElementWidth + gap)), framePos.y, singleElementWidth);
			elements[i].setColor(unsortedElementsColor);
		}

	}


	// Insertion Algorithm
	// checks for larger element to the left
	void visualizeInsertion() {
		int j;

		for (unsigned i{ 1 }; i < numOfElements; i++) {
			j = i - 1;

			while (j >= 0 &&  ( elements[j].getValue() > elements[j+1].getValue() ) ) {
				swapElements(elements[j] , elements[j+1]);
				--j;
			}
		}
	}


	// Shell Sort Algorithm
	void visualizeShellSort() {
		int j;

		for (const unsigned gap : SHELL_GAPS) {
			//# Do a gapped insertion sort for this gap size.
			//# The first gap elements a[0..gap - 1] are already in gapped order keep adding one more element until the entire array is gap sorted

			for (unsigned i = gap; i < numOfElements; ++i)
			{
				//# add a[i] to the elements that have been gap sorted
				//# save a[i] in current to make a hole at position i

				//curr = a[i]

				//# shift earlier gap - sorted elements up until the correct location for a[i] is found

				//for (j = i; j >= gap and a[j - gap] > curr; j -= gap)
				//	a[j] = a[j - gap]

				//# put temp(the original a[i]) in its correct location

				//a[j] = curr

				j = i;

				//while (j >= gap && (elements[j].getValue() >= elements[j - gap].getValue())) {
				//	swapElements(elements[j], elements[j - gap]);
				//	j -= gap;
				//}
			}
		}
	}



	// Sets number of elements to be rendered
	void setNumOfElements(unsigned& _renderedElements) {
		numOfElements = _renderedElements;
	}


	// Draws SortFrame 
	void render() {

		target.draw(frame);
		target.draw(baseLine);

		for (unsigned i{ 0 }; i < numOfElements; i++) {
			elements[i].drawOn(target);
		}

	}


};