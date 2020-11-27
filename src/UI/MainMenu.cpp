#include "../stdafx.hpp"

#include "MainMenu.hpp"


MainMenu::MainMenu(sf::RenderWindow& _window) :
	targetWindow{_window},

	background{rsc.mainmenuBackgroundTexture},

	appTitleText  {		 "VISUALIZER"	 , rsc.menuFont, 150 },
	sortOptionText{ "Sort  Visualization", rsc.menuFont,  80 },
	treeOptionText{ "Tree  Visualization", rsc.menuFont,  80 },
	exitOptionText{			"Exit"		 , rsc.menuFont, 100 }
{
	setUp();
}


void MainMenu::setUp() 
{
	background.setPosition(0.f, 0.f);
	background.setScale(0.55f, 0.5f);

	appTitleText.setFont  (rsc.menuFont);
	sortOptionText.setFont(rsc.menuFont);
	treeOptionText.setFont(rsc.menuFont);
	exitOptionText.setFont(rsc.menuFont);

	appTitleText.setPosition  ((SCR_WIDTH - appTitleText.getLocalBounds().width) / 2.f  ,  50.f);
	sortOptionText.setPosition((SCR_WIDTH - sortOptionText.getLocalBounds().width) / 2.f, 300.f);
	treeOptionText.setPosition((SCR_WIDTH - treeOptionText.getLocalBounds().width) / 2.f, 400.f);
	exitOptionText.setPosition((SCR_WIDTH - exitOptionText.getLocalBounds().width) / 2.f, 750.f);
}

void MainMenu::updateMouseEvents() 
{
	float mouseX = float(sf::Mouse::getPosition(targetWindow).x);
	float mouseY = float(sf::Mouse::getPosition(targetWindow).y);

	if (sortOptionText.getGlobalBounds().contains(mouseX, mouseY)) 
	{
		sortOptionText.setScale(1.1f, 1.1f);

		if (mainMenuEvent.type == sf::Mouse::Left) {
			targetWindow.close();
		}
	}
	else
		sortOptionText.setScale(1.f, 1.f);

	if (treeOptionText.getGlobalBounds().contains(mouseX, mouseY)) 
	{
		treeOptionText.setScale(1.1f, 1.1f);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			targetWindow.close();
		}
	}
	else
		treeOptionText.setScale(1.f, 1.f);

	if (exitOptionText.getGlobalBounds().contains(mouseX, mouseY)) 
	{
		exitOptionText.setScale(1.1f, 1.1f);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			targetWindow.close();
		}
	}
	else
		exitOptionText.setScale(1.f, 1.f);
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
	targetWindow.clear();

	targetWindow.draw(background);

	targetWindow.draw(appTitleText);
	targetWindow.draw(sortOptionText);
	targetWindow.draw(treeOptionText);
	targetWindow.draw(exitOptionText);

	targetWindow.display();
}
};
