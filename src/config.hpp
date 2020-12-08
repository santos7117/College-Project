#pragma once

#ifndef _config_HPP
#define _config_HPP

#include "stdafx.hpp"

#include "ResourceHolder.hpp"



// Screen Configurations
const unsigned short SCR_WIDTH = 1600;
const unsigned short SCR_HEIGHT = 900;
const sf::VideoMode SCR_DIMENSIONS = sf::VideoMode(SCR_WIDTH, SCR_HEIGHT);



// Resource Holders
const ResourceHolder rsc;




// App Configuration
const unsigned short int SHELL_GAPS[6] = { /*701, 301,*/ 132, 57, 23, 10, 4, 1 };

const sf::Color themeColor = sf::Color(52, 80, 92);
	
	// Top Navigation Bar
	const sf::Vector2f topNavBarPos  = sf::Vector2f(0.f, 0.f);
	const sf::Vector2f topNavBarSize = sf::Vector2f(SCR_WIDTH, 50.f);


	// SortFrame Configuration
	const short unsigned normalZoomFactor = 1100;

	const sf::Vector2f framePos  = sf::Vector2f(0, topNavBarPos.y + topNavBarSize.y);
	const sf::Vector2f frameSize = sf::Vector2f(SCR_WIDTH, 800.f);
	const sf::Color frameBorderColor = sf::Color(192, 192, 225);
	const sf::Vector2f subFrameSize = sf::Vector2f(frameSize/2.f);
	const sf::Color leftUnsortedColor = sf::Color(190, 191, 88);
	const sf::Color rightUnsortedColor = sf::Color(204, 86, 86);
	const sf::Color iniSortedColor = sf::Color(62, 150, 0);
	const sf::Color sortedColor	 = sf::Color(124, 255, 0);
	const sf::Color unsortedColor = sf::Color(169, 169, 169);
	const sf::Color gapSortedColor = sf::Color(64, 128, 0);


	// Bottom Navigation Bar
	const sf::Vector2f btmNavBarPos =  sf::Vector2f(0, topNavBarSize.y + frameSize.y);
	const sf::Vector2f btmNavBarSize = sf::Vector2f(SCR_WIDTH, 50.f);


// Array Constants
const unsigned short ARR_SIZE = 100;
const unsigned short RANGE = 550;

#endif