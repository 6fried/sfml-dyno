#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "player.hpp"

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
						player.jump(app, background);
						break;
				}
			}
			int sec = 32*count.asSeconds();
			player.run(sec);
			app.draw(background);
			app.draw(player.m_player);
			app.display();
		}
		
		return EXIT_SUCCESS;

	}