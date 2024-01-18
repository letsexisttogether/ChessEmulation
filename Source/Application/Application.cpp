#include "Application.hpp"

#include <iostream>

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

sf::Window& Application::GetWindow() noexcept
{
    return *m_Window;
}
const sf::Window& Application::GetWindow() const noexcept
{
    return *m_Window;
}

// Change it when the time comes
Application::Application() = default;
