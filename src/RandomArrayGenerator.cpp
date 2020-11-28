#include "stdafx.hpp"

#include "RandomArrayGenerator.hpp"

std::array<Element, ARR_SIZE> &RandomArrayGenerator::randomize() 
{
	std::srand(unsigned(std::time(nullptr)));

	for (unsigned i{ 0 }; i < ARR_SIZE; i++) {
		elements[i].setValue(5 + std::rand() % RANGE);
		elements[i].setColor(unsortedElementsColor);
	}

	return elements;
}