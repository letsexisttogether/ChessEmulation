#pragma once

#include <SFML/Graphics.hpp>

template<class _Result>
class Button : public sf::Sprite
{
public:
    Button() = default;

    Button(const sf::Texture& texture)
        : sf::Sprite{ texture }
    {}
    Button(const sf::Texture& texture, const sf::Vector2f& position)
        : sf::Sprite{ texture }
    {
        setPosition(position);
    }

    virtual ~Button() = default;

    virtual _Result Press() noexcept = 0; 

    virtual bool IsIntersected(const sf::Vector2i& position) const noexcept = 0;
};
