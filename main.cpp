#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "obstacles.hpp"

using namespace sf;

	int main()
	{
		//window init
		RenderWindow app(VideoMode(800, 600, 32), "SFML Dino");
		app.setFramerateLimit(60);
		app.setVerticalSyncEnabled(true);
		Texture background_tex;
		if (!background_tex.loadFromFile("textures/background.png"))
			return EXIT_FAILURE;
		Sprite background(background_tex);
		Player player;
		Obstacles obstacle;
		Clock timer;
		Time count;
		//game loop
		while (app.isOpen())
		{
			count = timer.getElapsedTime();
			app.clear();
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
								obstacle.move();
								app.draw(background);
								app.draw(obstacle.m_obstacle);
								app.draw(player.m_player);
								app.display();
							}
							count = timer.getElapsedTime();

							while(player.m_player.getPosition().y <= 300)
							{
								player.move(Vector2f(0, 4));
								obstacle.move();
								app.draw(background);
								app.draw(obstacle.m_obstacle);
								app.draw(player.m_player);
								app.display();
							}

						}
						break;
				}
			}
			int sec = 32*count.asSeconds();
			player.run(sec);
			obstacle.move();
			app.draw(obstacle.m_obstacle);
			app.draw(background);
			app.draw(player.m_player);
			app.draw(obstacle.m_obstacle);
			app.display();
		}
		
		return EXIT_SUCCESS;

	}