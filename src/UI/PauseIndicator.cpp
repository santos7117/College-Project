#include "../stdafx.hpp"

#include "PauseIndicator.hpp"


PauseIndicator::PauseIndicator() :

	// Member Initializers
	sprite{rsc.pauseIcon},
	pauseStatus{ 0 }
{
	sprite.setPosition((SCR_WIDTH - 50) / 2.f, btmNavBarPos.y + 5);
}

void PauseIndicator::setState(const bool& _state) {	pauseStatus = _state; }

void PauseIndicator::reverseState() { pauseStatus = !pauseStatus; }

constexpr bool PauseIndicator::isPaused() const { return pauseStatus; }

void PauseIndicator::updateIcon() 
{
	if (pauseStatus)
		// render play icon when paused
		sprite.setTexture(rsc.playIcon);
	else
		// render pause icon when unpaused
		sprite.setTexture(rsc.pauseIcon);
}

void PauseIndicator::renderOn(sf::RenderWindow& _window) const 
{	
	_window.draw(sprite);
}
};