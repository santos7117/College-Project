#include "stdafx.hpp"

#include "Application.hpp"


// Constructor
Application::Application(sf::RenderWindow& _window) :

	// Member initializers

	targetWindow{ _window },


	// initialization of Navigation Bar and Buttons 
	topNavBar		{ topNavBarSize },
	backBtn			{	   	 "Back"		  , rsc.menuFont, 50 },
	selectionSortBtn{	"Selection Sort"  , rsc.menuFont, 35 },
	insertionSortBtn{	"Insertion Sort"  , rsc.menuFont, 35 },
	shellSortBtn	{	  "Shell Sort"	  , rsc.menuFont, 35 },
	plusBtn			{		   "+"		  , rsc.menuFont, 90 },
	minusBtn		{		   "-"		  , rsc.menuFont, 90 },
	genNewArrBtn	{ "Generate New Arr"  , rsc.menuFont, 65 },
	btmNavBar		{ btmNavBarSize },

	// initialization of Sort Frame
	sortFrame{ frameSize },
	numOfElements	 { 6 },
	numOfSwaps		 { 0 },
	numOfComparisions{ 0 },
	animationSpeed	 { 1.f },
	elementsSizeIndicator  {	  "Size : " + std::to_string(numOfElements)		 , rsc.menuFont, 20},
	animationSpeedIndicator{"Animation Speed : " + std::to_string(animationSpeed), rsc.menuFont, 20},
	swapIndicator		   {					"Swaps : 0"					     , rsc.menuFont, 20},
	comparisionIndicator   {				 "Comparisions : 0"					 , rsc.menuFont, 20},

	// initialization of array
	elements{ elementsGenerator.init() }

// Constructor Body
{
	setNavBars();
	setSortFrame();
	randomize(ARR_SIZE);

}



// Sets up Navigation Bar and Buttons position and color 
void Application::setNavBars()
{
	// set top navigation bar
	topNavBar.setPosition(topNavBarPos);
	topNavBar.setFillColor(themeColor);

	// calculates positions for buttons relative to top navigation bar
	const static sf::Vector2f iniTopNavLine{(topNavBarSize.x - backBtn.getWidth()
															- selectionSortBtn.getWidth()
															- insertionSortBtn.getWidth()
															- shellSortBtn.getWidth()
															- plusBtn.getWidth()
															- minusBtn.getWidth()
															- genNewArrBtn.getWidth()) / 3.f
															, (topNavBarSize.y - backBtn.getHeight()) / 5.f };
	const static sf::Vector2f backBtnTextPos	 {						 iniTopNavLine.y					  , iniTopNavLine.y	- 15.f	};
	const static sf::Vector2f selectionSortBtnPos{			iniTopNavLine.x + backBtn.getWidth() - 25.f		  , iniTopNavLine.y			};
	const static sf::Vector2f insertionSortBtnPos{ selectionSortBtnPos.x + insertionSortBtn.getWidth() + 70.f , iniTopNavLine.y			};
	const static sf::Vector2f shellSortBtnPos	 { insertionSortBtnPos.x + insertionSortBtn.getWidth() + 70.f , iniTopNavLine.y			};
	const static sf::Vector2f genNewArrBtnPos	 {	  (topNavBarSize.x - genNewArrBtn.getWidth() - 85.f) 	  , iniTopNavLine.y - 25.f  };
	const static sf::Vector2f minusBtnPos		 {		genNewArrBtnPos.x - minusBtn.getWidth() - 35.f		  , iniTopNavLine.y - 40.f  };
	const static sf::Vector2f plusBtnPos		 {			 minusBtnPos.x - plusBtn.getWidth() - 8.f		  , minusBtnPos.y			};

	// set buttons position from above calculations
	backBtn.setPosition(backBtnTextPos);
	selectionSortBtn.setPosition(selectionSortBtnPos);
	insertionSortBtn.setPosition(insertionSortBtnPos);
	shellSortBtn.setPosition(shellSortBtnPos);
	genNewArrBtn.setPosition(genNewArrBtnPos);
	minusBtn.setPosition(minusBtnPos);
	plusBtn.setPosition(plusBtnPos);

	// set bottom navigation bar
	btmNavBar.setPosition(btmNavBarPos);
	btmNavBar.setFillColor(themeColor);
}


