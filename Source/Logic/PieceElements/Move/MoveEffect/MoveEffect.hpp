#pragma once

#include <cstdint>

enum class MoveEffect : std::uint8_t
{
    NONE, 

    TRANSFER,
    ATTACK,

    EN_PASSANT,
    CASTLE
};
