#include "player.hpp"
#include <cmath>

using namespace sf;

Player::Player()
{
		m_player.setPosition(10, 300);
}

void Player::draw(RenderTarget &target)
{
	target.draw(m_player);
}

void Player::run(int ind)
{
	m_path[16]=(ind%8)+'0';            
	if (!m_player_tex.loadFromFile(m_path))
		exit(EXIT_FAILURE);
	m_player.setTexture(m_player_tex);
}

void Player::jump(RenderWindow &app, Sprite &background)
{
	m_path[16]='5';
	if (!m_player_tex.loadFromFile(m_path))
		exit(EXIT_FAILURE);
	m_player.setTexture(m_player_tex);
	while(m_player.getPosition().y >= 220)
	{
		m_speed = Vector2f(0, -4);
		m_player.move(m_speed);
		app.draw(background);
		app.draw(m_player);
		app.display();
	}

	while(m_player.getPosition().y <= 300)
	{
		m_speed = Vector2f(0, 4);
		m_player.move(m_speed);
		app.draw(background);
		app.draw(m_player);
		app.display();
	}
}