// Sets up Sort Frame positions and Sort Detail Indicator positions
// This is the area where actual animations are visible while sorting
void Application::setSortFrame()
{
	// set up sort frame
	sortFrame.setFillColor(themeColor);
	sortFrame.setPosition(framePos);
	sortFrame.setOutlineColor(frameBorderColor);
	sortFrame.setOutlineThickness(1.f);

	// set up indicators
	elementsSizeIndicator.setPosition  (framePos.x + 5.f , btmNavBarPos.y - 4.f		   );
	animationSpeedIndicator.setPosition(framePos.x + 5.f , btmNavBarPos.y - 8.f + 25.f );
	swapIndicator.setPosition		   (framePos.x + 5.f , 810.f					   );
	comparisionIndicator.setPosition   (framePos.x + 5.f , 810.f + 15.f				   );

	alignElements();
}


// Aligns elements at the centre of the frame (window) by setting proper positions of the elements
void Application::alignElements()
{
	// calculates width of single elements and gaps associated with the elements
	singleElementWidth = float(normalZoomFactor / numOfElements);
	float gap = 0.2f * singleElementWidth;

	// calculates total width of all rendered elements and initial position for first element
	float totalWidthOfElements = numOfElements * (singleElementWidth + gap) - gap;
	float iniXPos = (frameSize.x - totalWidthOfElements) / 2.f;

	// sets the above calculated positions for every elements
	for (short i{ 0 }; i < numOfElements; i++)
		elements[i].setRect(iniXPos + (i * (singleElementWidth + gap)), framePos.y + 2.f, singleElementWidth);
}

// Randomizes original array
void Application::randomize(const short unsigned& _numOfElements)
{
	elements = elementsGenerator.randomize(_numOfElements);

	resetSortDetails();
	alignElements();
}

// Swaps elements with visual animation while sorting
void Application::swapElements(Element& leftElem, Element& rightElem, bool optimize = 0) {
	// calculates animation distance for swap animation
	const float animationDistance = rightElem.getXPos();

	// color codes the current swapping elements
	leftElem.setColor(leftUnsortedColor);
	rightElem.setColor(rightUnsortedColor);

	// updates sort details
	++numOfComparisions;
	++numOfSwaps;

	while (leftElem.getXPos() < animationDistance)
	{
		// listens to any events if provided during animations
		updateEvents();

		// updates sort details and swap animations
		updateSortDetails();
		rightElem.move(-animationSpeed * dt, 0.f);
		leftElem.move(animationSpeed * dt, 0.f);

		// renders everything at real time
		renderEverything();
	}

	// reflects change on original array
	std::swap(leftElem, rightElem);

	// color codes optimization algorithm (shell sort) elements
	if (optimize)
	{
		leftElem.setColor(gapSortedColor);
		rightElem.setColor(gapSortedColor);
	}

	alignElements();
}


// Insertion Algorithm
// Checks for larger element on the left and inserts at appropriate position
void Application::visualizeInsertion(ElementsArray& arr) 
{
	resetSortDetails();

	// pointer for travelling to the left of array
	short j;

	for (short i{ 1 }; i < numOfElements; i++) 
	{
		++numOfComparisions;
		j = i - 1;

		for (j; j >= 0 && (arr[j] > arr[j + 1]); --j)
		{
			swapElements(arr[j], arr[j + 1]);
		}
	}

	setSortedColor();
}

// Shell Sort Algorithm
// Gaps sorts the given array first and then applies insertion algorithm
void Application::visualizeShellSort(ElementsArray& arr) {
	resetSortDetails();

	// gap sorts for given gap size
	for (const short unsigned int& gap : SHELL_GAPS) 
	{
		for (short i =gap; i < numOfElements; ++i)
		{
			++numOfComparisions;
			if ((arr[i - gap]) > arr[i]) {
				swapElements(arr[i-gap], arr[i], true);
			}

		}
	}

	//visualizeInsertion();
}

// Selection Sort Algorithm
// Checks for the smallest element on each pass and walks the element to the first
void Application::visualizeSelection(ElementsArray& arr)
{
	resetSortDetails();

	short i, j, min;

	for (i = 0; i < numOfElements - 1; ++i)
	{
		min = i;
		for (j = i + 1; j < numOfElements; ++j)
		{
			if (arr[j] < arr[min]) {
				++numOfComparisions;
				min = j;
			}
		}

		if (min != i) swapElements(arr[i], arr[min]);
	}

	setSortedColor();
}

