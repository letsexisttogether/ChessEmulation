#pragma once

#include <cstdint>
#include <tuple>

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

    /**
    * @details Does not check for piece being empty
    */
    auto IsSameColor(const Piece& piece) const noexcept -> bool;

    auto GetType() const noexcept -> PieceType;
    auto IsWhite() const noexcept -> bool;

    auto AsPack() const noexcept -> std::tuple<PieceType, bool>;

    explicit operator bool () const noexcept;

private:
    Piece() = default;

private:
    RawPiece m_RawPiece{};
};
