#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "Graphic/Sprite/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Controller : public Sprite
{ 
public:
    using Window = sf::RenderWindow;

public:
    Controller() = delete; 

    Controller(Window& window, const TexturePointer texture, 
        const Position position = Position{});

    virtual ~Controller() = default;

    virtual void Control() noexcept(false) = 0;

    virtual Intersectable* GetPossibleIntersectable() const noexcept(false);

protected:
    Window& m_Window;
};
