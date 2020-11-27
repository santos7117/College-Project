#pragma once 

#ifndef _PAUSE_INDICATOR_CPP
#define _PAUSE_INDICATOR_CPP

#include "../config.hpp"
#include "../ResourceHolder.hpp"

class PauseIndicator
{
private:
	sf::Sprite sprite;
	bool pauseStatus;

public:
	PauseIndicator();

	void setState(const bool& _state);

	void reverseState();

	constexpr bool isPaused() const;

	void updateIcon();

	void renderOn(sf::RenderWindow& _window) const;
};



#endif