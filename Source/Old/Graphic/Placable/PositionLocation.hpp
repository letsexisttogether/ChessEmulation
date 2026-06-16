#pragma once

#include <cstdint>

enum class PositionLocation : std::uint8_t
{
    CENTER, 

    UP_RIGHT,
    UP_LEFT,

    DOWN_RIGHT,
    DOWN_LEFT
};
