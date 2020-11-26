#pragma once

#ifndef ELEMENT_CPP
#define ELEMENT_CPP

#include "stdafx.hpp"

#include "config.cpp"


class Element {
private:

	unsigned value;	
	sf::RectangleShape rect;
	sf::Text label;
	sf::Color color;



public:

	// Constructor
	Element() 
	{
	}

	// Copy Constructor
	//Element(const Element& other) : 
	//	value(other.value), rect(other.rect), label(other.label), color(other.color)
	//{	}



	// Sets rectangle's position and size for the element
	void setRect(const float &_x_pos, const float &_y_pos, const float &_width) {
		rect.setPosition(_x_pos, _y_pos);
		rect.setSize(sf::Vector2f(_width, float(value)));

		label.setFont(rsc.elementNumFont);
		label.setString(std::to_string(value));
		label.setCharacterSize(unsigned(_width/1.5));
		label.setPosition(_x_pos+(_width-label.getGlobalBounds().width)/2, rect.getPosition().y + rect.getGlobalBounds().height);
	}

	// Moves element
	void move(float offsetX, float offsetY) {
		rect.move(offsetX, offsetY);
	}

	// Sets color of element and element's rectangle
	void setColor(sf::Color _color = sf::Color::Blue) {
		color = _color;
		rect.setFillColor(_color);
		label.setFillColor(_color);
	}

	// Sets value for the element
	void setValue(unsigned _val) {
		value = _val;
	}

	// Returns value of the element
	unsigned getValue() {
		return value;
	}


	// Returns X position of the element
	float getXPos() {
		return rect.getPosition().x;
	}

	// Draws element with label on window
	void drawOn(sf::RenderWindow& window) const{
		window.draw(rect);
		window.draw(label);
	}

	friend bool operator >  (Element& leftElem, Element& rightElem) 
	{
		return leftElem.value > rightElem.value;
	}

	friend bool operator >= (Element &leftElem, Element &rightElem)
	{
		return leftElem.value >= rightElem.value;
	}

	friend bool operator <  (Element &leftElem, Element &rightElem)
	{
		return leftElem.value < rightElem.value;
	}

	friend bool operator <= (Element &leftElem, Element &rightElem)
	{
		return leftElem.value <= rightElem.value;
	}
};


#endif