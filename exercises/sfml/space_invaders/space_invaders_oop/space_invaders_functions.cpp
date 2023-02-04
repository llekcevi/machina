#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "space_invaders.hpp"

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
/* void Ship::shoot(int laser_y)
{
    if (isShooting)
    {
        std::cout << "ship::shoot" << std::endl;
        laser_y -= m_movement_speed;
         laser.laser_sprite.setPosition(laser.laser_position_x, laser.laser_position_y);
        if (laser_y < 0)
            isShooting = false;
    }
}
 */
Ship::~Ship() {}

Laser::Laser()
{
    m_laser_tex.loadFromFile("/Users/llekcevic/Downloads/spaceArt/png/laserRed.png");
    laser_sprite.setTexture(m_laser_tex);
    m_laser_sprite_height = laser_sprite.getLocalBounds().height;
    m_laser_sprite_width = laser_sprite.getLocalBounds().width;
    laser_sprite.setOrigin(m_laser_sprite_width / 2.f, m_laser_sprite_height / 2.f);
    laser_speed = 15;
    isShooting = false;
}

void Laser::shoot(int ship_x, int ship_y)
{
    position(ship_x, ship_y);
    
    if (isShooting)
    {
        std::cout << laser_position_y << std::endl;
        std::cout << laser_position_x << std::endl;

        std::cout << "laser::shoot" << std::endl;
        moveUp();   
    }
}

void Laser::position(int ship_x, int ship_y)
{
    laser_position_x = ship_x;
    laser_position_y = ship_y;
}

void Laser::moveUp()
{
        while (laser_position_y > 15)
        {
        laser_position_y -= laser_speed;
        std::cout <<"laser::moveUp before set position "<< laser_position_y << std::endl;
            laser_sprite.setPosition(laser_position_x, laser_position_y);

        }
        isShooting = false;
}

Laser::~Laser()
{
}
