#pragma once

#include <time.h>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../RandomArrayGenerator.cpp"



class SortFrameRenderer
{
private:
	unsigned numOfElements = 10;
	unsigned sleepTime = .5;
	float singleElementWidth;
	float gap;
	std::clock_t clock;


	const sf::Vector2f mFramePos = sf::Vector2f(0, 150);
	const sf::Vector2f mFrameSize = sf::Vector2f(1600, 600);
	const sf::Vector2f baseLinePos = sf::Vector2f(mFramePos.x, mFramePos.y);
	const sf::Vector2f baseLineSize = sf::Vector2f(mFrameSize.x, 5);


	sf::RectangleShape frame;
	sf::RectangleShape baseLine;

	RandomArrayGenerator randomElementsArr;
	std::array <Element, ARR_SIZE> elements;


	void setSortFrame() {
		frame.setFillColor(sf::Color::Magenta);
		frame.setPosition(mFramePos);
		frame.setSize(mFrameSize);

		baseLine.setFillColor(sf::Color::Yellow);
		baseLine.setPosition(baseLinePos);
		baseLine.setSize(baseLineSize);

	}


	// width from 5 to 200 && gap from 2 to 60
	void setElements() {
		const float globalRelativeYPos = baseLine.getPosition().y + baseLine.getLocalBounds().height;
		const float zoomFactor = 1100;

		singleElementWidth = zoomFactor / numOfElements;
		gap = 0.2f * singleElementWidth;

		float totalWidthOfElements = numOfElements * (singleElementWidth +gap) - gap;
		float iniXPos = (1600 - totalWidthOfElements) / 2;

		for (unsigned i{ 0 }; i < numOfElements; i++) {
			elements[i].setRect(iniXPos + (i * (singleElementWidth + gap) ), globalRelativeYPos, singleElementWidth);
		}

	}

	void sleep(unsigned ms) {
		clock = std::clock() + ms * CLOCKS_PER_SEC / 1000;
		while (std::clock() < clock)
		{

		}
	}


	//while (leftXPos != rightXPos) {
	//	leftElem.move(offset, 0);
	//	rightElem.move(-offset, 0);

	//	leftXPos += offset;
	//}
	void swapElements(Element& leftElem, Element& rightElem) {
		float leftXPos = leftElem.getXPos();
		float rightXPos = rightElem.getXPos();
		float offset = singleElementWidth + gap;

		leftElem.setColor(sf::Color::Yellow);	sleep(500);
		rightElem.setColor(sf::Color::Red);		sleep(500);

		std::swap(leftElem, rightElem);

		rightElem.setColor(sf::Color::Green);
	}

public:

	SortFrameRenderer()
	{
		elements = randomElementsArr.randomize();

		setSortFrame();
		//setFont();
	}



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

	void visualizeShellSort() {

	}


	//void updateRenderedElements() {

	//}


	void setNumOfElements(unsigned& _renderedElements) {
		numOfElements = _renderedElements;
	}


	void drawOn(sf::RenderWindow &window) {
		window.draw(frame);
		window.draw(baseLine);

		setElements();

		for (unsigned i{ 0 }; i < numOfElements; i++) {
			elements[i].drawOn(window);
		}

	}


};