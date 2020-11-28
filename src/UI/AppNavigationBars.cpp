//#pragma once
//
//#include "../stdafx.hpp"
//#include "AppNavigationBars.hpp"
//
//
//
//AppNavigationBars::AppNavigationBars() :
//
//	// Member initializers
//
//	topNavBar{ topNavBarSize },
//
//	backBtn{ "Back"	  , rsc.menuFont, 50 },
//	insertionSortBtn{ "Insertion Sort", rsc.menuFont, 50 },
//	shellSortBtn{ "Shell Sort"  , rsc.menuFont, 50 },
//	plusBtn{ "+", rsc.menuFont, 90 },
//	minusBtn{ "-", rsc.menuFont, 90 },
//	genNewArrBtn{ "Generate New Arr"  , rsc.menuFont, 65 },
//
//	btmNavBar{ btmNavBarSize }
//{
//	setNavBars();
//}
//
//
//void AppNavigationBars::setNavBars()
//{
//	// Set top navigation bar
//	topNavBar.setPosition(topNavBarPos);
//	topNavBar.setFillColor(themeColor);
//
//	// Calculate positions for text buttons
//	sf::Vector2f iniTopNavLine{ (topNavBarSize.x - backBtn.getWidth()
//												- insertionSortBtn.getWidth()
//												- shellSortBtn.getWidth()
//												- plusBtn.getWidth()
//												- minusBtn.getWidth()
//												- genNewArrBtn.getWidth()) / 3.f
//												, (topNavBarSize.y - backBtn.getHeight()) / 5.f };
//	sf::Vector2f backBtnTextPos{ iniTopNavLine.y, iniTopNavLine.y };
//	sf::Vector2f insertionSortBtnTextPos{ iniTopNavLine.x + backBtn.getWidth() - 25.f, iniTopNavLine.y };
//	sf::Vector2f shellSortBtnTextPos{ insertionSortBtnTextPos.x + insertionSortBtn.getWidth() + 70.f, iniTopNavLine.y };
//	sf::Vector2f genNewArrBtnTextPos{ (topNavBarSize.x - genNewArrBtn.getWidth() - 85.f), iniTopNavLine.y - 15.f };
//	sf::Vector2f minusBtnPos{ genNewArrBtnTextPos.x - minusBtn.getWidth() - 35.f, iniTopNavLine.y - 20.f };
//	sf::Vector2f plusBtnPos{ minusBtnPos.x - plusBtn.getWidth() - 8.f, minusBtnPos.y };
//
//	// Set text buttons
//	backBtn.setPosition(backBtnTextPos);
//	insertionSortBtn.setPosition(insertionSortBtnTextPos);
//	shellSortBtn.setPosition(shellSortBtnTextPos);
//	genNewArrBtn.setPosition(genNewArrBtnTextPos);
//	minusBtn.setPosition(minusBtnPos);
//	plusBtn.setPosition(plusBtnPos);
//
//	// Set bottom navigation bar
//	btmNavBar.setPosition(btmNavBarPos);
//	btmNavBar.setFillColor(themeColor);
//}
//
//
//void AppNavigationBars::updateMouseEvents()
//{
//	float mouseX = (float)sf::Mouse::getPosition(SortApp::targetWindow).x;
//	float mouseY = (float)sf::Mouse::getPosition(targetWindow).y;
//
//	backBtn.update(mouseX, mouseY);
//	insertionSortBtn.update(mouseX, mouseY);
//	shellSortBtn.update(mouseX, mouseY);
//	plusBtn.update(mouseX, mouseY);
//	minusBtn.update(mouseX, mouseY);
//	genNewArrBtn.update(mouseX, mouseY);
//
//	if (backBtn.onClick()) {
//		targetWindow.close();
//	}
//
//	if (insertionSortBtn.onClick()) {
//		SortApp::visualizeInsertion();
//	}
//
//	if (shellSortBtn.onClick()) {
//		sortFrame.visualizeShellSort();
//	}
//
//	if (plusBtn.onClick()) {
//		sortFrame.inrElements();
//	}
//
//	if (minusBtn.onClick()) {
//		sortFrame.dcrElements();
//	}
//
//	if (genNewArrBtn.onClick()) {
//		sortFrame.randomize();
//	}
//}