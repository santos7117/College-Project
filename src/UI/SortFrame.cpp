#include "../stdafx.hpp"

#include "SortFrame.hpp"


void SortFrame::setSortFrame() 
{
	frame.setFillColor(themeColor);
	frame.setPosition(framePos);
	frame.setOutlineColor(frameBorderColor);
	frame.setOutlineThickness(1.f);
}


// Swaps elements with animation while sorting
void SortFrame::swapElements(Element& leftElem, Element& rightElem) {
	float leftXPos = leftElem.getXPos();
	float rightXPos = rightElem.getXPos();
	//float offset = singleElementWidth + gap;

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

SortFrame::SortFrame(sf::RenderWindow& _window) :
	target{_window},
	frame{frameSize},
	numOfElements{20},
	elements{randomElementsArr.randomize()}
{
	setSortFrame();
}


// Sets elements at the centre of the frame (window) by setting the elements
// width from 5 to 200 && gap from 2 to 60
void SortFrame::setElements() 
{
	singleElementWidth = float (zoomFactor / numOfElements);
	float gap = 0.2f * singleElementWidth;

	float totalWidthOfElements = numOfElements * (singleElementWidth + gap) - gap;
	float iniXPos = (frame.getLocalBounds().width - totalWidthOfElements) / 2;

	for (unsigned i{ 0 }; i < numOfElements; i++) {
		elements[i].setRect(iniXPos + (i * (singleElementWidth + gap)), framePos.y, singleElementWidth);
		elements[i].setColor(unsortedElementsColor);
	}

}

void SortFrame::randomize()
{
	elements = randomElementsArr.randomize();
	setElements();
}


// Insertion Algorithm
// checks for larger element to the left
void SortFrame::visualizeInsertion() {
	int j;

	for (unsigned i{ 1 }; i < numOfElements; i++) {
		j = i - 1;

		while (j >= 0 &&  ( elements[j] > elements[j+1] ) ) {
			swapElements(elements[j] , elements[j+1]);
			--j;
		}
	}
}


// Shell Sort Algorithm
void SortFrame::visualizeShellSort() {
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
void SortFrame::inrElements() 
{	
	numOfElements += 10;
	setElements();
}

void SortFrame::dcrElements() 
{ 
	numOfElements -= 10;
	setElements();
}


// Draws SortFrame 
void SortFrame::render() 
{
	target.draw(frame);

	for (unsigned i{ 0 }; i < numOfElements; i++) {
		elements[i].drawOn(target);
	}

}