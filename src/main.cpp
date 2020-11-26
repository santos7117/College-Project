#include "stdafx.hpp"

#include "SortApp.cpp"
//#include "./UI/MainMenu.cpp"
//#include "./UI/SplashScreen.cpp"




int main()
{
	sf::RenderWindow window(SCR_DIMENSIONS, "Visualizer");
	window.setFramerateLimit(10);
	SortApp app = SortApp(window);

	while (window.isOpen()) 
	{
		app.update();

		app.render();

	}

}