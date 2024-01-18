#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "Graphic/Sprite/Sprite.hpp"

class Controller : public Sprite
{ 
public:
    Controller() = delete; 

    Controller(const TexturePointer texture, 
        const Position position = Position{});

    virtual ~Controller() = default;

    virtual void Control(const sf::Event event) noexcept(false) = 0;

    Intersectable* GetPossibleIntersectable() const noexcept(false);
};
