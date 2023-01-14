#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Click");
    window.setFramerateLimit(60);
    // MOUSE
    bool leftClick;
    ;

    // RECT
    sf::RectangleShape rect;
    sf::Vector2f rect_position(100, 100);
    rect.setPosition(rect_position.x, rect_position.y);
    sf::Vector2f rect_size = sf::Vector2f(100, 100);
    rect.setSize(rect_size);
    sf::Color color = sf::Color::Green;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left)
                    leftClick = true;
            if (event.type == sf::Event::MouseButtonReleased)
                if (event.key.code == sf::Mouse::Left)
                    leftClick = false;
        }
        window.setActive();

        if (leftClick)
        {
            int mouse_x = sf::Mouse::getPosition(window).x;
            int mouse_y = sf::Mouse::getPosition(window).y;
            if ((mouse_x > rect_position.x) && (mouse_x < (rect_position.x + 100)) && (mouse_y > rect_position.y) && (mouse_y < (rect_position.y + 100)))
            {
                color = sf::Color::Black;
            }  
        }
        rect.setFillColor(color);

        // window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}