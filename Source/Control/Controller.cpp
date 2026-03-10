#include "Controller.hpp"

#include "Application/Application.hpp"
#include "Application/Scenes/Scene.hpp"

MouseController::MouseController(const TexturePointer texture) noexcept(false)
    : Sprite{ texture }, m_Window{ Application::GetInstance().GetWindow() }
{
    m_Window.setMouseCursorVisible(false);
}

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
        if (auto intersectable = GetPossibleIntersectable())
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

Intersectable* MouseController::GetPossibleIntersectable()
    const noexcept(false)
{
    const auto& scene = Application::GetInstance().GetScene();
    
    for (auto intersectable : scene.GetIntersectables())
    {
        if (IsIntersected(*intersectable))
        {
            return intersectable;
        }
    }

    return {};
}

void MouseController::UpdatePosition() noexcept
{
    const auto mousePosition = static_cast<Position>
        (sf::Mouse::getPosition(m_Window));

    SetOrigin(mousePosition);
}
