#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
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

    Scene& GetScene() noexcept(false);
    const Scene& GetScene() const noexcept(false);

    sf::RenderWindow& GetWindow() noexcept(false);
    const sf::RenderWindow& GetWindow() const noexcept(false);

private:
    Application();

    ~Application() = default; 

    void CheckScene() const noexcept(false);
    void CheckWindow() const noexcept(false);

private:
    std::unique_ptr<Scene> m_Scene{};
    std::unique_ptr<sf::RenderWindow> m_Window{};
};
