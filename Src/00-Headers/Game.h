#pragma once
#include <SFML/Graphics.hpp>

#include "Player.h"

class Game
{
private:
	sf::RenderWindow	m_window;
	Player				m_player;

	void ProcessEvent();
	void Update(sf::Time timePerFrame);
	void Render();

public:
	// Destruction of copy operator for our Game class.
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	Game();
	void Run(int fps);
};

