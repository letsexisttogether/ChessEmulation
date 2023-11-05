#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

#include "UI/Buttons/SimpleButton/SimpleButton.hpp"
#include "Control/MouseController/MouseController.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");

    std::unique_ptr<Controller> controller{ new MouseController{ window } };

    sf::Texture texture{};
    texture.loadFromFile("D:/Important/Programming/Solo/ChessEmulation/Resourses/button.png");

    using MenuButton = std::unique_ptr<Button<void>>;

    std::vector<MenuButton> buttons{};

    buttons.push_back(MenuButton{ new SimpleButton<void>
            {
                texture, { 50.f, 100.f },
                [&]() -> void { window.clear(sf::Color::Green); }
            }});
    buttons.push_back(MenuButton{ new SimpleButton<void>
            {
                texture, { 50.f, 300.f },
                [&]() -> void { window.clear(sf::Color::Blue); }
            }});

    while (window.isOpen()) 
    {
        for (sf::Event event; window.pollEvent(event); ) 
        {
            sf::Event::EventType type{ event.type };

            if (type == sf::Event::Closed)
            {
                window.close();
            }

            for (const auto& button : buttons)
            {
                if (controller->IsActive(event) 
                        && button->IsIntersected(*controller))
                {
                    button->OnPress();
                }

            }

        }

        for (const auto& button : buttons)
        {
            window.draw(*button);
        }

        window.display();

    }

    return 0;
}