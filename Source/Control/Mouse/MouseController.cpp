#include "MouseController.hpp"

#include <SFML/Window/Mouse.hpp>

MouseController::MouseController(Window& window, const TexturePointer texture)
    : Controller{ window, texture }
{}

// This version of the method is a piece of my mourning creation
// I will change in the future, when all the controllers are implemented
void MouseController::Control() noexcept(false)
{
    UpdatePosition();

    sf::Event event{};

    while(m_Window.pollEvent(event));

    if (event.type == sf::Event::MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Left)
    {
        if (Intersectable* intersectable = GetPossibleIntersectable())
        {
            intersectable->OnInteract();
        }
    }
}

bool MouseController::IsIntersected(const Intersectable& intersectabla)
    const noexcept
{
    const Position arrowPosition{ GetPosition(PositionLocation::UP_LEFT) };

    const Position intersectablaUpRight
    { 
        intersectabla.GetPosition(PositionLocation::UP_RIGHT)
    };
    const Position intersecatblaDownLeft 
    {
        intersectabla.GetPosition(PositionLocation::DOWN_LEFT)
    };

    const bool isXIntersected = (intersectablaUpRight.x >= arrowPosition.x
        && intersecatblaDownLeft.x <= arrowPosition.x);

    const bool isYIntersected = (intersectablaUpRight.y <= arrowPosition.y
        && intersecatblaDownLeft.y >= arrowPosition.y);

    return isXIntersected && isYIntersected;
}

void MouseController::UpdatePosition() noexcept
{
    const Position mousePosition
    {
        static_cast<Position>(sf::Mouse::getPosition(m_Window))
    };

    SetOrigin(mousePosition);
}
