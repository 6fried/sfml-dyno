#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "player.cpp"

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
        //game loop
        sf::Clock m_timer;
        sf::Time m_count, m__count;
        while (app.isOpen())
        {
            app.clear();
            Event event;
            while (app.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    app.close();
            }
            m_count = m_timer.getElapsedTime();
            m__count = m_count;
            int sec = 8*m_count.asSeconds();
            player.run(sec);
            app.draw(background);
            app.draw(player.m_player);
            app.display();
        }
        
        return EXIT_SUCCESS;

    }