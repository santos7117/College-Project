#pragma once

#ifndef _ELEMENT_ANIMATOR_HPP
#define _ELEMENT_ANIMATOR_HPP

#include "stdafx.hpp"

#include "Element.hpp"


class ElementAnimator
{
private:

	std::shared_ptr<Element> leftElem;
	std::shared_ptr<Element> rightElem;

	float deltaTime;

public:

	//ElementAnimator(Element &left, Element &right, const float &dt) :
	//	leftElem{left},
	//	rightElem{right},
	//	deltaTime{dt}
	//{

	//}

	void set(Element& left, Element& right)
	{
		leftElem = std::make_shared<Element> (left);
		rightElem = std::make_shared<Element>(right);
	}

	void update(const float& _dt)
	{
		leftElem->move(_dt, 0.f);
		rightElem->move(-_dt, 0.f);
	}


};

#endif