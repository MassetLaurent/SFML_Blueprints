#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
private:
	sf::RectangleShape	m_shape;
	sf::Vector2f		m_velocity	{ 0.f,0.f };

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	Player();
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;

	int		m_rotation	{ 0 };
	bool	m_isMoving	{ false };

	void Update(sf::Time deltaTime);

	void ProcessEvents();
	
	template<typename ... Args>	
	void SetPosition(Args&& ... args) {
		m_shape.setPosition(std::forward<Args>(args)...);
	}
};

