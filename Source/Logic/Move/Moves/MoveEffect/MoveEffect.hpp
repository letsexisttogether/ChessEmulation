#pragma once

#include <cstdint>

enum class MoveEffect : std::uint8_t
{
    NONE, 

    TRANSFER,
    ATTACK,

    PIECE_TRANSFER,

    // I will work on making it into the game someday 
    // EN_PASSANT,
    CASTLE
};
