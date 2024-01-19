#include "Sprite.hpp"

#include <iostream>

Sprite::Sprite(const TexturePointer texture, 
    const Position position)
    : Drawable{ texture, position } 
{}

