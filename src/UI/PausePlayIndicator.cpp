#pragma once

#ifndef _PAUSE_PLAY_INDICATOR_CPP
#define _PAUSE_PLAY_INDICATOR_CPP

#include "../config.cpp"
#include "../resourceHolder.cpp"

class PauseIndicator
{
private:
	sf::Sprite sprite;
	bool pauseStatus;

public:
	PauseIndicator() :

		// Member Initializers
		sprite{rsc.pauseIcon},
		pauseStatus{ 0 }
	{
		sprite.setPosition((SCR_WIDTH - 50) / 2.f, btmNavBarPos.y + 5);
	}

	void setState(const bool& _state) {	pauseStatus = _state; }

	void reverseState() { pauseStatus = !pauseStatus; }

	constexpr bool isPaused() const { return pauseStatus; }

	void updateIcon() {
		if (pauseStatus)
			// render play icon when paused
			sprite.setTexture(rsc.playIcon);
		else
			// render pause icon when unpaused
			sprite.setTexture(rsc.pauseIcon);
	}

	void renderOn(sf::RenderWindow& _window) const {	
		_window.draw(sprite);
	}
};

#endif