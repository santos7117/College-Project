#pragma once

#ifndef _RANDOM_ARRAY_GENERATOR_CPP
#define _RANDOM_ARRAY_GENERATOR_CPP


#include "Element.hpp"

class RandomArrayGenerator 
{

private:

	// <!-- TODO : Make shared_ptr >
	std::array <Element, ARR_SIZE> elements;


public:

	// Returns array of elements with random values
	std::array<Element, ARR_SIZE> &randomize(const short unsigned& _numOfElements);

};

#endif