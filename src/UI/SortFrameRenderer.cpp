#pragma once

#include <time.h>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../config.cpp"
#include "../RandomArrayGenerator.cpp"



class SortFrameRenderer
{
private:
	sf::RenderWindow& target;
	unsigned numOfElements = 20;
	float singleElementWidth;
	float gap;
	//unsigned sleepTime = .5;
	//std::clock_t clock;

	sf::RectangleShape frame;
	sf::RectangleShape baseLine;

	RandomArrayGenerator randomElementsArr;
	std::array <Element, ARR_SIZE> elements;


	void setSortFrame() {
		frame.setFillColor(mFrameColor);
		frame.setPosition(mFramePos);
		frame.setSize(mFrameSize);

		baseLine.setFillColor(baseLineColor);
		baseLine.setPosition(baseLinePos);
		baseLine.setSize(baseLineSize);

	}


	// Sets elements at the centre of the frame (window) by setting the elements
	// width from 5 to 200 && gap from 2 to 60
	void setElements() {
		const float globalRelativeYPos = baseLine.getPosition().y + baseLine.getLocalBounds().height;
		const float zoomFactor = 1100;
		const float frameWidth = frame.getLocalBounds().width;

		singleElementWidth = zoomFactor / numOfElements;
		gap = 0.2f * singleElementWidth;

		float totalWidthOfElements = numOfElements * (singleElementWidth +gap) - gap;
		float iniXPos = (frameWidth - totalWidthOfElements) / 2;

		for (unsigned i{ 0 }; i < numOfElements; i++) {
			elements[i].setRect(iniXPos + (i * (singleElementWidth + gap) ), globalRelativeYPos, singleElementWidth);
			elements[i].setColor(unsortedElementsColor);
		}

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

		while (leftXPos != rightXPos) {
			leftElem.move(offset, 0);
			rightElem.move(-offset, 0);

			target.clear();
			leftElem.drawOn(target);
			rightElem.drawOn(target);

			leftXPos += offset;
		}

		std::swap(leftElem, rightElem);

		rightElem.setColor(sf::Color::Green);
	}

public:

	SortFrameRenderer(sf::RenderWindow& _window) :
		target{_window}
	{
		elements = randomElementsArr.randomize();

		setSortFrame();
		//setFont();
	}



	// Insertion Algorithm
	// checks for larger element to the left
	void visualizeInsertion() {
		int j;

		for (unsigned i{ 1 }; i < numOfElements; i++) {
			j = i - 1;

			while (j >= 0 &&  (elements[j].getValue() > elements[j+1].getValue() ) ) {
				swapElements(elements[j] , elements[j+1]);
				--j;
			}
		}
	}


	// Shell Sort Algorithm
	void visualizeShellSort() {
		int j;

		for (const unsigned gap : gaps) {
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

				while (j >= gap && (elements[j].getValue() > elements[j - gap].getValue())) {
					swapElements(elements[j], elements[j - gap]);
					j -= gap;
				}
			}
		}
	}


	//void updateRenderedElements() {

	//}


	// Sets number of elements to be rendered
	void setNumOfElements(unsigned& _renderedElements) {
		numOfElements = _renderedElements;
	}


	// Draws SortFrame 
	void drawOn(sf::RenderWindow &window) {
		window.draw(frame);
		window.draw(baseLine);

		setElements();

		for (unsigned i{ 0 }; i < numOfElements; i++) {
			elements[i].drawOn(window);
		}

	}


};