#pragma once

#include <cstdint>

enum class MoveEffect : std::uint8_t
{
    NONE, 

    TRANSFER,
    ATTACK,

    PIECE_TRANSFER,

    EN_PASSANT,
    CASTLE
};
