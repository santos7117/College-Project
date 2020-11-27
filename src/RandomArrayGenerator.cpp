#pragma once

#include "stdafx.hpp"

#include "Element.cpp"

class RandomArrayGenerator {

private:

	// <!-- TODO : Make shared_ptr >
	std::array <Element, ARR_SIZE> elements;


public:

	// Returns array of elements with random values
	std::array<Element, ARR_SIZE> randomize() 
	{
		std::srand(unsigned(std::time(nullptr)));

		for (unsigned i{ 0 }; i < elements.size(); i++) {
			elements[i].setValue(5 + std::rand() % RANGE);
		}

		return elements;
	}

};

