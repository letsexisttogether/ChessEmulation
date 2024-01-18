#pragma once

#include <SFML/Window/Window.hpp>
#include <memory>

class SceneSpawner;
class Scene;

// Manages the scenes SetUp(), CleanUp() and Switch()
// I lied
// Who cares
// I'm the only dev of it
// I'm getting out of my mind
// I'm aaaaaaaa
// Cool
// What if anyone sees this beauty?
// Who cares?
// I don't
// Me neither
class Application final
{
public:
    static Application& GetInstance() noexcept;

    void CarryTheBoatsAndTheLogs() noexcept;

    Scene& GetScene() noexcept;
    const Scene& GetScene() const noexcept;

    sf::Window& GetWindow() noexcept;
    const sf::Window& GetWindow() const noexcept;

private:
    Application();

    ~Application() = default; 

private:
    std::unique_ptr<Scene> m_Scene{};
    std::unique_ptr<sf::Window> m_Window{};
};
