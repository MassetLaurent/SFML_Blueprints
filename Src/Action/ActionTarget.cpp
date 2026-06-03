#include "../00-Headers/ActionTarget.h"

ActionTarget::ActionTarget()
{

}

bool ActionTarget::ProcessEvent(const sf::Event& event) const
{
	bool res{ false };

	for (auto& action : m_eventsPoll)
	{
		if (action.first == event)
		{
			action.second(event);
			res = true;
			break;
		}
	}

	return res;
}

void ActionTarget::ProcessEvents() const
{
	for (auto& action : m_eventsRealTime)
	{
		if (action.first.test())
			action.second(action.first.m_event);
	}
}

void ActionTarget::Bind(const Action& action, const FuncType& callback)
{
	if (action.m_type & Action::Type::RealTime)
		m_eventsRealTime.emplace_back(action, callback);
	else
		m_eventsPoll.emplace_back(action, callback);
}

void ActionTarget::Unbind(const Action& action)
{
	auto remove_func = [&action](const std::pair<Action, FuncType>& pair)->bool
		{
			return pair.first == action;
		};
	
	if (action.m_type & Action::Type::RealTime)
		m_eventsRealTime.remove_if(remove_func);
	else
		m_eventsPoll.remove_if(remove_func);
}