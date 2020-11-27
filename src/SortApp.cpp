//#include "stdafx.hpp"
//
//#include "SortApp.hpp"
//
//
//// Constructor
//SortApp::SortApp(sf::RenderWindow& _window) :
//
//	// Member initializers
//
//	targetWindow{ _window }, 
//
//	theme{themeColor},
//
//	topNavBar{ topNavBarSize },
//	backBtnText{ "Back", rsc.menuFont, 50 },
//	insertionSortBtnText{ "Insertion Sort", rsc.menuFont, 50 },
//	shellSortBtnText{ "Shell Sort", rsc.menuFont, 50 },
//	plusBtn{ "+", rsc.menuFont, 90 },
//	minusBtn{ "-", rsc.menuFont, 90 },
//	genNewArrBtnText{ "Generate New Array", rsc.menuFont, 75 },
//
//	sortFrame{ targetWindow }, 
//
//	btmNavBar{ btmNavBarSize}
//
//
//		
//
//// Constructor Body
//{
//	setNavBars();
//
//	sortFrame.setElements();
//}
//
//
//void SortApp::setNavBars()
//{
//	// Set top navigation bar
//	topNavBar.setPosition(topNavBarPos);
//	topNavBar.setFillColor(theme);
//
//	// Calculate positions for text buttons
//	sf::Vector2f iniTopNavLine{(topNavBarSize.x - backBtnText.getLocalBounds().width
//												- insertionSortBtnText.getLocalBounds().width
//												- shellSortBtnText.getLocalBounds().width
//												- plusBtn.getGlobalBounds().width
//												- minusBtn.getGlobalBounds().width
//												- genNewArrBtnText.getLocalBounds().width) / 3.f
//												, (topNavBarSize.y - backBtnText.getLocalBounds().height) / 3.f };
//	sf::Vector2f backBtnTextPos{ iniTopNavLine.y, iniTopNavLine.y };
//	sf::Vector2f insertionSortBtnTextPos{ iniTopNavLine.x + backBtnText.getLocalBounds().width + 5.f, iniTopNavLine.y };
//	sf::Vector2f shellSortBtnTextPos{ insertionSortBtnTextPos.x + insertionSortBtnText.getGlobalBounds().width + 45.f, iniTopNavLine.y };
//	sf::Vector2f genNewArrBtnTextPos{ (topNavBarSize.x - genNewArrBtnText.getLocalBounds().width - 15.f), iniTopNavLine.y - 10.f };
//	sf::Vector2f minusBtnPos{ genNewArrBtnTextPos.x - minusBtn.getGlobalBounds().width - 35.f, iniTopNavLine.y - 20.f };
//	sf::Vector2f plusBtnPos{ minusBtnPos.x - plusBtn.getGlobalBounds().width - 5.f, minusBtnPos.y };
//
//	// Set text buttons
//	backBtnText.setPosition(backBtnTextPos);
//	insertionSortBtnText.setPosition(insertionSortBtnTextPos);
//	shellSortBtnText.setPosition(shellSortBtnTextPos);
//	genNewArrBtnText.setPosition(genNewArrBtnTextPos);
//	minusBtn.setPosition(minusBtnPos);
//	plusBtn.setPosition(plusBtnPos);
//
//	// Set bottom navigation bar
//	btmNavBar.setPosition(btmNavBarPos);
//	btmNavBar.setFillColor(theme);
//}
//
//// Handles pause state
//void SortApp::handlePause()
//{
//	while (pauseIndicator.isPaused()) {
//		while (targetWindow.pollEvent(event))
//		{
//			switch (event.type) {
//
//				// handles window close event
//			case sf::Event::Closed:
//				targetWindow.close();
//				break;
//
//			case sf::Event::KeyPressed:
//				switch (event.key.code)
//				{
//				case sf::Keyboard::P:
//					pauseIndicator.reverseState();
//					pauseIndicator.updateIcon();
//					break;
//
//				}
//				break;
//
//			}
//		}
//	}
//}
//
//
//void SortApp::updateEvents() 
//{
//	while (targetWindow.pollEvent(event)) 
//	{
//		switch (event.type) {
//
//			// handles window close event
//			case sf::Event::Closed:
//				targetWindow.close();
//				break;
//
//			case sf::Event::KeyPressed:
//				switch (event.key.code)
//				{
//
//					// Shortcuts :- 
//					// I -> Insertion Sort Visualization
//					// S -> Shell Sort Visualization
//
//				case sf::Keyboard::I:
//					sortFrame.visualizeInsertion();
//					break;
//
//
//				case sf::Keyboard::S:
//					sortFrame.visualizeShellSort();
//					break;
//
//				case sf::Keyboard::P:
//					pauseIndicator.reverseState();
//					pauseIndicator.updateIcon();
//					handlePause();
//					break;
//
//				}
//				break;
//				
//		}
//	}
//}
//
//void SortApp::update()
//{
//	updateEvents();
//	pauseIndicator.updateIcon();
//}
//
//
//
//void SortApp::renderNavBar()
//{
//	targetWindow.draw(topNavBar);
//
//	targetWindow.draw(backBtnText);
//	targetWindow.draw(insertionSortBtnText);
//	targetWindow.draw(shellSortBtnText);
//	targetWindow.draw(plusBtn);
//	targetWindow.draw(minusBtn);
//	targetWindow.draw(genNewArrBtnText);
//
//	targetWindow.draw(btmNavBar);
//}
//
//// Draws all App Components on window
//void SortApp::render() 
//{
//	targetWindow.clear(sf::Color::Cyan);
//
//	renderNavBar();
//	pauseIndicator.renderOn(targetWindow);
//
//	sortFrame.render();
//
//	targetWindow.display();
//}
