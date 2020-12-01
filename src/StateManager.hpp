#pragma once

#ifndef _STATE_MANAGER_HPP
#define _STATE_MANAGER_HPP

#include "State.hpp"
#include <memory>
#include <stack>

typedef std::unique_ptr<State> StateRef;

class StateManager
{
private:
	std::stack<StateRef> states;
	StateRef newState;

	bool isRemoving;
	bool isAdding;
	bool isReplacing;

public:
	StateManager()  {}
	~StateManager() {}

	void addState(StateRef _new_state, bool _is_replacing = true);
	void removeState();

	void processStateChanges();

	StateRef& getActiveState();
};


#endif