#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Control/Controller.hpp"

class Controllable : public sf::Sprite
{
public:
    Controllable() = default;    
    Controllable(const Controllable&) = default;
    Controllable(Controllable&&) = default;

    Controllable(const sf::Vector2f& position);
    Controllable(const sf::Texture& texture);
    Controllable(const sf::Texture& texture, const sf::Vector2f& position);

    ~Controllable() = default;

    bool IsIntersected(const Controller& controller) const noexcept;

    Controllable& operator = (const Controllable&) = default;
    Controllable& operator = (Controllable&&) = default;
};
