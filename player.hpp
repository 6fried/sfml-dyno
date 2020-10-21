#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
	private:
		Texture m_player_tex;
		String m_path = "textures/player/f.png";
		Vector2f m_speed;

		
	public:
		Sprite m_player;
		Player();
		void run(int ind);
		void jump(RenderWindow &app, Sprite &background);
		void draw(RenderTarget &target);
};
