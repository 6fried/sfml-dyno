#include <SFML/Graphics.hpp>

using namespace sf;

class Obstacles
{
private:
    Texture m_obstacle_tex;
    Vector2f m_speed;
public:
    Sprite m_obstacle;
    Obstacles();
    void move(Vector2f m_speed = Vector2f(-4, 0));
    void draw(RenderTarget &app);
    Obstacles generate();
};
