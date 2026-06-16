#pragma once

#include "Graphic/Intersectable/Intersectable.hpp"
#include "Graphic/Drawable/Drawable.hpp"

class Sprite : public Intersectable, public Drawable 
{
public:
    Sprite() = default;;
    Sprite(const Sprite&) = default;
    Sprite(Sprite&& sprite);

    Sprite(const TexturePointer texture, 
        const Position position = Position{});

    virtual ~Sprite() = default;

    Sprite& operator = (const Sprite&) = default;
    Sprite& operator = (Sprite&&) = default;
};
