#include "Application.hpp"

#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>

#include "SFML/Graphics/RenderWindow.hpp"
#include "Spawn/Scene/Game/GameSceneSpawner.hpp"

Application& Application::GetInstance() noexcept
{
    static Application instance{};

    return instance;
}

void Application::CarryTheBoatsAndTheLogs() noexcept
{
    while(m_Window->isOpen() && m_Scene->IsWorking())
    {
        try
        {
            m_Scene->UpdateLogic(); 

            m_Window->clear();
            m_Scene->UpdateGraphic();
            m_Window->display();
        }
        catch (std::exception& exp)
        {
            std::cerr << exp.what() << std::endl;

            m_Scene->SetWorking(false);
        }
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));

    m_Window->close();

    std::cout << "Have a nice day" << std::endl;
}

Scene& Application::GetScene() noexcept(false)
{
    CheckScene();

    return *m_Scene;
}

const Scene& Application::GetScene() const noexcept(false)
{
    CheckScene();

    return *m_Scene; 
}

sf::RenderWindow& Application::GetWindow() noexcept(false)
{
    CheckWindow();

    return *m_Window;
}
const sf::RenderWindow& Application::GetWindow() const noexcept(false)
{
    CheckWindow();

    return *m_Window;
}

// Change it when the time comes
Application::Application()
{
    m_Window.reset(new sf::RenderWindow
        { 
            sf::VideoMode{ 1920, 1080 },
            "The new window",
        });

    m_Window->setMouseCursorVisible(false);

    std::unique_ptr<SceneSpawner> spawner{ new GameSceneSpawner{ *m_Window } };

    m_Scene.reset(spawner->SpawnScene());
}

void Application::CheckScene() const noexcept(false)
{
    if (!m_Scene)
    {
        throw std::runtime_error{ "The scene is not initialized" };
    }
}

void Application::CheckWindow() const noexcept(false)
{
    if (!m_Scene)
    {
        throw std::runtime_error{ "The window is not initialized" };
    }
}
