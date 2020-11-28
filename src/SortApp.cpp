#include "stdafx.hpp"

#include "SortApp.hpp"


// Constructor
SortApp::SortApp(sf::RenderWindow& _window) :

	// Member initializers

	targetWindow{ _window },

	topNavBar{ topNavBarSize },
	backBtn			{		"Back"	  , rsc.menuFont, 50 },
	insertionSortBtn{ "Insertion Sort", rsc.menuFont, 50 },
	shellSortBtn	{   "Shell Sort"  , rsc.menuFont, 50 },
	plusBtn { "+", rsc.menuFont, 90 },
	minusBtn{ "-", rsc.menuFont, 90 },
	genNewArrBtn{ "Generate New Arr"  , rsc.menuFont, 65 },

	btmNavBar{ btmNavBarSize},

	sortFrame{ frameSize },
	numOfElements{ 20 },
	elements{ randomElementsArr.randomize() },
	animationSpeed{0.0001}

// Constructor Body
{
	setNavBars();
	setSortFrame();
	arrangeElements();
}


void SortApp::setNavBars()
{
	// Set top navigation bar
	topNavBar.setPosition(topNavBarPos);
	topNavBar.setFillColor(themeColor);

	// Calculate positions for text buttons
	sf::Vector2f iniTopNavLine{(topNavBarSize.x - backBtn.getWidth()
												- insertionSortBtn.getWidth()
												- shellSortBtn.getWidth()
												- plusBtn.getWidth()
												- minusBtn.getWidth()
												- genNewArrBtn.getWidth()) / 3.f
												, (topNavBarSize.y - backBtn.getHeight()) / 5.f };
	sf::Vector2f backBtnTextPos{ iniTopNavLine.y, iniTopNavLine.y };
	sf::Vector2f insertionSortBtnTextPos{ iniTopNavLine.x + backBtn.getWidth() - 25.f, iniTopNavLine.y };
	sf::Vector2f shellSortBtnTextPos{ insertionSortBtnTextPos.x + insertionSortBtn.getWidth() + 70.f, iniTopNavLine.y };
	sf::Vector2f genNewArrBtnTextPos{ (topNavBarSize.x - genNewArrBtn.getWidth() - 85.f), iniTopNavLine.y - 15.f };
	sf::Vector2f minusBtnPos{ genNewArrBtnTextPos.x - minusBtn.getWidth() - 35.f, iniTopNavLine.y - 20.f };
	sf::Vector2f plusBtnPos{ minusBtnPos.x - plusBtn.getWidth() - 8.f, minusBtnPos.y };

	// Set text buttons
	backBtn.setPosition(backBtnTextPos);
	insertionSortBtn.setPosition(insertionSortBtnTextPos);
	shellSortBtn.setPosition(shellSortBtnTextPos);
	genNewArrBtn.setPosition(genNewArrBtnTextPos);
	minusBtn.setPosition(minusBtnPos);
	plusBtn.setPosition(plusBtnPos);

	// Set bottom navigation bar
	btmNavBar.setPosition(btmNavBarPos);
	btmNavBar.setFillColor(themeColor);
}


void SortApp::setSortFrame()
{
	sortFrame.setFillColor(themeColor);
	sortFrame.setPosition(framePos);
	sortFrame.setOutlineColor(frameBorderColor);
	sortFrame.setOutlineThickness(1.f);
}


// Swaps elements with animation while sorting
void SortApp::swapElements(Element& leftElem, Element& rightElem) {
	float offset = 1.2f * singleElementWidth;

	leftElem.setColor(sf::Color::Yellow);
	rightElem.setColor(sf::Color::Red);

	while (leftElem.getXPos() <= rightElem.getXPos() + singleElementWidth) {
		updateEvents();
		leftElem.move ( animationSpeed * dt, 0.f);
		rightElem.move(-animationSpeed * dt, 0.f);
		targetWindow.clear();
		renderNavBar();
		renderElements();
		targetWindow.display();
	}

	std::swap(leftElem, rightElem);
	leftElem.setColor(sf::Color::Green);
	rightElem.setColor(sf::Color::Green);
	arrangeElements();
}

//void SortFrame::updateMovement(Element& leftElem, Element& rightElem)
//{
//	leftElem.move(deltaTime, 0.f);
//	rightElem.move(-deltaTime, 0.f);
//}

