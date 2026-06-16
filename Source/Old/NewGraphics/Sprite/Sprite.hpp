#pragma once

#include <memory>

#include <SFML/Graphics/Sprite.hpp>

#include "../Drawable/Drawable.hpp"
#include "../Intersectable/Intersectable.hpp"
#include "../Interactable/Interactable.hpp"

GraphicsSpaceStart

class Sprite : public Drawable, public Intersectable, public Interactable
{
public:
    Sprite() = delete;
    Sprite(const Sprite&) = default;
    Sprite(Sprite&&) = default;

    Sprite(Drawable&& drawable, Intersectable&& intersectable,
        Interactable&& interactable) noexcept;

    ~Sprite() = default;

    Sprite& operator = (const Sprite&) = default;
    Sprite& operator = (Sprite&&) = default;
};

GraphicsSpaceEnd
