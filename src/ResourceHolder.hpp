#pragma once


#ifndef _RESOURCE_HOLDER_CPP
#define _RESOURCE_HOLDER_CPP

class ResourceHolder
{
public:
	sf::Font menuFont;
	sf::Font elementNumFont;
	sf::Texture splashScreenTexture;
	sf::Texture mainmenuBackgroundTexture;
	sf::Texture pauseIcon;
	sf::Texture playIcon;


	ResourceHolder();

	void loadFontsAndTextures();
};

#endif