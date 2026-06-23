#pragma once

#include <cstdint>

enum PieceType : std::uint8_t
{
    None = 0x0,
    Pawn,               // 0b001 
    Rook,               // 0b010
    Knight,             // 0b011
    Bishop,             // 0b100
    Queen,              // 0b101
    King                // 0b101
};

class Piece
{
public:
    using RawPiece = std::uint8_t;

public:
    explicit Piece(const RawPiece rawPiece) noexcept;
    Piece(const PieceType type, const bool isWhite) noexcept;

    auto GetPieceType() const noexcept -> PieceType;
    auto IsWhite() const noexcept -> bool;

private:
    RawPiece m_RawPiece{};
};
