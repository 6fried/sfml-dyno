#include "game.hpp"


Game::Game()
{
	srand(time(NULL));
	app.create(VideoMode(800, 600, 32), "SFML Dino");
	app.setFramerateLimit(60);
	app.setVerticalSyncEnabled(true);
	if (!background_tex.loadFromFile("textures/background.png"))
			 exit(EXIT_FAILURE);
	background.setTexture(background_tex);
	obstacles.push_back(new Obstacles);
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
					{
						while(player.m_player.getPosition().y >= 160)
						{
							player.move(Vector2f(0, -4));
							app.draw(background);
							for (int i = 0; i < obstacles.size(); i++){
								obstacles[i]->move();
								if (obstacles[i]->m_obstacle.getPosition().x == -20)
								{
									delete obstacles[i];
								}
								app.draw(obstacles[i]->m_obstacle);}
							app.draw(player.m_player);
							app.display();
						}

						while(player.m_player.getPosition().y <= 300)
						{
							player.move(Vector2f(0, 4));
							app.draw(background);
							for (int i = 0; i < obstacles.size(); i++){
								obstacles[i]->move();
								app.draw(obstacles[i]->m_obstacle);}
							app.draw(player.m_player);
							app.display();
						}

					}
					break;
			}
		}
		//read map
		//if map has || great obs
		//if map has |  small obs
		//if map has \/ black hole
		int sec = 32*count.asSeconds();
		player.run(sec);
		app.draw(background);
		/*int it = timer.getElapsedTime().asSeconds();
		if ((timer.getElapsedTime()-obs_counter).asSeconds() >= 2.5){
			gen = true;
			obs_counter =	timer.getElapsedTime();}
		else
			gen = false;
		if (800 - obstacles[obstacles.size()-1]->m_obstacle.getPosition().x >= 400){
			int r = rand()%3;
			for (int i = 0; i < r; i++)
				if (800 - obstacles[obstacles.size()-1]->m_obstacle.getPosition().x >= 10){
					create_obstacles();
				}}*/
		for (int i = 0; i < obstacles.size(); i++){
			obstacles[i]->move();
			app.draw(obstacles[i]->m_obstacle);}			
		app.draw(player.m_player);
		app.display();
	}
	exit(EXIT_SUCCESS);
}

void Game::create_obstacles()
{
	obstacles.push_back(new Obstacles);
}


