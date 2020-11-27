#pragma once

#include "stdafx.hpp"

class ResourceHolder 
{
public:
	sf::Font menuFont;
	sf::Font elementNumFont;
	sf::Texture splashScreenTexture;
	sf::Texture mainmenuBackgroundTexture;
	sf::Texture pauseIcon;
	sf::Texture playIcon;


	ResourceHolder() 
	{
		loadFontsAndTextures();
	}

	void loadFontsAndTextures() 
	{
		splashScreenTexture.loadFromFile("./assets/pics/splashScreen.gif");
		mainmenuBackgroundTexture.loadFromFile("./assets/pics/background.jpg");
		pauseIcon.loadFromFile("./assets/pics/pauseBtnIcon.png");
		playIcon.loadFromFile("./assets/pics/playBtnIcon.png");

		menuFont.loadFromFile("./assets/fonts/sakuraBlossom.ttf");
		elementNumFont.loadFromFile("./assets/fonts/numDigitalMono.ttf");

	}
};