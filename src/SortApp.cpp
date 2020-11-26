#pragma once

#include "stdafx.hpp"


#include "UI/SortFrameRenderer.cpp"



class SortApp {
private:
	sf::Event event;
	sf::RenderWindow& targetWindow;

	sf::Color theme;

	sf::RectangleShape topNavBar;
	sf::Text backBtnText;
	sf::Text insertionSortBtnText;
	sf::Text shellSortBtnText;
	sf::Text plusBtn;
	sf::Text minusBtn;
	sf::Text genNewArrBtnText;
	SortFrame sortFrame;
	sf::RectangleShape btmNavBar;

	bool isPaused;



public:

	// Constructor
	SortApp(sf::RenderWindow& _window) :

		// Member initializers

		targetWindow{ _window }, 

		theme{themeColor},

		topNavBar{ topNavBarSize },
		backBtnText{ "Back", rsc.menuFont, 50 },
		insertionSortBtnText{ "Insertion Sort", rsc.menuFont, 50 },
		shellSortBtnText{ "Shell Sort", rsc.menuFont, 50 },
		plusBtn{ "+", rsc.menuFont, 90 },
		minusBtn{ "-", rsc.menuFont, 90 },
		genNewArrBtnText{ "Generate New Array", rsc.menuFont, 75 },

		sortFrame{ targetWindow }, 

		btmNavBar{ btmNavBarSize},


		isPaused{0}

	// Constructor Body
	{
		setNavBars();

		sortFrame.setElements();
	}


	void setNavBars()
	{
		// Set top navigation bar
		topNavBar.setPosition(topNavBarPos);
		topNavBar.setFillColor(theme);

		// Calculate positions for text buttons
		sf::Vector2f iniTopNavLine{(topNavBarSize.x - backBtnText.getLocalBounds().width
													- insertionSortBtnText.getLocalBounds().width
													- shellSortBtnText.getLocalBounds().width
													- plusBtn.getGlobalBounds().width
													- minusBtn.getGlobalBounds().width
													- genNewArrBtnText.getLocalBounds().width) / 3.f
													, (topNavBarSize.y - backBtnText.getLocalBounds().height) / 3.f };
		sf::Vector2f backBtnTextPos{ iniTopNavLine.y, iniTopNavLine.y };
		sf::Vector2f insertionSortBtnTextPos{ iniTopNavLine.x + backBtnText.getLocalBounds().width + 5.f, iniTopNavLine.y };
		sf::Vector2f shellSortBtnTextPos{ insertionSortBtnTextPos.x + insertionSortBtnText.getGlobalBounds().width + 45.f, iniTopNavLine.y };
		sf::Vector2f genNewArrBtnTextPos{ (topNavBarSize.x - genNewArrBtnText.getLocalBounds().width - 10.f), iniTopNavLine.y - 10.f };
		sf::Vector2f minusBtnPos{ genNewArrBtnTextPos.x - minusBtn.getGlobalBounds().width - 35.f, iniTopNavLine.y - 20.f };
		sf::Vector2f plusBtnPos{ minusBtnPos.x - plusBtn.getGlobalBounds().width - 5.f, minusBtnPos.y };

		// Set text buttons
		backBtnText.setPosition(backBtnTextPos);
		insertionSortBtnText.setPosition(insertionSortBtnTextPos);
		shellSortBtnText.setPosition(shellSortBtnTextPos);
		genNewArrBtnText.setPosition(genNewArrBtnTextPos);
		minusBtn.setPosition(minusBtnPos);
		plusBtn.setPosition(plusBtnPos);

		// Set bottom navigation bar
		btmNavBar.setPosition(btmNavBarPos);
		btmNavBar.setFillColor(theme);
	}

	// Handles pause state
	void handlePause() {
		while (isPaused) {
			updateEvents();
		}
	}

	void handleShortcuts()
	{
		while (targetWindow.pollEvent(event))
		{
			if (event.type == event.key.code)
			{
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
					isPaused = !isPaused;
					handlePause();
					break;

				}
			}
		}
	}

	void updateEvents() 
	{
		while (targetWindow.pollEvent(event)) 
		{
			switch (event.type) {

				// handles window close event
				case sf::Event::Closed:
					targetWindow.close();
					break;
				
			}
		}
	}

	void update()
	{
		updateEvents();

		handleShortcuts();


	}



	void renderNavBar()
	{
		targetWindow.draw(topNavBar);

		targetWindow.draw(backBtnText);
		targetWindow.draw(insertionSortBtnText);
		targetWindow.draw(shellSortBtnText);
		targetWindow.draw(plusBtn);
		targetWindow.draw(minusBtn);
		targetWindow.draw(genNewArrBtnText);

		targetWindow.draw(btmNavBar);
	}

	// Draws all App Components on window
	void render() {
		targetWindow.clear();

		renderNavBar();

		sortFrame.render();

		targetWindow.display();
	}


};