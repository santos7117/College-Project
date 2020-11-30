#include "stdafx.hpp"

#include "RandomArrayGenerator.hpp"

std::array<Element, ARR_SIZE> &RandomArrayGenerator::randomize(const short unsigned& _numOfElements = ARR_SIZE) 
{
	std::srand(short unsigned(std::time(nullptr)));

	for (unsigned i{ 0 }; i < _numOfElements; i++) {
		elements[i].setValue(5 + std::rand() % RANGE);
	}

	return elements;
}