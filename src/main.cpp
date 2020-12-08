#include "Application.hpp"


int main()
{
	sf::RenderWindow window(SCR_DIMENSIONS, "Visualizer", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	Application app = Application(window);

	while (window.isOpen()) 
	{
		app.update();

		app.render();

	}

}