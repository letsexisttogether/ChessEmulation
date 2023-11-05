#pragma once

#include "Graphic/Controllable/Controllable.hpp"

template<class _Result>
class Button : public Controllable
{
public:
    Button() = default;

    Button(const sf::Texture& texture, const sf::Vector2f& position)
        : Controllable{ texture, position }
    {
        setPosition(position);
    }

    virtual ~Button() = default;

    virtual _Result OnPress() noexcept = 0; 
};
