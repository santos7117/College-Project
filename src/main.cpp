//#include "stdafx.hpp"
//#include <iostream>
//#include "config.hpp"
//#include "./UI/PausePlayIndicator.cpp"
//#include "SortApp.cpp"
#include "./UI/MainMenu.hpp"
//#include "./UI/SplashScreen.cpp"


int main()
{
	sf::RenderWindow window(SCR_DIMENSIONS, "Visualizer");
	window.setFramerateLimit(10);
	sf::Event event;
	//PausePlayIndicator pauseIndicator;
	//SortApp app = SortApp(window);
	float mouseX, mouseY;

	MainMenu menu(window);


	while (window.isOpen()) 
	{

		menu.updateEvents();

		menu.render();

	}

}

//window.clear(sf::Color::Cyan);
//
//
//pauseIndicator.renderOn(window);
//
//window.display();

//while (window.pollEvent(event))
//{
//	switch (event.type) {
//
//		// handles window close event
//	case sf::Event::Closed:
//		window.close();
//		break;
//
//	case sf::Event::KeyPressed:
//		switch (event.key.code)
//		{
//		case sf::Keyboard::P:
//			pauseIndicator.reverseState();
//			pauseIndicator.updateIcon();
//			while (pauseIndicator.isPaused()) {
//				while (window.pollEvent(event))
//				{
//					switch (event.type) {
//
//						// handles window close event
//					case sf::Event::Closed:
//						window.close();
//						break;
//
//					case sf::Event::KeyPressed:
//						switch (event.key.code)
//						{
//						case sf::Keyboard::P:
//							pauseIndicator.reverseState();
//							pauseIndicator.updateIcon();
//							break;
//
//						}
//						break;
//
//					}
//				}
//			}
//			break;
//
//		}
//		break;
//
//	}
//}