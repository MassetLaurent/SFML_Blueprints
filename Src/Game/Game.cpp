#include "../00-Headers/Game.h"
//Privates methods
void Game::ProcessEvent()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case(sf::Event::Closed):
			m_window.close();
			break;
		case(sf::Event::KeyPressed):
			switch (event.key.code)
			{
			case(sf::Keyboard::Escape):
				m_window.close();
				break;
			default:
				break;
			}			
			break;
		default:
			break;
		}
	}
}

void Game::Update(sf::Time timePerFrame)
{

}

void Game::Render()
{
	m_window.clear(sf::Color(35,35,35,255));
	m_window.draw(m_player);
	m_window.display();
}


// Publics methods
Game::Game() : m_window(sf::VideoMode(800,600), "LM Engine")
{

}

void Game::Run(int minimumFPS)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate{ sf::Time::Zero };
	sf::Time timePerFrame = sf::seconds(1.f / minimumFPS);

	while (m_window.isOpen())
	{
		ProcessEvent();

		timeSinceLastUpdate = clock.restart();

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			Update(timePerFrame);
		}

		Update(timeSinceLastUpdate);
		Render();
	}
}
