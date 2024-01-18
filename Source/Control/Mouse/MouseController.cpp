#include "MouseController.hpp"

#include <SFML/Window/Mouse.hpp>

#include "Application/Application.hpp"

MouseController::MouseController(const TexturePointer texture)
    : Controller{ texture }
{}

// This version of the method is a piece of my mourning creation
// I will change in the future, when all the controllers are implemented
void MouseController::Control() noexcept(false)
{
    UpdatePosition();

    sf::RenderWindow& window = Application::GetInstance().GetWindow();

    if (sf::Event event; window.pollEvent(event) 
            && event.type == sf::Event::MouseButtonReleased
            && event.mouseButton.button == sf::Mouse::Left)
    {
        Intersectable* intersectable = GetPossibleIntersectable();


        if (intersectable)
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
