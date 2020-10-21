#include "player.hpp"

using namespace sf;

Player::Player()
{
        m_player.setPosition(10, 300);
}

void Player::run(RenderWindow app, Sprite background)
{
    m_count = m_timer.getElapsedTime();
    m__count = m_count;
    int sec = 8*m_count.asSeconds();
    m_path[16]=(sec%2)+'0';            
    if (!m_player_tex.loadFromFile(m_path))
        exit(EXIT_FAILURE);
    m_player.setTexture(m_player_tex);
    app.draw(background);
    app.draw(m_player);
}