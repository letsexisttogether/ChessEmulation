#include "Sprite.hpp"

#include<type_traits>

GraphicsSpaceStart

Sprite::Sprite(Drawable&& drawable, Intersectable&& intersectable,
    Interactable&& interactable) noexcept
    : Drawable{ std::move(drawable) },
    Intersectable{ std::move(intersectable) }
{}

GraphicsSpaceEnd
