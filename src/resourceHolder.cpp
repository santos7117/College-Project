#include "stdafx.hpp"

#include "ResourceHolder.hpp"


ResourceHolder::ResourceHolder() 
{
	loadFontsAndTextures();
}


void ResourceHolder::loadFontsAndTextures() 
{
	splashScreenTexture.loadFromFile("./assets/pics/splashScreen.gif");
	mainmenuBackgroundTexture.loadFromFile("./assets/pics/background.jpg");
	pauseIcon.loadFromFile("./assets/pics/pauseBtnIcon.png");
	playIcon.loadFromFile("./assets/pics/playBtnIcon.png");

	menuFont.loadFromFile("./assets/fonts/sakuraBlossom.ttf");
	elementNumFont.loadFromFile("./assets/fonts/numDigitalMono.ttf");

}