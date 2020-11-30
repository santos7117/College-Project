#include "stdafx.hpp"

#include "Element.hpp"


Element::Element() 
{
	setColor(unsortedColor);
}


// Sets rectangle's position and size for the element
void Element::setRect(const float &_x_pos, const float &_y_pos, const float &_width) 
{
	rect.setPosition(_x_pos, _y_pos);
	rect.setSize(sf::Vector2f(_width, float(value)));

	label.setFont(rsc.elementNumFont);
	label.setString(std::to_string(value));
	label.setCharacterSize(unsigned(_width/1.5));
	label.setPosition(_x_pos+(_width-label.getGlobalBounds().width)/2, rect.getPosition().y + rect.getGlobalBounds().height);
}


// Moves element
void Element::move(const float& offsetX, const float& offsetY) 
{	
	rect.move(offsetX, offsetY);
	label.move(offsetX, offsetY);
}


// Sets color of element and element's rectangle
void Element::setColor(const sf::Color& _color = unsortedColor) {
	rect.setFillColor(_color);
	label.setFillColor(_color);
}


// Sets value for the element
void Element::setValue(const short unsigned& _val) {	value = _val;	}


// Returns value of the element
unsigned Element::getValue() const {	return value;	}


// Returns X position of the element
float Element::getXPos() const {	return rect.getPosition().x;	}


// Draws element with label on window
void Element::drawOn(sf::RenderWindow& window) const{
	window.draw(rect);
	window.draw(label);
}