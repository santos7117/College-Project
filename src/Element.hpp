#pragma once

#ifndef ELEMENT_CPP
#define ELEMENT_CPP


#include "config.hpp"


class Element {
private:

	short unsigned value;
	sf::RectangleShape rect;
	sf::Text label;



public:

	// Constructor
	Element();


	// Sets rectangle's position and size for the element
	void setRect(const float& _x_pos, const float& _y_pos, const float& _width);

	// Moves element with given offsets
	void move(const float& offsetX, const float& offsetY);

	// Sets color of element and element's rectangle
	void setColor(const sf::Color& _color);

	// Sets value for the element
	void setValue(const short unsigned& _val);

	// Returns value of the element
	unsigned getValue() const;


	// Returns X position of the element
	float getXPos() const;

	// Draws element with label on window
	void drawOn(sf::RenderWindow& window) const;

	friend bool operator >  (Element& leftElem, Element& rightElem) { return leftElem.value >  rightElem.value; }

	friend bool operator >= (Element& leftElem, Element& rightElem) { return leftElem.value >= rightElem.value; }

	friend bool operator <  (Element& leftElem, Element& rightElem) { return leftElem.value <  rightElem.value; }

	friend bool operator <= (Element& leftElem, Element& rightElem) { return leftElem.value <= rightElem.value; }
};

#endif