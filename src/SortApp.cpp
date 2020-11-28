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

	sortFrame{ targetWindow }, 

	btmNavBar{ btmNavBarSize}


		

// Constructor Body
{
	setNavBars();

	sortFrame.setElements();
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
		sortFrame.visualizeInsertion();
	}

	if (shellSortBtn.onClick()) {
		sortFrame.visualizeShellSort();
	}

	if (plusBtn.onClick()) {
		sortFrame.inrElements();
	}

	if (minusBtn.onClick()) {
		sortFrame.dcrElements();
	}

	if (genNewArrBtn.onClick()) {
		sortFrame.randomize();
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
					sortFrame.visualizeInsertion();
					break;


				case sf::Keyboard::S:
					sortFrame.visualizeShellSort();
					break;

				case sf::Keyboard::P:
					pauseIndicator.reverseState();
					pauseIndicator.updateIcon();
					handlePause();
					break;

				case sf::Keyboard::G:
					sortFrame.randomize();
					break;

				case sf::Keyboard::Equal:
					sortFrame.inrElements();
					break;

				case sf::Keyboard::Hyphen:
					sortFrame.dcrElements();
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

	sortFrame.update(animationTime.asMilliseconds());
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
}


// Draws all App Components on window
void SortApp::render() 
{
	animationTime = deltaClock.restart();

	targetWindow.clear(sf::Color::Cyan);

	renderNavBar();
	pauseIndicator.renderOn(targetWindow);

	sortFrame.render();

	targetWindow.display();
}
