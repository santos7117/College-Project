#include "../stdafx.hpp"

#include "Button.hpp"

Button::Button(const sf::String& string, const sf::Font& font, unsigned int characterSize = 30) :
	btnState{ BTN_IDLE },
	btnTitle{ string, font, characterSize }
{

}

void Button::setPosition(const float& _x, const float& _y)
{
	btnTitle.setPosition(_x, _y);
}

void Button::setState(const enum BTN_STATE& _state) { btnState = _state; }

void Button::updateBtnUI()
{
	switch (btnState)
	{
	case BTN_IDLE:
		btnTitle.setScale(1.f, 1.f);
		break;
	case BTN_HOVERED:
		btnTitle.setScale(1.2f, 1.1f);
		break;
	case BTN_CLICKED:
		btnTitle.setScale(1.f, 1.f);
	default:
		break;
	}
}

bool Button::onClick()
{
	if (btnState == BTN_CLICKED)
	{
		return 1;
	}
	return 0;
}

void Button::update(const float& _mouse_x, const float& _mouse_y)
{
	btnState = BTN_IDLE;

	if (btnTitle.getGlobalBounds().contains(_mouse_x, _mouse_y))
	{
		btnState = BTN_HOVERED;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			btnState = BTN_CLICKED;
		}
	}

	updateBtnUI();
}

void Button::renderOn(sf::RenderWindow& _window) const
{
	_window.draw(btnTitle);
}
