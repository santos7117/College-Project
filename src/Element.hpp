#pragma once

#ifndef ELEMENT_CPP
#define ELEMENT_CPP


#include "config.hpp"


class Element {
private:

	unsigned value;
	sf::RectangleShape rect;
	sf::Text label;
	sf::Color color;



public:

	// Constructor
	Element();

	// Copy Constructor
	//Element(const Element& other) : 
	//	value(other.value), rect(other.rect), label(other.label), color(other.color)
	//{	}



	// Sets rectangle's position and size for the element
	void setRect(const float& _x_pos, const float& _y_pos, const float& _width);

	// Moves element
	void move(float& offsetX, float& offsetY);

	// Sets color of element and element's rectangle
	void setColor(sf::Color _color = sf::Color::Blue);

	// Sets value for the element
	void setValue(unsigned _val);

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