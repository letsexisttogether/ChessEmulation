#include "MenuScene.hpp"

#include <iostream>

#include "Application/Application.hpp"
#include "Control/Mouse/MouseController.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "UI/Buttons/Button.hpp"

MenuScene::MenuScene()
{
    Drawable::TexturePointer texture{ new sf::Texture{} };
    texture->loadFromFile("D:\\Important\\Projects\\ChessEmulation\\Resourses\\button.png");

    Button* printButton = new Button
    { 
        texture, { 400.f, 100.f },
        [] () { std::cout << "Hello, I am pressing the button with controller\n"; }
    };

    Button* exitButton = new Button
    { 
        texture, { 400.f, 300.f },
        [this] () 
        { 
            SetWorking(false);
        }
    };

    Drawable::TexturePointer mouseTexture{ new sf::Texture{} };
    mouseTexture->loadFromFile("D:\\Important\\Projects\\ChessEmulation\\Resourses\\cursor.png");

    m_Controller.reset(new MouseController{ mouseTexture });

    AddIntersectable(printButton);
    AddDrawable(printButton);

    AddIntersectable(exitButton);
    AddDrawable(exitButton);

    AddDrawable(m_Controller.get());
}

void MenuScene::UpdateLogic() noexcept(false) 
{
    sf::RenderWindow& window = Application::GetInstance().GetWindow();

    for(sf::Event event; window.pollEvent(event); )
    {
        m_Controller->Control(event); 
    }
}
