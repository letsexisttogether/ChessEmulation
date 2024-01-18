#include <ios>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "Application/Application.hpp"
#include "Control//Mouse/MouseController.hpp"
#include "Graphic/Sprite/Sprite.hpp"

int main()
{
    Application& application = Application::GetInstance();

    sf::RenderWindow& window{ application.GetWindow() };

    Drawable::TexturePointer texture{ new sf::Texture{} };
    texture->loadFromFile("D:\\Important\\Projects\\ChessEmulation\\Resourses\\queen.png");

    Sprite sprite{ texture, { 100.f, 100.f } };

    Drawable::TexturePointer mouseTexture{ new sf::Texture{} };
    mouseTexture->loadFromFile("D:\\Important\\Projects\\ChessEmulation\\Resourses\\cursor.png");

    std::unique_ptr<Controller> controller{ new MouseController{ mouseTexture } };
    
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

        controller->Control(event);

        window.clear();

        window.draw(sprite);

        window.draw(*controller);

        window.display();
    }

    return EXIT_SUCCESS;
}