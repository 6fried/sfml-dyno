#include <istream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

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
        Sprite player;
        player.setPosition(10, 300);
        Texture player_tex;
        Clock timer;
        Time count, _count;
        while (app.isOpen())
        {
            count = timer.getElapsedTime();
            if ((count-_count) == seconds(0.125))
            {
                Event event;
                while (app.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        app.close();
                }
                _count = count;
                int sec = 8*count.asSeconds();
                String path = "textures/player/f.png";            
                path[16]=(sec%2)+'0';
                if (!player_tex.loadFromFile(path))
                    return EXIT_FAILURE;
                player.setTexture(player_tex);
                app.clear();
                app.draw(background);
                app.draw(player);
                app.display();
            }
        }
        
        return EXIT_SUCCESS;

    }