// Bubble Sort Algorithm
// Checks for largest element on each pass and walks the element to the last
void Application::visualizeBubbleSort(ElementsArray& arr) {
	resetSortDetails();

	for (short pass{ 0 }; pass < numOfElements; ++pass)
	{
		++numOfComparisions;

		for (short j{ 0 }; j < (numOfElements - pass - 1); ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swapElements(arr[j], arr[j + 1]);
			}
		}
	}

	setSortedColor();
}


void Application::setSortedColor()
{
	for (short i{ 0 }; i<numOfElements; ++i)
		elements[i].setColor(sortedColor);
}


// Increments number of elements to be rendered
void Application::inrElements()
{
	if (numOfElements + 10 < ARR_SIZE) numOfElements += 10;
	alignElements();
}

// Decrements number of elements to be rendered
void Application::dcrElements()
{
	if (numOfElements - 10 > 6) numOfElements -= 10;
	alignElements();
}


// Resets Sort Details 
void Application::resetSortDetails()
{
	numOfSwaps = 0;
	numOfComparisions = 0;
	swapIndicator.setString("Swaps : " + std::to_string(numOfSwaps));
	comparisionIndicator.setString("Comparisions : " + std::to_string(numOfComparisions));
}

// Updates Sort Details 
void Application::updateSortDetails()
{
	elementsSizeIndicator.setString("Size : " + std::to_string(numOfElements));
	animationSpeedIndicator.setString("Animation Speed : " + std::to_string(animationSpeed));
	swapIndicator.setString("Swaps : " + std::to_string(numOfSwaps));
	comparisionIndicator.setString("Comparisions : " + std::to_string(numOfComparisions));
}


// Handles pause state
void Application::handlePause()
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
					break;

				case sf::Keyboard::Escape:
					targetWindow.close();
					break;

				}
				break;

			}
		}
	}
}

// Updates Buttons based on mouse positions
// Handles click events on Buttons
void Application::updateMouseEvents()
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

	if (backBtn.onClick())	targetWindow.close();

	if (selectionSortBtn.onClick())	visualizeSelection(elements);

	if (insertionSortBtn.onClick())	visualizeInsertion(elements);

	if (shellSortBtn.onClick())	visualizeShellSort(elements);

	if (plusBtn.onClick())	inrElements();

	if (minusBtn.onClick())	dcrElements();

	if (genNewArrBtn.onClick())	randomize(numOfElements);
}

// Updates and handles events
void Application::updateEvents() 
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
					// S -> Selection Sort Visualization
					// I -> Insertion Sort Visualization
					// H -> Shell Sort Visualization
					// B -> Bubble Sort Visualization

				case sf::Keyboard::I:
					visualizeInsertion(elements);
					break;


				case sf::Keyboard::H:
					visualizeShellSort(elements);
					break;

				case sf::Keyboard::B:
					visualizeBubbleSort(elements);
					break;

				case sf::Keyboard::S:
					visualizeSelection(elements);
					break;

				case sf::Keyboard::Space:
					pauseIndicator.reverseState();
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

// Updates all the events and Sort Details
void Application::update()
{
	updateEvents();
	updateSortDetails();
}


// Draws all Navigation Bar Components
void Application::drawNavBar()
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

// Draws all Sort Details
void Application::drawSortDetails()
{
	targetWindow.draw(elementsSizeIndicator);
	targetWindow.draw(animationSpeedIndicator);

	targetWindow.draw(swapIndicator);
	targetWindow.draw(comparisionIndicator);
}

// Draws all elements 
void Application::drawElements()
{
	targetWindow.draw(sortFrame);

	for (short i{ 0 }; i< numOfElements; ++i)
		elements[i].drawOn(targetWindow);
}



// Renders every visuals at real time
void Application::renderEverything()
{
	// clears window for updated visuals
	targetWindow.clear(themeColor);

	// draws visuals
	drawNavBar();
	drawElements();
	drawSortDetails();

	// displays all of the above visuals
	targetWindow.display();
}


// Draws all App Components on window
void Application::render() 
{
	// calculates delta time for smooth frame transition
	dt = deltaClock.restart().asMilliseconds();

	renderEverything();
}
