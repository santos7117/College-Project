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
	window.setFramerateLimit(10);
	//sf::Event event;
	//PausePlayIndicator pauseIndicator;
	SortApp app = SortApp(window);
	//MainMenu menu = MainMenu(window);

	while (window.isOpen()) 
	{
		app.update();

		app.render();

	}

}