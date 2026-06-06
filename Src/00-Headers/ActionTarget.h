#pragma once
#include <functional>
#include <SFML/Graphics.hpp>

#include "Action.h"
#include "ActionMap.h"

template<typename T = int>
class ActionTarget
{
using FuncType = std::function<void(const sf::Event&)>;

private:
	std::list<std::pair<T, FuncType>> m_eventsRealTime;
	std::list<std::pair<T, FuncType>> m_eventsPoll;

	const ActionMap<T>& m_actionMap;

public:
	ActionTarget(const ActionTarget<T>&) = delete;
	ActionTarget<T>& operator=(const ActionTarget<T>&) = delete;

	using FuncType = std::function<void(const sf::Event&)>;

	ActionTarget(const ACtionMap<T>& map);

	bool ProcessEvent(const sf::Event& event) const;
	void ProcessEvents() const;
	void Bind(const T& key, const FuncType& callback);
	void Unbind(const T& key);
};

