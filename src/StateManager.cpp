#include "stdafx.hpp"

#include "StateManager.hpp"


void StateManager::addState(StateRef _new_state, bool _is_replacing)
{
	isAdding = true;
	isReplacing = _is_replacing;

	newState = std::move(_new_state);
}

void StateManager::removeState()
{
	isRemoving = true;
}

void StateManager::processStateChanges()
{
	if (isRemoving && !states.empty())
	{
		states.pop();

		if (!states.empty())
		{
			states.top()->resume();
		}

		isRemoving = false;
	}

	if (isAdding)
	{
		if (!states.empty())
		{
			if (isRemoving)
			{
				states.pop();
			}
			else
			{
				states.top()->pause();
			}
		}
		states.push(std::move(newState));
		states.top()->init();

		isAdding = false;
	}

}

StateRef& StateManager::getActiveState() { return states.top(); }