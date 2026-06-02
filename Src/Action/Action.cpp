#include "../00-Headers/Action.h"

Action::Action(const Action& other) : m_type(other.m_type)
{
	std::memcpy(&m_event, &other.m_event, sizeof(sf::Event));
}

Action& Action::operator=(const Action& other)
{
	std::memcpy(&m_event, &other.m_event, sizeof(sf::Event));
	m_type = other.m_type;
	return *this;
}