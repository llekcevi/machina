#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // Declare and create a new window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML window");
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);
    
    //SETUP
    sf::Texture zec_tekstura;
    zec_tekstura.loadFromFile("/Users/llekcevic/Downloads/kenney-animalpack/PNG/Round/rabbit.png");

    sf::Sprite zec_sprite;
    zec_sprite.setTexture(zec_tekstura);
    // GAME ENGINE LOOP


    // The main loop - ends as soon as the window is closed
    while (window.isOpen())
    {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Activate the window for OpenGL rendering
        window.setActive();
        //DRAW

        window.draw(zec_sprite);

        // OpenGL drawing commands go here...
        // End the current frame and display its contents on screen
        window.display();
    }
    return 0;
}