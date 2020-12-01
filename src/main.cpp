//#include "stdafx.hpp"
//#include <iostream>
//#include "config.hpp"
//#include "./UI/PausePlayIndicator.cpp"
#include "SortApp.hpp"
//#include "./UI/MainMenu.hpp"
//#include "./UI/SplashScreen.cpp"


int main()
{
	sf::RenderWindow window(SCR_DIMENSIONS, "Visualizer");
	window.setFramerateLimit(100);
	//sf::Event event;
	Application app = Application(window);
	//MainMenu menu = MainMenu(window);

	while (window.isOpen()) 
	{
		app.update();

		app.render();

	}

}