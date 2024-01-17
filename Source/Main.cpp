#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "Application/Application.hpp"
#include "Graphic/Drawable/Drawable.hpp"
#include "Spawn/Scene/Console/ConsoleSceneSpawner.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "The new window");

    Drawable::TexturePointer texture{ new sf::Texture{} };
    texture->loadFromFile("D:\\Important\\Projects\\ChessEmulation\\Resourses\\queen.png");

    Drawable drawable{ texture, { 100.f, 100.f } };

    Drawable me{ texture, { 50.f, 50.f } };
 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
 
        window.clear();
 
        window.draw(drawable);
        window.draw(me);
 
        window.display();
    }
    return EXIT_SUCCESS;
}