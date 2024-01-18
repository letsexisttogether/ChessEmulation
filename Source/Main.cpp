#include <ios>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "Application/Application.hpp"
#include "Graphic/Drawable/Drawable.hpp"
#include "Graphic/Intersectable/Intersectable.hpp"
#include "Spawn/Scene/Console/ConsoleSceneSpawner.hpp"

class Sprite : public Intersectable, public Drawable
{
public:
    Sprite(const Drawable::TexturePointer& texture, const Position& position)
        : Intersectable{ position },
        Drawable{ texture }
    {}

    virtual ~Sprite() = default;
};


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "The new window");

    Drawable::TexturePointer texture{ new sf::Texture{} };
    texture->loadFromFile("D:\\Important\\Projects\\ChessEmulation\\Resourses\\queen.png");

    Drawable sprite{ texture, { 100.f, 100.f } };

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

        window.draw(sprite);

        window.display();
    }

    return EXIT_SUCCESS;
}