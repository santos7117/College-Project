#pragma once

#ifndef _config_CPP
#define _config_CPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "ResourceHolder.cpp"



// Screen Configurations
const unsigned SCR_WIDTH = 1600;
const unsigned SCR_HEIGHT = 900;
const sf::VideoMode SCR_DIMENSIONS = sf::VideoMode(SCR_WIDTH, SCR_HEIGHT);




// SortFrame Configuration
const static unsigned gaps[6] = { /*701, 301,*/ 132, 57, 23, 10, 4, 1 };

const sf::Vector2f mFramePos = sf::Vector2f(0, 150);
const sf::Vector2f mFrameSize = sf::Vector2f(1600, 600);
const sf::Vector2f baseLinePos = sf::Vector2f(mFramePos.x, mFramePos.y);
const sf::Vector2f baseLineSize = sf::Vector2f(mFrameSize.x, 5);
const sf::Color mFrameColor = sf::Color(211, 211, 211);
const sf::Color baseLineColor = sf::Color(192, 192, 192);
const sf::Color unsortedElementsColor = sf::Color(169, 169, 169);



// Array Constants
const size_t ARR_SIZE = 150;
const unsigned RANGE = 500;



// Resource Holders
const ResourceHolder rsc;



















#endif