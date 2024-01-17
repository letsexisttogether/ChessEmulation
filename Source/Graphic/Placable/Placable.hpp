#pragma once

#include <SFML/Graphics/Vertex.hpp>
#include <vector>

#include "PositionLocation.hpp"

// An object of the class is representing a square
// with origin in the center and size
class Placable
{
public:
    using Position = sf::Vector2f;
    using Size = sf::Vector2f;

    using Vertex = sf::Vertex;
    
public:
    Placable() = default;
    Placable(const Placable& placable);
    Placable(Placable&&) = default;

    Placable(const Position origin, const Size size);
    
    virtual ~Placable() = default;

    const Position& GetOrigin() const noexcept;
    void SetOrigin(const Position origin) noexcept;

    const Size& GetSize() const noexcept;
    void SetSize(const Size size) noexcept;

    const Position GetPosition(const PositionLocation location) 
        const noexcept(false);

    const Vertex GetVertex(const PositionLocation location)
        const noexcept(false);

    Placable& operator = (const Placable& placable);
    Placable& operator = (Placable&&) = default;
    
protected:
    Position m_Origin{};
    Size m_Size{};
};
