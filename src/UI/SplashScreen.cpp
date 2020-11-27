#include "../stdafx.hpp"

#include "SplashScreen.hpp"


SplashScreen::SplashScreen(sf::RenderWindow& _window) :
	target{_window},
	splashBackground{rsc.splashScreenTexture}
{
	splashBackground.setPosition(-3600.f, -1700.f);
	splashBackground.setScale(11.f, 7.0f);

}

void SplashScreen::updateEvents() {
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

void SplashScreen::play() {
	target.clear();

	target.draw(splashBackground);

	target.display();
}