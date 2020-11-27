#pragma once

#ifndef _SPLASH_SCREEN_CPP
#define _SPLASH_SCREEN_CPP


#include "../config.hpp"


class SplashScreen 
{
private:
	sf::Event splashEvent;
	sf::RenderWindow& target;
	sf::Sprite splashBackground;

public:
	SplashScreen(sf::RenderWindow& _window);

	void updateEvents();

	void play();

};


#endif