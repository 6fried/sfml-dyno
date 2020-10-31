#include "obstacles.hpp"

using namespace sf;

Obstacles::Obstacles()
{
    if (!m_obstacle_tex.loadFromFile("textures/obstacles/obstacle.png"))
		exit(EXIT_FAILURE);
	m_obstacle.setTexture(m_obstacle_tex);
    m_obstacle.setScale(0.25, 0.25);
    m_obstacle.setPosition(810, 300);
    this->move();
}

void Obstacles::move(Vector2f m_speed)
{
    if (m_obstacle.getPosition().x >= -20)
        m_obstacle.move(m_speed);
//    else m_obstacle.setPosition(780, 300);
}
