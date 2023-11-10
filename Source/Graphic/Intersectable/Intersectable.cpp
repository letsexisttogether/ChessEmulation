#include "Intersectable.hpp"

Controllable::Controllable(const sf::Vector2f& position)
{
    setPosition(position); 
}

Controllable::Controllable(const sf::Texture& texture)
    : sf::Sprite{ texture }
{}

Controllable::Controllable(const sf::Texture& texture, const sf::Vector2f& position)
    : sf::Sprite{ texture }
{
    setPosition(position); 
}

bool Controllable::IsIntersected(const Controller& controller) const noexcept
{
    const sf::Vector2i& controllerPosition = controller.GetPosition();

    const sf::Vector2f& objPosition = getPosition();
    const sf::Vector2i objSize{ getTexture()->getSize() }; 

    const sf::Vector2i leftUpBorder
    {
        static_cast<std::int32_t>(objPosition.x),
        static_cast<std::int32_t>(objPosition.y)
    };
    const sf::Vector2i rightDownBorder
    { 
        leftUpBorder.x + objSize.x,
        leftUpBorder.y + objSize.y
    };

    return controllerPosition.x >= leftUpBorder.x 
        && controllerPosition.x <= rightDownBorder.x
        && controllerPosition.y >= leftUpBorder.y 
        && controllerPosition.y <= rightDownBorder.y;
}
