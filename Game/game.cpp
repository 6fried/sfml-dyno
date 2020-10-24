#include "game.hpp"

using namespace std;

Game::Game()
{
	srand(time(NULL));
	app.create(VideoMode(800, 600, 32), "SFML Dino");
	app.setFramerateLimit(60);
	app.setVerticalSyncEnabled(true);
	if (!background_tex.loadFromFile("textures/background.png"))
			 exit(EXIT_FAILURE);
	background.setTexture(background_tex);
	map.open("textures/map.mp");
	if (!map)
		exit(EXIT_FAILURE);
	
}

Game::~Game()
{
	delete this;
}

void Game::run()
{
	while (app.isOpen())
	{
		count = timer.getElapsedTime();
		take_event();
		read_map();
		app.draw(background);
		for (int i = 0; i < obstacles.size(); i++){
			obstacles[i]->move();
			if (obstacles[i]->m_obstacle.getPosition().x == -20)
				obstacles.erase(obstacles.begin()+i);
			else app.draw(obstacles[i]->m_obstacle);}
		app.draw(player.m_player);

		app.display();
	}
	exit(EXIT_SUCCESS);
}

void Game::take_event()
{
	Event event;
	while (app.pollEvent(event))
	{
		switch (event.type)
		{
			case Event::Closed:
				app.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Space))
					play_jump_anim();
				break;
		}
	}
}

void Game::create_obstacles()
{
	obstacles.push_back(new Obstacles);
}

void Game::play_jump_anim()
{
	while(player.m_player.getPosition().y >= 160)
	{
		player.move(Vector2f(0, -4));
		app.draw(background);
		for (int i = 0; i < obstacles.size(); i++){
		obstacles[i]->move();
		if (obstacles[i]->m_obstacle.getPosition().x == -20){
			obstacles.erase(obstacles.begin()+i);
			create_obstacles();}
		else app.draw(obstacles[i]->m_obstacle);}
		app.draw(player.m_player);
		app.display();
	}

	while(player.m_player.getPosition().y <= 300)
	{
		player.move(Vector2f(0, 4));
		app.draw(background);
		for (int i = 0; i < obstacles.size(); i++){
		obstacles[i]->move();
		if (obstacles[i]->m_obstacle.getPosition().x == -20){
			obstacles.erase(obstacles.begin()+i);
			create_obstacles();}
		else app.draw(obstacles[i]->m_obstacle);}
		app.draw(player.m_player);
		app.display();
	}
}

void Game::still_running(double time)
{
	while ((timer.getElapsedTime()-count).asSeconds() < time)
	{
		take_event();
		_count = timer.getElapsedTime();
		int sec = 32*_count.asSeconds();
		player.run(sec);
		app.draw(background);
		for (int i = 0; i < obstacles.size(); i++){
			obstacles[i]->move();
			if (obstacles[i]->m_obstacle.getPosition().x == -20)
			{
				obstacles.erase(obstacles.begin()+i);
				create_obstacles();
			}
			else app.draw(obstacles[i]->m_obstacle);}
		app.draw(player.m_player);
		app.display();		
	}
}

void Game::read_map()
{
	char c;
	
	map.get(c);
	switch (c)
	{
		case 46:  //'.'
			still_running(0.5);
		break;
		case 124: //'|'
			still_running(0.1);
			create_obstacles();
		break;
		default:
			still_running();
		break;
	}
}


