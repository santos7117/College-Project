#pragma once

#ifndef _config_HPP
#define _config_HPP

#include "stdafx.hpp"

#include "ResourceHolder.hpp"



// Screen Configurations
const static unsigned SCR_WIDTH = 1600;
const static unsigned SCR_HEIGHT = 900;
const static sf::VideoMode SCR_DIMENSIONS = sf::VideoMode(SCR_WIDTH, SCR_HEIGHT);



// Resource Holders
const static ResourceHolder rsc;




// App Configuration
const static unsigned SHELL_GAPS[6] = { /*701, 301,*/ 132, 57, 23, 10, 4, 1 };

const static sf::Color themeColor = sf::Color(52, 80, 92);
	
	// Top Navigation Bar
	const static sf::Vector2f topNavBarPos  = sf::Vector2f(0.f, 0.f);
	const static sf::Vector2f topNavBarSize = sf::Vector2f(SCR_WIDTH, 100.f);


	// SortFrame Configuration
	const static unsigned zoomFactor = 1100;

	const static sf::Vector2f framePos  = sf::Vector2f(0, topNavBarPos.y + topNavBarSize.y);
	const static sf::Vector2f frameSize = sf::Vector2f(SCR_WIDTH, 740.f);
	const static sf::Color frameBorderColor = sf::Color(192, 192, 225);
	const static sf::Color leftUnsortedColor = sf::Color(190, 191, 88);
	const static sf::Color rightUnsortedColor = sf::Color(204, 86, 86);
	const static sf::Color iniSortedColor = sf::Color(62, 150, 0);
	const static sf::Color sortedColor	 = sf::Color(124, 255, 0);
	const static sf::Color unsortedColor = sf::Color(169, 169, 169);
	const static sf::Color gapSortedColor = sf::Color(64, 128, 0);


	// Bottom Navigation Bar
	const static sf::Vector2f btmNavBarPos =  sf::Vector2f(0, topNavBarSize.y + frameSize.y);
	const static sf::Vector2f btmNavBarSize = sf::Vector2f(SCR_WIDTH, 60.f);


// Array Constants
const static size_t ARR_SIZE = 100;
const static unsigned RANGE = 550;

#endif