#pragma once

#include <random>
#include <ctime>
#include <array>

#include "Element.cpp"

const size_t ARR_SIZE = 225;
const unsigned RANGE = 500;

class RandomArrayGenerator {

private:

	std::array <Element, ARR_SIZE> elements;


public:

	// Returns array of elements with random values
	std::array<Element, ARR_SIZE> randomize() {
		std::srand(unsigned(std::time(nullptr)));

		for (unsigned i{ 0 }; i < elements.size(); i++) {
			elements[i].setValue(5 + std::rand() % RANGE);
		}

		return elements;
	}

};

