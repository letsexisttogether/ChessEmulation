#pragma once

#include <cstdint>

#include <SFML/Graphics/Vertex.hpp>

#include "../Core.hpp"

GraphicsSpaceStart

/**
* @brief Location of a rectangle vertex
*/
enum class Location : std::uint8_t
{
    Center, 

    UpRight,
    UpLeft,

    DownRight,
    DownLeft
};


/**
* @brief Representable of a rectangular object
*/
struct Placable
{
    using Position = sf::Vector2f;
    using SizeType = sf::Vector2f;
    using RotationType = std::uint16_t;

    Placable() = default;
    Placable(const Placable&) = default;
    Placable(Placable&&) = default;

    Placable(const Position origin, const SizeType size,
        const RotationType rotation = 0) noexcept;

    Position GetPosition(const Location location) const noexcept;

    Placable& operator = (const Placable&) = default;
    Placable& operator = (Placable&&) = default;

    Position Origin{};
    SizeType Size{};
    RotationType Rotation{};

private:
    Position GetPositionForOffset(const Location location) const noexcept;
};

GraphicsSpaceEnd
