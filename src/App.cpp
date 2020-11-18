#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include "UI/SortFrameRenderer.cpp"


const unsigned SCR_WIDTH = 1600;
const unsigned SCR_HEIGHT = 900;
const sf::VideoMode SCR_DIMENSIONS = sf::VideoMode(SCR_WIDTH, SCR_HEIGHT);



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

	void init() {
		window.create(SCR_DIMENSIONS, "Visualizer"/*, sf::Style::Fullscreen*/);
		window.setFramerateLimit(1);
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

					case sf::Keyboard::S:
						sortFrame.visualizeShellSort();

					case sf::Keyboard::P:
						isPaused ? resume() : pause();

				}
			}
		}
	}

	// Handles pause state
	void pause() {

	}

	// Resumes the App
	void resume() {

	}

	// Runs App instance
	void run() {
		init();

		while (window.isOpen()) {
			processAppEvents();

			drawComponents();
			//sortFrame.visualizeInsertion();


			window.display();
		}
	}



};