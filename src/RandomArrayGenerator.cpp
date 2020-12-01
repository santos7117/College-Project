#include "stdafx.hpp"

#include "RandomArrayGenerator.hpp"

RandomArrayGenerator::RandomArrayGenerator() :
	elements{ARR_SIZE}
{}


// Returns initilized vector
std::vector<Element> &RandomArrayGenerator::init() 
{
	// creates seed each time program starts
	std::srand(short unsigned(std::time(nullptr)));

	return elements;
}


// Fills vector with random numbers upto given index
std::vector<Element>& RandomArrayGenerator::randomize(const short unsigned& _numOfElements = ARR_SIZE)
{
	for (short i{ 0 }; i< _numOfElements; ++i)
	{
		elements[i].setValue(5 + std::rand() % RANGE);
		elements[i].setColor(unsortedColor);
	}

	return elements;
}