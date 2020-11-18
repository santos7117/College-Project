#pragma once

#include<SFML/Graphics/Font.hpp>

class ResourceHolder {
public:
	sf::Font menuFont;
	sf::Font elementNumFont;


	ResourceHolder() {
		//menuFont.loadFromFile("../assets/sakuraBlossom.ttf");
		//elementNumFont.loadFromFile("../assets/numDigitalMono.ttf");
	}

};