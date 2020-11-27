#pragma once

#ifndef _BUTTON_HPP
#define _BUTTON_HPP



const enum BTN_STATE { BTN_IDLE, BTN_HOVERED, BTN_CLICKED };

class Button
{
private:
	short unsigned btnState;
	sf::Text btnTitle;

public:
	Button(const sf::String& string, const sf::Font& font, unsigned int characterSize);

	void setPosition(const float& _x, const float& _y);

	void setState(const enum BTN_STATE& _state);

	void updateBtnUI();

	bool onClick();

	void update(const float& _mouse_x, const float& _mouse_y);

	void renderOn(sf::RenderWindow& _window) const;
};

#endif