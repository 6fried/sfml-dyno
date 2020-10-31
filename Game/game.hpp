#include <SFML/Graphics.hpp>
#include <fstream>
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
	Time count, _count;
	int nbr_obs = 0;
	bool gen;
	std::ifstream map;



public:
    Game();
    ~Game();
	void run();
	void take_event();
	void create_obstacles();
	void play_jump_anim();
	void still_running(double time = 2.5);
	void read_map();
};
