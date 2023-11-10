#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Control/Controller.hpp"

class Intersectable : public sf::Sprite
{
public:
    Intersectable() = default;    
    Intersectable(const Intersectable&) = default;
    Intersectable(Intersectable&&) = default;

    Intersectable(const sf::Vector2f& position);
    Intersectable(const sf::Texture& texture);
    Intersectable(const sf::Texture& texture, const sf::Vector2f& position);

    ~Intersectable() = default;

    bool IsIntersected(const Controller& controller) const noexcept;
    
    virtual void OnIntersect(const Controller& controller) noexcept = 0;

    Intersectable& operator = (const Intersectable&) = default;
    Intersectable& operator = (Intersectable&&) = default;
};
