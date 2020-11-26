//#include "../stdafx.hpp"
#pragma once

//#ifndef _SPLASH_SCREEN_CPP
//#define _SPLASH_SCREEN_CPP


#include "../config.cpp"

class SplashScreen {
private:
	sf::Event splashEvent;
	sf::RenderWindow& target;
	sf::Sprite splashBackground;

public:
	SplashScreen(sf::RenderWindow& _window) :
		target{_window},
		splashBackground{rsc.splashScreenTexture}
	{
		splashBackground.setPosition(-3600.f, -1700.f);
		splashBackground.setScale(11.f, 7.0f);

	}

	void updateEvents() {
		while (target.pollEvent(splashEvent)) {
			switch (splashEvent.type) {
				case sf::Event::Closed:
					target.close();
					break;
				
				case sf::Event::KeyPressed:
					if (splashEvent.key.code == sf::Keyboard::Space)
						target.close();
					break;
				}

		}

	}

	void play() {
		target.clear();

		target.draw(splashBackground);

		target.display();
	}

};




//#endif