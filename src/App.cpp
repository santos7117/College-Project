#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include "UI/SortFrameRenderer.cpp"



class App {
private:
	sf::RenderWindow window;
	sf::Event event;
	SortFrameRenderer sortFrame;
	bool isPaused;


	// Draws all App Components on window
	void drawComponents() {
		sortFrame.drawOn(window);
	}



public:

	// Constructor
	App() :
		sortFrame(window)
	{

	}

	void init() {
		window.create(SCR_DIMENSIONS, "Visualizer", SCR_STYLE);
		window.setFramerateLimit(30);

		isPaused = 0;
	}


	void processAppEvents() {
		while (window.pollEvent(event)) {
			switch (event.type) {

			// handles window close event
			case sf::Event::Closed:
				window.close();
				break;

			// handles shortcut events
			case sf::Event::KeyPressed:
				switch (event.key.code) {

					// Shortcuts :- 
					// I -> Insertion Sort Visualization
					// S -> Shell Sort Visualization

					case sf::Keyboard::I:
						sortFrame.visualizeInsertion();
						break;


					case sf::Keyboard::S:
						sortFrame.visualizeShellSort();
						break;

					case sf::Keyboard::P:
						isPaused = !isPaused;
						pause();
						break;

				}
			}
		}
	}

	// Handles pause state
	void pause() {
		while (isPaused) {
			processAppEvents();
		}
	}

	// Runs App instance
	void run() {
		init();

		//sf::CircleShape circle(10);
		//circle.setPosition(100.f, 100.f);
		//circle.setFillColor(sf::Color::White);

		while (window.isOpen()) {
			processAppEvents();

			window.clear();
			//window.draw(circle);
			//circle.move(5.f, 5.f);

			drawComponents();

			window.display();
		}
	}



};