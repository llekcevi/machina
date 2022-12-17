#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    // Declare and create a new window
    sf::Window window(sf::VideoMode(800, 600), "SFML window");
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);
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
        // OpenGL drawing commands go here...
        // End the current frame and display its contents on screen
        window.display();
    }
    return 0;
}