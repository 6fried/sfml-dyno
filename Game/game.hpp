#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "obstacles.hpp"

using namespace sf;

class Game
{
private:
	RenderWindow app;
	Texture background_tex;
	Sprite background;
	Player player;
	std::vector<Obstacles*> obstacles;
	Clock timer;
	Time count, obs_counter;
	int nbr_obs = 0;
	bool gen;

public:
    Game();
    ~Game();
	void run();
	void create_obstacles();
};
