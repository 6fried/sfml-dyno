#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
    private:
        
        sf::Texture m_player_tex;
        String m_path = "textures/player/f.png";            

        
    public:
        sf::Sprite m_player;
        Player();
        void run(int ind);
};
