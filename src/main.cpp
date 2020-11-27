#include "stdafx.hpp"

//#include "config.hpp"
//#include "./UI/PausePlayIndicator.cpp"
#include "SortApp.cpp"
//#include "./UI/MainMenu.cpp"
//#include "./UI/SplashScreen.cpp"





int main()
{
	sf::RenderWindow window(SCR_DIMENSIONS, "Visualizer");
	//sf::Event event;
	//PausePlayIndicator pauseIndicator;
	window.setFramerateLimit(10);
	SortApp app = SortApp(window);


	while (window.isOpen()) 
	{


		app.update();

		app.render();

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