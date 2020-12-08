#pragma once

#ifndef _STATE_HPP
#define _STATE_HPP


// Base Class for modeling all States
class State
{
public:
	virtual void init() = 0;
	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual void pause();
	virtual void resume();
};


#endif // !_STATE_HPP
