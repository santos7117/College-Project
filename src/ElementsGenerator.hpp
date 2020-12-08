#pragma once

#ifndef _RANDOM_ARRAY_GENERATOR_HPP
#define _RANDOM_ARRAY_GENERATOR_HPP


#include "Element.hpp"

typedef std::vector<Element> ElementsArray;

class ElementsGenerator 
{

private:
	
	ElementsArray elements;


public:

	// Initializes Array
	ElementsGenerator();

	// Returns array of Elements with random values
	ElementsArray& init();

	// Randomizes previously generated array
	ElementsArray& randomize(const short unsigned&);

};

#endif