// Sets elements at the centre of the frame (window) by setting the elements
// width from 5 to 200 && gap from 2 to 60
void SortApp::arrangeElements()
{
	singleElementWidth = float(zoomFactor / numOfElements);
	float gap = 0.2f * singleElementWidth;

	float totalWidthOfElements = numOfElements * (singleElementWidth + gap) - gap;
	float iniXPos = (sortFrame.getLocalBounds().width - totalWidthOfElements) / 2;

	for (unsigned i{ 0 }; i < numOfElements; i++) {
		elements[i].setRect(iniXPos + (i * (singleElementWidth + gap)), framePos.y, singleElementWidth);
	}

}

void SortApp::randomize()
{
	elements = randomElementsArr.randomize();
	arrangeElements();
}


// Insertion Algorithm
// checks for larger element to the left
void SortApp::visualizeInsertion() {
	int j;

	for (unsigned i{ 1 }; i < numOfElements; i++) {
		j = i - 1;

		while (j >= 0 && (elements[j] > elements[j + 1])) {
			swapElements(elements[j], elements[j + 1]);
			--j;
		}
	}
}


// Shell Sort Algorithm
void SortApp::visualizeShellSort() {
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
void SortApp::inrElements()
{
	if (numOfElements + 10 < ARR_SIZE) numOfElements += 10;
	arrangeElements();
}

void SortApp::dcrElements()
{
	if (numOfElements - 10 > 6) numOfElements -= 10;
	arrangeElements();
}


// Handles pause state
void SortApp::handlePause()
{
	while (pauseIndicator.isPaused()) {
		while (targetWindow.pollEvent(event))
		{
			switch (event.type) {

				// handles window close event
			case sf::Event::Closed:
				targetWindow.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::P:
					pauseIndicator.reverseState();
					pauseIndicator.updateIcon();
					break;

				case sf::Keyboard::Escape:
					targetWindow.close();

				}
				break;

			}
		}
	}
}


void SortApp::updateMouseEvents()
{
	float mouseX = (float)sf::Mouse::getPosition(targetWindow).x;
	float mouseY = (float)sf::Mouse::getPosition(targetWindow).y;

	backBtn.update(mouseX, mouseY);
	insertionSortBtn.update(mouseX, mouseY);
	shellSortBtn.update(mouseX, mouseY);
	plusBtn.update(mouseX, mouseY);
	minusBtn.update(mouseX, mouseY);
	genNewArrBtn.update(mouseX, mouseY);

	if (backBtn.onClick()) {
		targetWindow.close();
	}

	if (insertionSortBtn.onClick()) {
		visualizeInsertion();
	}

	if (shellSortBtn.onClick()) {
		visualizeShellSort();
	}

	if (plusBtn.onClick()) {
		inrElements();
	}

	if (minusBtn.onClick()) {
		dcrElements();
	}

	if (genNewArrBtn.onClick()) {
		randomize();
	}
}


void SortApp::updateEvents() 
{
	while (targetWindow.pollEvent(event)) 
	{
		switch (event.type) {

			// handles window close event
			case sf::Event::Closed:
				targetWindow.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{

					// Shortcuts :- 
					// I -> Insertion Sort Visualization
					// S -> Shell Sort Visualization

				case sf::Keyboard::I:
					visualizeInsertion();
					break;


				case sf::Keyboard::S:
					visualizeShellSort();
					break;

				case sf::Keyboard::P:
					pauseIndicator.reverseState();
					pauseIndicator.updateIcon();
					handlePause();
					break;

				case sf::Keyboard::G:
					randomize();
					break;

				case sf::Keyboard::Equal:
					inrElements();
					break;

				case sf::Keyboard::Hyphen:
					dcrElements();
					break;

				case sf::Keyboard::Escape:
					targetWindow.close();
					break;

				}
				break;

			case sf::Event::MouseMoved:
				updateMouseEvents();
				break;
				
		}
	}
}


void SortApp::update()
{
	updateEvents();
	pauseIndicator.updateIcon();

}


void SortApp::renderNavBar()
{
	targetWindow.draw(topNavBar);

	backBtn.renderOn(targetWindow);
	insertionSortBtn.renderOn(targetWindow);
	shellSortBtn.renderOn(targetWindow);
	plusBtn.renderOn(targetWindow);
	minusBtn.renderOn(targetWindow);
	genNewArrBtn.renderOn(targetWindow);

	targetWindow.draw(btmNavBar);
	pauseIndicator.renderOn(targetWindow);

}

void SortApp::renderElements()
{
	targetWindow.draw(sortFrame);

	for (unsigned i{ 0 }; i < numOfElements; i++) {
		elements[i].drawOn(targetWindow);
	}
}


// Draws all App Components on window
void SortApp::render() 
{
	dt = deltaClock.restart().asMicroseconds();

	targetWindow.clear(sf::Color::Cyan);

	renderNavBar();
	renderElements();


	targetWindow.display();
}
