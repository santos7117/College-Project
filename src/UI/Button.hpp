#pragma once

#ifndef _BUTTON_HPP
#define _BUTTON_HPP



const enum BTN_STATE { BTN_IDLE, BTN_HOVERED, BTN_CLICKED };

// Expands sf::Text class to be utilizedas Button
class Button
{

public:

	// Initializes sf::Text
	Button(const sf::String& string, const sf::Font& font, unsigned int characterSize);

	// Sets Position of Button on Screen
	void setPosition(const float& _x, const float& _y);

	void setPosition(const sf::Vector2f& _pos);

	//void setState(const enum BTN_STATE& _state);

	float getWidth() const;

	float getHeight() const;

	// Handles click event
	// \return True if Button is clicked
	bool onClick();

	// Updates Button states
	void update(const float& _mouse_x, const float& _mouse_y);

	void renderOn(sf::RenderWindow& _window) const;


private:
	short unsigned btnState;
	sf::Text btnTitle;

	void updateBtnUI();
};

#endif