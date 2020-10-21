#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
    private:
        sf::Sprite m_player;
        sf::Texture m_player_tex;
        sf::Clock m_timer;
        sf::Time m_count, m__count;
        String m_path = "textures/player/f.png";            

        
    public:
        Player();
        void run(RenderWindow app, Sprite background);
};
