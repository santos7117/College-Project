#pragma once

#include "stdafx.hpp"

class ResourceHolder {
public:
	sf::Font menuFont;
	sf::Font elementNumFont;
	sf::Texture splashScreenTexture;
	sf::Texture mainmenuBackgroundTexture;


	ResourceHolder() {
		loadFontsAndTextures();
	}

	void loadFontsAndTextures() {
		splashScreenTexture.loadFromFile("./assets/pics/splashScreen.gif");
		mainmenuBackgroundTexture.loadFromFile("./assets/pics/background.jpg");

		menuFont.loadFromFile("./assets/fonts/sakuraBlossom.ttf");
		elementNumFont.loadFromFile("./assets/fonts/numDigitalMono.ttf");

	}
};