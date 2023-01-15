#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Laser
{
public:
    sf::Sprite laser_sprite;
    int laser_position_x;
    int laser_position_y;
    int laser_speed;

private:
    sf::Texture m_laser_tex;
    int m_laser_sprite_height;
    int m_laser_sprite_width;

public:
    Laser(int ship_x, int ship_y);
    void shoot();
    ~Laser();
};

class Ship
{
public:
    sf::Sprite ship_sprite;
    int ship_current_position_x;
    int ship_current_position_y;
    bool isMovingRight;
    bool isMovingLeft;
    bool isShooting;

private:
    sf::Texture m_ship_tex;
    int m_movement_speed;
    int m_ship_sprite_height;
    int m_ship_sprite_width;

public:
    Ship(sf::RenderWindow *window);
    void moveShip(sf::RenderWindow *window);
    void moveRight();
    void moveLeft();
    void shoot();
    ~Ship();
};

int main()
{
    // Declare and create a new window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML window");
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);

    // SETUP
    //-background

    sf::Texture background;
    background.loadFromFile("/Users/llekcevic/Downloads/space.jpg");
    sf::Sprite background_sprite;
    background_sprite.setTexture(background);
    background_sprite.setScale(0.5, 0.5);

    // - ship

    Ship ship(&window);

    // laser

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
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Key::Right)
                {
                    ship.isMovingRight = true;
                }
                else if (event.key.code == sf::Keyboard::Key::Left)
                {
                    ship.isMovingLeft = true;
                }
                else if (event.key.code == sf::Keyboard::Key::Space)
                {
                    ship.isShooting = true;
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Key::Right)
                {
                    ship.isMovingRight = false;
                }
                else if (event.key.code == sf::Keyboard::Key::Left)
                {
                    ship.isMovingLeft = false;
                }
            }
        }
        // Activate the window for OpenGL rendering
        window.setActive();
        
        ship.moveShip(&window);

        ship.shoot();
   

        // DRAW
        window.clear();
        window.draw(background_sprite);
        //kako nacrtati laser?
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
    m_ship_sprite_height = ship_sprite.getLocalBounds().height;
    m_ship_sprite_width = ship_sprite.getGlobalBounds().width;
    ship_sprite.setOrigin(m_ship_sprite_width / 2.f, m_ship_sprite_height / 2.f);
    ship_current_position_x = window->getSize().x / 2;
    ship_current_position_y = window->getSize().y - m_ship_sprite_height / 2.f;
    m_movement_speed = 3;
}

void Ship::moveShip(sf::RenderWindow *window)
{
    bool canMoveRight = (ship_current_position_x - m_ship_sprite_width / 2.f) < (window->getSize().x - m_ship_sprite_width);
    bool canMoveLeft = (ship_current_position_x - m_ship_sprite_width / 2.f) > 0;

    if (isMovingRight && canMoveRight)
    {
        moveRight();
    }
    else if (isMovingLeft && canMoveLeft)
    {
        moveLeft();
    }
    ship_sprite.setPosition(ship_current_position_x, ship_current_position_y);
}

void Ship::moveRight()
{
    ship_current_position_x += m_movement_speed;
}

void Ship::moveLeft()
{
    ship_current_position_x -= m_movement_speed;
}
void Ship::shoot()
{
    if (isShooting)
    {
        std::cout << "ship::shoot" << std::endl;
        Laser laser (ship_current_position_x, ship_current_position_y);
        laser.shoot();
        laser.laser_sprite.setPosition(laser.laser_position_x, laser.laser_position_y);
        isShooting = false;
    }
}

Ship::~Ship() {}

Laser::Laser(int ship_x, int ship_y)
{
    m_laser_tex.loadFromFile("/Users/llekcevic/Downloads/spaceArt/png/laserRed.png");
    laser_sprite.setTexture(m_laser_tex);
    m_laser_sprite_height = laser_sprite.getLocalBounds().height;
    m_laser_sprite_width = laser_sprite.getLocalBounds().width;
    laser_sprite.setOrigin(m_laser_sprite_width / 2.f, m_laser_sprite_height / 2.f);
    laser_speed = 15;
    laser_position_x = ship_x;
    laser_position_y -= ship_y;
}

void Laser::shoot()
{
    laser_position_y -= laser_speed;
}

Laser::~Laser()
{
}
