#include "stdafx.hpp"

#include "SortApp.hpp"


// Constructor
SortApp::SortApp(sf::RenderWindow& _window) :

	// Member initializers

	targetWindow{ _window },

	topNavBar{ topNavBarSize },
	backBtn			{		"Back"	  , rsc.menuFont, 50 },
	selectionSortBtn{ "Selection Sort", rsc.menuFont, 35 },
	insertionSortBtn{ "Insertion Sort", rsc.menuFont, 35 },
	shellSortBtn	{   "Shell Sort"  , rsc.menuFont, 35 },
	plusBtn { "+", rsc.menuFont, 90 },
	minusBtn{ "-", rsc.menuFont, 90 },
	genNewArrBtn{ "Generate New Arr"  , rsc.menuFont, 65 },

	btmNavBar{ btmNavBarSize},

	sortFrame{ frameSize },
	numOfElements{ 6 },
	elements{ randomElementsArr.randomize(ARR_SIZE) },
	animationSpeed{0.05f}

// Constructor Body
{
	setNavBars();
	setSortFrame();
	alignElements();
}


void SortApp::setNavBars()
{
	// Set top navigation bar
	topNavBar.setPosition(topNavBarPos);
	topNavBar.setFillColor(themeColor);

	// Calculate positions for text buttons
	sf::Vector2f iniTopNavLine{(topNavBarSize.x - backBtn.getWidth()
												- selectionSortBtn.getWidth()
												- insertionSortBtn.getWidth()
												- shellSortBtn.getWidth()
												- plusBtn.getWidth()
												- minusBtn.getWidth()
												- genNewArrBtn.getWidth()) / 3.f
												, (topNavBarSize.y - backBtn.getHeight()) / 5.f };
	sf::Vector2f backBtnTextPos{ iniTopNavLine.y, iniTopNavLine.y };
	sf::Vector2f selectionSortBtnPos{ iniTopNavLine.x + backBtn.getWidth() - 25.f, iniTopNavLine.y };
	sf::Vector2f insertionSortBtnPos{ selectionSortBtnPos.x + insertionSortBtn.getWidth() + 70.f, iniTopNavLine.y };
	sf::Vector2f shellSortBtnPos{ insertionSortBtnPos.x + insertionSortBtn.getWidth() + 70.f, iniTopNavLine.y };
	sf::Vector2f genNewArrBtnPos{ (topNavBarSize.x - genNewArrBtn.getWidth() - 85.f), iniTopNavLine.y - 15.f };
	sf::Vector2f minusBtnPos{ genNewArrBtnPos.x - minusBtn.getWidth() - 35.f, iniTopNavLine.y - 20.f };
	sf::Vector2f plusBtnPos{ minusBtnPos.x - plusBtn.getWidth() - 8.f, minusBtnPos.y };

	// Set text buttons
	backBtn.setPosition(backBtnTextPos);
	selectionSortBtn.setPosition(selectionSortBtnPos);
	insertionSortBtn.setPosition(insertionSortBtnPos);
	shellSortBtn.setPosition(shellSortBtnPos);
	genNewArrBtn.setPosition(genNewArrBtnPos);
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
void SortApp::swapElements(Element& leftElem, Element& rightElem, bool optimize = 0) {
	const float animationDistance = rightElem.getXPos();

	leftElem. setColor(leftUnsortedColor);
	rightElem.setColor(rightUnsortedColor);

	while (leftElem.getXPos() < animationDistance) 
	{
		updateEvents();
		rightElem.move(-animationSpeed * dt, 0.f);
		leftElem. move( animationSpeed * dt, 0.f);
		targetWindow.clear();
		renderNavBar();
		renderElements();
		targetWindow.display();
	}

	// reflect change on array
	std::swap(leftElem, rightElem);

	if (optimize)
	{
		leftElem. setColor(gapSortedColor);
		rightElem.setColor(gapSortedColor);
	}

	alignElements();
}

//void SortFrame::updateMovement(Element& leftElem, Element& rightElem)
//{
//	leftElem.move(deltaTime, 0.f);
//	rightElem.move(-deltaTime, 0.f);
//}

// Sets elements at the centre of the frame (window) by setting the elements
// width from 5 to 200 && gap from 2 to 60
void SortApp::alignElements()
{
	singleElementWidth = float(zoomFactor / numOfElements);
	float gap = 0.2f * singleElementWidth;

	float totalWidthOfElements = numOfElements * (singleElementWidth + gap) - gap;
	float iniXPos = (sortFrame.getLocalBounds().width - totalWidthOfElements) / 2;

	for (short i{ 0 }; i < numOfElements; i++) 
	{
		elements[i].setRect(iniXPos + (i * (singleElementWidth + gap)), framePos.y, singleElementWidth);
	}

}

void SortApp::randomize(const short unsigned& _numOfElements)
{
	elements = randomElementsArr.randomize(_numOfElements);
	alignElements();
}


// Insertion Algorithm
// checks for larger element to the left
void SortApp::visualizeInsertion() {
	short j;

	for (short i{ 1 }; i < numOfElements; i++) 
	{
		j = i - 1;

		while (j >= 0 && (elements[j] > elements[j + 1])) {
			swapElements(elements[j], elements[j + 1]);
			--j;
		}
	}

	setSortedColor();
}


// Shell Sort Algorithm
void SortApp::visualizeShellSort() {

	// gap sort
	for (const short unsigned int& gap : SHELL_GAPS) 
	{
		//# Do a gapped insertion sort for this gap size.
		//# The first gap elements a[0..gap - 1] are already in gapped order keep adding one more element until the entire array is gap sorted

		for (short i =gap; i < numOfElements; ++i)
		{
			if ((elements[i - gap]) > elements[i]) {
				swapElements(elements[i-gap], elements[i], true);
			}

		}
	}

	//visualizeInsertion();
}


void SortApp::visualizeBubbleSort() {
	bool isSorted{ false };

	for (short pass{ 0 }; pass < numOfElements && !isSorted; ++pass)
	{
		for (short j{ 0 }; j < (numOfElements - pass - 1); ++j)
		{
			isSorted = true;
			if (elements[j] > elements[j + 1])
			{
				swapElements(elements[j], elements[j + 1]);
				isSorted = false;
			}
		}
	}

	setSortedColor();
}


void SortApp::visualizeSelection()
{
	short i, j, min;

	for (i = 0; i < numOfElements - 1; ++i)
	{
		min = i;
		for (j = i + 1; j < numOfElements; ++j)
		{
			if (elements[j] < elements[min]) min = j;
		}

		if (min != i) swapElements(elements[i], elements[min]);
	}

	setSortedColor();
}


void SortApp::setSortedColor()
{
	for (short i{ 0 }; i < numOfElements; ++i)
		elements[i].setColor(sortedColor);
}


// Sets number of elements to be rendered
void SortApp::inrElements()
{
	if (numOfElements + 10 < ARR_SIZE) numOfElements += 10;
	alignElements();
}

void SortApp::dcrElements()
{
	if (numOfElements - 10 > 6) numOfElements -= 10;
	alignElements();
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
					break;
				case sf::Keyboard::G:
					randomize(numOfElements);
					break;
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
	selectionSortBtn.update(mouseX, mouseY);
	insertionSortBtn.update(mouseX, mouseY);
	shellSortBtn.update(mouseX, mouseY);
	plusBtn.update(mouseX, mouseY);
	minusBtn.update(mouseX, mouseY);
	genNewArrBtn.update(mouseX, mouseY);

	if (backBtn.onClick()) {
		targetWindow.close();
	}

	if (selectionSortBtn.onClick()) {
		visualizeSelection();
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
		randomize(numOfElements);
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


				case sf::Keyboard::H:
					visualizeShellSort();
					break;

				case sf::Keyboard::B:
					visualizeBubbleSort();
					break;

				case sf::Keyboard::S:
					visualizeSelection();
					break;

				case sf::Keyboard::P:
					pauseIndicator.reverseState();
					pauseIndicator.updateIcon();
					handlePause();
					break;

				case sf::Keyboard::G:
					randomize(numOfElements);
					break;

				case sf::Keyboard::Up:
					inrElements();
					break;

				case sf::Keyboard::Down:
					dcrElements();
					break;

				case sf::Keyboard::Left:
					animationSpeed -= 0.05f;
					break;

				case sf::Keyboard::Right:
					animationSpeed += 0.05f;
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
	selectionSortBtn.renderOn(targetWindow);
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

	for (short i{ 0 }; i < numOfElements; i++) {
		elements[i].drawOn(targetWindow);
	}
}


// Draws all App Components on window
void SortApp::render() 
{
	dt = deltaClock.restart().asMilliseconds();

	targetWindow.clear(sf::Color::Cyan);

	renderNavBar();
	renderElements();


	targetWindow.display();
}
