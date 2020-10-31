#include "player.hpp"

using namespace sf;

Player::Player()
{
		m_player.setPosition(10, 300);
}

void Player::run(int ind)
{
	m_path[16]=(ind%8)+'0';            
	if (!m_player_tex.loadFromFile(m_path))
		exit(EXIT_FAILURE);
	m_player.setTexture(m_player_tex);
}

void Player::move(Vector2f speed)
{
	m_path[16]='5';
	if (!m_player_tex.loadFromFile(m_path))
		exit(EXIT_FAILURE);
	m_player.setTexture(m_player_tex);
	m_player.move(speed);
}