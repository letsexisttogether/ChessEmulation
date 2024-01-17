#include "Placable.hpp"

#include <stdexcept>

#include "Graphic/Placable/PositionLocation.hpp"

Placable::Placable(const Placable& placable)
    : m_Origin{ placable.m_Origin }, m_Size{ placable.m_Size }
{}

Placable::Placable(const Position origin, const Size size)
    : m_Origin{ origin }, m_Size{ size }
{}

const Placable::Position& Placable::GetOrigin() const noexcept
{
    return m_Origin;
}

void Placable::SetOrigin(const Position origin) noexcept
{
    m_Origin = origin;
}

const Placable::Size& Placable::GetSize() const noexcept
{
    return m_Size;
}

void Placable::SetSize(const Size size) noexcept
{
    m_Size = size;
}

const Placable::Position 
    Placable::GetPosition(const PositionLocation location) 
    const noexcept(false)
{
    switch (location)
    {
        case PositionLocation::CENTER:
            return { m_Origin };

        case PositionLocation::UP_RIGHT:
            return { m_Origin.x + m_Size.x, m_Origin.y - m_Size.y };

        case PositionLocation::UP_LEFT:
            return { m_Origin.x - m_Size.x, m_Origin.y - m_Size.y };

        case PositionLocation::DOWN_RIGHT:
            return { m_Origin.x + m_Size.x, m_Origin.y + m_Size.y };

        case PositionLocation::DOWN_LEFT:
            return { m_Origin.x - m_Size.x, m_Origin.y + m_Size.y };
    }

    throw std::runtime_error{ "This enum value was not supposed to be here" };

    return Position{};
}

const Placable::Vertex 
Placable::GetVertex(const PositionLocation location)
    const noexcept(false)
{
    Position position{ GetPosition(location) };

    return { position, position };
}

Placable& Placable::operator = (const Placable& placable)
{
    m_Origin = placable.m_Origin;
    m_Size = placable.m_Size;

    return *this;
}
