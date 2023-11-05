#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

class Controller
{
public:
    using Position = sf::Vector2i; 

public:
    Controller() = default; 

    virtual ~Controller() = default;

    virtual const Position& GetPosition() const noexcept = 0;
    virtual void SetPosition(const Position& position) noexcept = 0;

    virtual bool IsActive(const sf::Event& event) const noexcept = 0;
};
