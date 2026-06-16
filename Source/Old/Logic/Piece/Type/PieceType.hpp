#pragma once

#include <cstdint>

enum class PieceType : std::uint8_t
{
    PAWN,

    KING,
    QUEEN,

    ROOK,
    BISHOP,
    KNIGHT
};
