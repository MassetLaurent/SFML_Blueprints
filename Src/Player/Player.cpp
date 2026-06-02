#include "../00-Headers/Player.h"
const float M_PI{ 3.1416 };

Player::Player() : m_shape(sf::Vector2f(32.f, 32.f))
{
	m_shape.setFillColor(sf::Color::Blue);
	m_shape.setOrigin(16, 16);
}


void Player::Update(sf::Time deltaTime)
{
	float seconds = deltaTime.asSeconds();

	if (m_rotation != 0)
	{
		float angle = m_rotation * 180 * seconds;
		m_shape.rotate(angle);
	}

	if (m_isMoving)
	{
		float angle = m_shape.getRotation() / 180 * M_PI - M_PI / 2;
		m_velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.f * seconds;
	}

	m_shape.move(seconds * m_velocity);
	
	/*
	std::cout << " rotation :" << m_rotation << std::endl;
	std::cout << " is moving :" << m_isMoving << std::endl;*/
}

void Player::ProcessEvents()
{
	m_isMoving = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	m_rotation = 0;
	m_rotation -= sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	m_rotation += sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_shape, states);
}
