#include "Application.hpp"

#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Window.hpp"
#include "Scenes/Scene.hpp"

Application& Application::GetInstance() noexcept
{
    static Application instance{};

    return instance;
}

void Application::CarryTheBoatsAndTheLogs() noexcept
{
    while(m_Scene->IsWorking())
    {
        try
        {
           m_Scene->UpdateLogic(); 

           m_Scene->UpdateGraphic();
        }
        catch (std::exception& exp)
        {
            std::cerr << exp.what() << std::endl;
        }
    }

    std::cout << "Have a nice day" << std::endl;
}

Scene& Application::GetScene() noexcept
{
    return *m_Scene;
}
const Scene& Application::GetScene() const noexcept
{
    return *m_Scene; 
}

sf::RenderWindow& Application::GetWindow() noexcept
{
    return *m_Window;
}
const sf::RenderWindow& Application::GetWindow() const noexcept
{
    return *m_Window;
}

// Change it when the time comes
Application::Application()
{
    m_Window.reset(new sf::RenderWindow{ sf::VideoMode{ 800, 600 }, "The new window" });

    m_Window->setMouseCursorVisible(false);
}
