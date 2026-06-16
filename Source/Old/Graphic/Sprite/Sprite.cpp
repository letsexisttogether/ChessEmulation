#include "Sprite.hpp"

Sprite::Sprite(Sprite&& sprite)
    : Drawable{ std::move(sprite) }
{}

Sprite::Sprite(const TexturePointer texture, 
    const Position position)
    : Drawable{ texture, position } 
{}

