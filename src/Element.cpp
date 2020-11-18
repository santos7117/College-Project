#pragma once

#ifndef ELEMENT_CPP
#define ELEMENT_CPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "resourceHolder.cpp"


const ResourceHolder rsc;

class Element {
private:

	unsigned value;
	sf::RectangleShape rect;
	sf::Text label;
	sf::Color color;



public:
	Element() {
		setColor();
	}

	//Element(const Element& other) : 
	//	value(other.value), rect(other.rect), label(other.label), color(other.color)
	//{	}


	void setRect(const float &_x_pos, const float &_y_pos, const float &_width) {
		rect.setPosition(_x_pos, _y_pos);
		rect.setSize(sf::Vector2f(_width, float(value)));

		//label.setFont(rsc.elementNumFont);
		//label.setString(value);
		//label.setPosition(_x_pos, _y_pos + value);
		//label.setCharacterSize(50);
	}

	void move(float offsetX, float offsetY) {
		rect.move(offsetX, offsetY);
	}

	void setColor(sf::Color _color = sf::Color::Blue) {
		color = _color;
		rect.setFillColor(_color);
	}

	void setValue(unsigned _val) {
		value = _val;
	}

	unsigned getValue() {
		return value;
	}

	float getXPos() {
		return rect.getPosition().x;
	}

	void drawOn(sf::RenderWindow& window) const{
		window.draw(rect);
		//window.draw(label);
	}

	friend bool operator > (Element &leftElem, Element &rightElem);
	friend bool operator >= (Element &leftElem, Element &rightElem);
	friend bool operator < (Element &leftElem, Element &rightElem);
	friend bool operator <= (Element &leftElem, Element &rightElem);
};

//bool operator > (Element &leftElem, Element &rightElem) {
//	return leftElem.value > rightElem.value;
//}
//
//bool operator >= (Element &leftElem, Element &rightElem) {
//	return leftElem.value >= rightElem.value;
//}
//
//bool operator < (Element &leftElem, Element &rightElem) {
//	return leftElem.value < rightElem.value;
//}
//
//bool operator <= (Element &leftElem, Element &rightElem) {
//	return leftElem.value <= rightElem.value;
//}



#endif