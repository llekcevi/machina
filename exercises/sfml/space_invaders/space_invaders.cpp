#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ship
{
    //dodati funckiju za kretanje broda
public:
    sf::Texture ship_tex;
    sf::Sprite ship_sprite;
    int ship_sprite_height;
    int ship_sprite_width;
    int ship_current_position_x;
    int ship_current_position_y; 
    bool isMovingRight;
    bool isMovingLeft;
    bool isShooting;
    int movement_speed;

public:
    Ship(int window_height, int window_width);
    ~Ship();
};

int
main()
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

    Ship ship(window_height, window_width);
;
    // laser
    sf::Texture laser_tex;
    laser_tex.loadFromFile("/Users/llekcevic/Downloads/spaceArt/png/laserRed.png");
    sf::Sprite laser_sprite;
    laser_sprite.setTexture(laser_tex);
    int laser_sprite_height = laser_sprite.getLocalBounds().height;
    int laser_sprite_width = laser_sprite.getLocalBounds().width;
    laser_sprite.setOrigin(laser_sprite_width / 2.f, laser_sprite_height / 2.f);
    int laser_current_position_x = ship.ship_current_position_x;
    int laser_current_position_y = ship.ship_current_position_y;
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
                    ship.isMovingRight = true;
                else if (event.key.code == sf::Keyboard::Key::Left)
                    ship.isMovingLeft = true;
                else if (event.key.code == sf::Keyboard::Key::Space)
                    ship.isShooting = true;
            if (event.type == sf::Event::KeyReleased)
                if (event.key.code == sf::Keyboard::Key::Right)
                    ship.isMovingRight = false;
                else if (event.key.code == sf::Keyboard::Key::Left)
                    ship.isMovingLeft = false;
        }
        // Activate the window for OpenGL rendering
        window.setActive();

        if (ship.isMovingLeft && (ship.ship_current_position_x - ship.ship_sprite_width / 2) > 0)
        {
            ship.ship_current_position_x -= ship.movement_speed;
            laser_current_position_x -= ship.movement_speed;
            if (ship.isShooting)
            {
                laser_current_position_y -= laser_speed;
                laser_current_position_x += ship.movement_speed;

                if (laser_current_position_y < 0)
                {
                    ship.isShooting = false;
                    laser_current_position_y = ship.ship_sprite.getPosition().y;
                    laser_current_position_x = ship.ship_sprite.getPosition().x;
                }
            }
        }

        else if (ship.isMovingRight && (ship.ship_current_position_x - ship.ship_sprite_width / 2 < (window_width - ship.ship_sprite_width)))
        {
            ship.ship_current_position_x += ship.movement_speed;
            laser_current_position_x += ship.movement_speed;
            if (ship.isShooting)
            {
                laser_current_position_y -= laser_speed;
                laser_current_position_x -= ship.movement_speed;

                if (laser_current_position_y < 0)
                {
                    ship.isShooting = false;
                    laser_current_position_y = ship.ship_sprite.getPosition().y;
                    laser_current_position_x = ship.ship_sprite.getPosition().x;
                }
            }
        }

        else if (ship.isShooting)
        {
            laser_current_position_y -= 15;

            if (laser_current_position_y < 0)
            {
                ship.isShooting = false;
                laser_current_position_y = ship.ship_sprite.getPosition().y;
                laser_current_position_x = ship.ship_sprite.getPosition().x;
            }
        }

        ship.ship_sprite.setPosition(ship.ship_current_position_x, ship.ship_current_position_y);
        laser_sprite.setPosition(laser_current_position_x, laser_current_position_y);

        // DRAW
        window.clear();
        // window.draw(wall_sprite);
        window.draw(background_sprite);
        window.draw(laser_sprite);
        window.draw(ship.ship_sprite);

        // OpenGL drawing commands go here...
        // End the current frame and display its contents on screen
        window.display();
    }
    return 0;
}

Ship::Ship(int window_height, int window_width)
{
    ship_tex.loadFromFile("/Users/llekcevic/Downloads/spaceArt/png/player.png");
    ship_sprite.setTexture(ship_tex);
    ship_sprite_height = ship_sprite.getLocalBounds().height;
    ship_sprite_width = ship_sprite.getGlobalBounds().width;
    ship_sprite.setOrigin(ship_sprite_width / 2.f, ship_sprite_height / 2.f);
    ship_current_position_x = window_width / 2;
    ship_current_position_y = window_height - ship_sprite_height / 2.f;
    int movement_speed = 3;
}

Ship::~Ship() {}