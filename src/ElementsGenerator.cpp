#include "stdafx.hpp"

#include "ElementsGenerator.hpp"

ElementsGenerator::ElementsGenerator() :
	elements{ARR_SIZE}
{}


// Returns initilized vector
ElementsArray& ElementsGenerator::init() 
{
	// creates seed each time program starts
	std::srand(short unsigned(std::time(nullptr)));

	return elements;
}


// Fills vector with random numbers upto given index
ElementsArray& ElementsGenerator::randomize(const short unsigned& _numOfElements = ARR_SIZE)
{
	for (short i{ 0 }; i< _numOfElements; ++i)
	{
		elements[i].setValue(5 + std::rand() % RANGE);
		elements[i].setColor(unsortedColor);
	}

	return elements;
}