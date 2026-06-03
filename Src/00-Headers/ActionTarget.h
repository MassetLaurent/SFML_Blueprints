#pragma once
#include <functional>
#include <SFML/Graphics.hpp>

#include "Action.h"

class ActionTarget
{
using FuncType = std::function<void(const sf::Event&)>;

private:
	std::list<std::pair<Action, FuncType>> m_eventsRealTime;
	std::list<std::pair<Action, FuncType>> m_eventsPoll;

public:
	ActionTarget();

	bool ProcessEvent(const sf::Event& event) const;
	void ProcessEvents() const;
	void Bind(const Action& action, const FuncType& callback);
	void Unbind(const Action& action);
};

