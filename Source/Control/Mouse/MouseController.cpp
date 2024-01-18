#include "MouseController.hpp"

#include <SFML/Window/Mouse.hpp>

#include "Application/Application.hpp"

MouseController::MouseController(const TexturePointer texture)
    : Controller{ texture }
{}

// This version of the method is a piece of my mourning creation
// I will change in the future, when all the controllers are implemented
void MouseController::Control(const sf::Event event) noexcept(false)
{
    UpdatePosition();

    sf::RenderWindow& window = Application::GetInstance().GetWindow();

    if (event.type == sf::Event::MouseButtonReleased
            && event.mouseButton.button == sf::Mouse::Left)
    {
        if (Intersectable* intersectable = GetPossibleIntersectable())
        {
            intersectable->OnInteract();
        }
    }
}

void MouseController::UpdatePosition() noexcept
{
    const sf::RenderWindow& window = Application::GetInstance().GetWindow();

    const Position mousePosition
    {
        static_cast<Position>(sf::Mouse::getPosition(window))
    };

    SetOrigin(mousePosition);
}
