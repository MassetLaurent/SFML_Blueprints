#pragma once
#include <SFML/Graphics.hpp>

#include "ActionTarget.h"

class Player : public sf::Drawable, public ActionTarget<int>
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
	sf::RectangleShape	m_shape;
	sf::Vector2f		m_velocity	{ 0.f,0.f };

	bool m_isMoving{ false };
	int m_rotation{ 0 };

	static ActionMap<int> m_playerInputs;

public:
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	
	Player();
	
	template<typename ... Args>	
	void SetPosition(Args&& ... args);

	void ProcessEvents();
	
	void Update(sf::Time deltaTime);
	
	enum PlayerInputs { Up, Left, Right };

	static void SetDefaultsInput();
};

