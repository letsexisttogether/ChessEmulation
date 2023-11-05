#pragma once

#include <SFML/Graphics.hpp>

class Button : public sf::Sprite
{
public:
    Button() = delete;
    Button(const Button&) = delete;
    Button(Button&&) = delete; 

    Button(const sf::Texture& texture)
        : sf::Sprite{ texture }
    {}

    virtual ~Button() = default;

    virtual void Press() noexcept = 0; 

    virtual bool IsIntersected(const sf::Vector2i& position) const noexcept = 0;
};
