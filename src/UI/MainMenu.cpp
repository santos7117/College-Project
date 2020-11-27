#include "../stdafx.hpp"

#include "MainMenu.hpp"


MainMenu::MainMenu(sf::RenderWindow& _window) :
	targetWindow{_window},

	background{rsc.mainmenuBackgroundTexture},

	appTitleText  {		 "VISUALIZER"	 , rsc.menuFont, 170 },
	sortOption{ "Sort  Visualization", rsc.menuFont,  80 },
	treeOption{ "Tree  Visualization", rsc.menuFont,  80 },
	exitOption{			"Exit"		 , rsc.menuFont, 100 }
{
	setUp();
}


void MainMenu::setUp() 
{
	background.setPosition(0.f, 0.f);
	background.setScale(0.57f, 0.5f);

	appTitleText.setPosition  ((SCR_WIDTH - appTitleText.getGlobalBounds().width) / 2.f  ,  50.f);
	sortOption.setPosition((SCR_WIDTH - sortOption.getWidth()) / 2.f, 300.f);
	treeOption.setPosition((SCR_WIDTH - treeOption.getWidth()) / 2.f, 400.f);
	exitOption.setPosition((SCR_WIDTH - exitOption.getWidth()) / 2.f, 750.f);
}

void MainMenu::updateMouseEvents() 
{
	float mouseX = float(sf::Mouse::getPosition(targetWindow).x);
	float mouseY = float(sf::Mouse::getPosition(targetWindow).y);

	sortOption.update(mouseX, mouseY);
	treeOption.update(mouseX, mouseY);
	exitOption.update(mouseX, mouseY);

	if (sortOption.onClick())
		targetWindow.close();
}

void MainMenu::updateEvents() 
{
	while (targetWindow.pollEvent(mainMenuEvent)) {
		switch (mainMenuEvent.type) {
			case sf::Event::Closed :
				targetWindow.close();
				break;

			case sf::Event::MouseMoved:
				updateMouseEvents();
				break;
		}
	}
}

void MainMenu::render() 
{
	targetWindow.clear(sf::Color::Cyan);

	targetWindow.draw(background);

	targetWindow.draw(appTitleText);
	sortOption.renderOn(targetWindow);
	treeOption.renderOn(targetWindow);
	exitOption.renderOn(targetWindow);

	targetWindow.display();
}