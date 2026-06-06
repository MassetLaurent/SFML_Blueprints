#pragma once
#include <unordered_map>

#include "Action.h"

template<typename T = int>
class ActionMap
{
private:
	std::unordered_map<T, Action> m_map;

public:
	ActionMap(const ActionMap<T>&) = delete;
	ActionMap<T>& operator=(const ActionMap<T>&) = delete;

	ActionMap() = default;

	template<typename T>
	void ActionMap<T>::Map(const T& key, const Action& action)
	{
		m_map.emplace(key, action);
	}

	template<typename T>
	const Action& ActionMap<T>::Get(const T& key) const
	{
		return m_map.at(key);
	}
};

