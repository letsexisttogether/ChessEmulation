#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Mouse.hpp"


#include "UI/Buttons/SimpleButton/SimpleButton.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");

    sf::CircleShape shape(50); 
    shape.setFillColor(sf::Color::Green); 
    shape.setPosition(50.f, 50.f);

    sf::Texture texture{};
    texture.loadFromFile("D:/Important/Programming/Solo/ChessEmulation/Resourses/button.png");

    std::unique_ptr<Button> button{ new SimpleButton<void>
    { 
        texture, 
        []() -> void { std::cout << "The name is Alex" << std::endl; } 
    }};

    button->setPosition(50.f, 100.f);

    while (window.isOpen()) 
    {
        for (sf::Event event; window.pollEvent(event); ) 
        {
            sf::Event::EventType type{ event.type };

            if (type == sf::Event::Closed)
            {
                window.close();
            }
            if (type == sf::Event::MouseButtonReleased 
                    && event.mouseButton.button == sf::Mouse::Left 
                    && button->IsIntersected(sf::Mouse::getPosition(window)))
            {
                button->Press();
            }
        }

        window.clear();

        window.draw(shape);
        window.draw(*button.get());

        window.display();

    }

    return 0;
}