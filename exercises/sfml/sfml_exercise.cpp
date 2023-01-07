#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // Declare and create a new window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML window");
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);

    // SETUP
    // - window
    int window_height = window.getSize().y;
    int window_width = window.getSize().x;

    //-background

    sf::Texture background;
    background.loadFromFile("/Users/llekcevic/Downloads/space.jpg");
    sf::Sprite background_sprite;
    background_sprite.setTexture(background);
    background_sprite.setScale(0.5, 0.5);

    // - ship

    sf::Texture ship_tex;
    ship_tex.loadFromFile("/Users/llekcevic/Downloads/spaceArt/png/player.png");
    sf::Sprite ship_sprite;
    ship_sprite.setTexture(ship_tex);
    // ship_sprite.setScale(0.3, 0.3);
    int ship_sprite_height = ship_sprite.getLocalBounds().height;
    int ship_sprite_width = ship_sprite.getGlobalBounds().width;
    ship_sprite.setOrigin(ship_sprite_width / 2.f, ship_sprite_height / 2.f);
    // int sprite_rotation = 0;
    int ship_current_position_x = 500;
    int ship_current_position_y = 500;
    bool isMovingRight;
    bool isMovingLeft;
    bool isMovingForwards;
    bool isMovingBackwards;
    bool isShooting;
    int movement_speed = 3;

    // laser
    sf::Texture laser_tex;
    laser_tex.loadFromFile("/Users/llekcevic/Downloads/spaceArt/png/laserRed.png");
    sf::Sprite laser_sprite;
    laser_sprite.setTexture(laser_tex);
    int laser_sprite_height = laser_sprite.getLocalBounds().height;
    int laser_sprite_width = laser_sprite.getLocalBounds().width;
    laser_sprite.setOrigin(laser_sprite_width / 2.f, laser_sprite_height / 2.f);
    int laser_current_position_x = ship_current_position_x;
    int laser_current_position_y = ship_current_position_y;
    int laser_speed = 15;

    // GAME ENGINE LOOP

    // The main loop - ends as soon as the window is closed
    while (window.isOpen())
    {
        // FRAME CALCULATION

        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Key::Right)
                    isMovingRight = true;
                else if (event.key.code == sf::Keyboard::Key::Left)
                    isMovingLeft = true;
                else if (event.key.code == sf::Keyboard::Key::Up)
                    isMovingForwards = true;
                else if (event.key.code == sf::Keyboard::Key::Down)
                    isMovingBackwards = true;
                else if (event.key.code == sf::Keyboard::Key::Space)
                    isShooting = true;
            if (event.type == sf::Event::KeyReleased)
                if (event.key.code == sf::Keyboard::Key::Right)
                    isMovingRight = false;
                else if (event.key.code == sf::Keyboard::Key::Left)
                    isMovingLeft = false;
                else if (event.key.code == sf::Keyboard::Key::Up)
                    isMovingForwards = false;
                else if (event.key.code == sf::Keyboard::Key::Down)
                    isMovingBackwards = false;
        }
        // Activate the window for OpenGL rendering
        window.setActive();

        if (isMovingBackwards && (ship_current_position_y < (window_height - ship_sprite_height)))
        {
            ship_current_position_y += movement_speed;
            laser_current_position_y += movement_speed;
        }
        else if (isMovingForwards && ship_current_position_y > 0)
        {
            ship_current_position_y -= movement_speed;
            laser_current_position_y -= movement_speed;
        }

        else if (isMovingLeft && ship_current_position_x > 0)
        {
            ship_current_position_x -= movement_speed;
            laser_current_position_x -= movement_speed;
        }

        else if (isMovingRight && (ship_current_position_x < (window_width - ship_sprite_width)))
        {
            ship_current_position_x += movement_speed;
            laser_current_position_x += movement_speed;
        }

        else if (isShooting)
        {
            laser_current_position_y -= 15;
            if (laser_current_position_y < 0)
            {
                isShooting = false;
                laser_current_position_y = ship_sprite.getPosition().y;
                laser_current_position_x = ship_sprite.getPosition().x;
            }
        }

        ship_sprite.setPosition(ship_current_position_x, ship_current_position_y);
        laser_sprite.setPosition(laser_current_position_x, laser_current_position_y);

        // DRAW
        window.clear();
        // window.draw(wall_sprite);
        window.draw(background_sprite);
        window.draw(laser_sprite);
        window.draw(ship_sprite);

        // OpenGL drawing commands go here...
        // End the current frame and display its contents on screen
        window.display();
    }
    return 0;
}