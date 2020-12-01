#pragma once

#ifndef _RANDOM_ARRAY_GENERATOR_HPP
#define _RANDOM_ARRAY_GENERATOR_HPP


#include "Element.hpp"

class RandomArrayGenerator 
{

private:

	std::vector <Element> elements;


public:
	RandomArrayGenerator();

	// Returns array of Elements with random values
	std::vector<Element>& init();

	std::vector<Element> &randomize(const short unsigned& _numOfElements);

};

#endif