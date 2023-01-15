#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ship
{
    // dodati funckiju za kretanje broda
public:
    sf::Sprite ship_sprite;
    int ship_sprite_height;
    int ship_sprite_width;
    int ship_current_position_x;
    int ship_current_position_y;
    bool isMovingRight;
    bool canMoveRight;
    bool isMovingLeft;
    bool canMoveLeft;
    bool isShooting;
    int m_movement_speed;

private:
    sf::Texture m_ship_tex;

public:
    Ship(sf::RenderWindow *window);
    void moveShip(sf::RenderWindow *window);
    void moveRight();
    void moveLeft();
    ~Ship();
};

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

    Ship ship(&window);
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
                {
                    ship.isMovingRight = true;
                }
                else if (event.key.code == sf::Keyboard::Key::Left)
                    ship.isMovingLeft = true;
                else if (event.key.code == sf::Keyboard::Key::Space)
                    ship.isShooting = true;
            if (event.type == sf::Event::KeyReleased)
                if (event.key.code == sf::Keyboard::Key::Right)
                {
                    ship.isMovingRight = false;
                }

                else if (event.key.code == sf::Keyboard::Key::Left)
                    ship.isMovingLeft = false;
        }
        // Activate the window for OpenGL rendering
        window.setActive();
        ship.moveShip(&window);
        /* if (ship.isMovingLeft && (ship.ship_current_position_x - ship.ship_sprite_width / 2) > 0)
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
            ship.moveRight();
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
        } */

        if (ship.isShooting)
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
        window.draw(background_sprite);
        window.draw(laser_sprite);
        window.draw(ship.ship_sprite);

        // End the current frame and display its contents on screen
        window.display();
    }
    return 0;
}

Ship::Ship(sf::RenderWindow *window)
{
    m_ship_tex.loadFromFile("/Users/llekcevic/Downloads/spaceArt/png/player.png");
    ship_sprite.setTexture(m_ship_tex);
    ship_sprite_height = ship_sprite.getLocalBounds().height;
    ship_sprite_width = ship_sprite.getGlobalBounds().width;
    ship_sprite.setOrigin(ship_sprite_width / 2.f, ship_sprite_height / 2.f);
    ship_current_position_x = window->getSize().x / 2;
    ship_current_position_y = window->getSize().y - ship_sprite_height / 2.f;
    m_movement_speed = 3;
    std::cout << ship_sprite_width << std::endl;
}

void Ship::moveShip(sf::RenderWindow *window)
{
    bool canMoveRight = (ship_current_position_x - ship_sprite_width / 2.f) < (window->getSize().x - ship_sprite_width);
    bool canMoveLeft = (ship_current_position_x - ship_sprite_width / 2.f) > 0;

    if (isMovingRight && canMoveRight)
    {
        moveRight();
    }
    else if (isMovingLeft && canMoveLeft)
    {
        moveLeft();
    }
}

void Ship::moveRight()
{
    ship_current_position_x += m_movement_speed;
    std::cout << ship_current_position_x << std::endl;
    std::cout << canMoveRight << std::endl;
}

void Ship::moveLeft()
{
    ship_current_position_x -= m_movement_speed;
    std::cout << ship_current_position_x << std::endl;
}

Ship::~Ship() {}