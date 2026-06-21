#include "Piece.hpp"

Piece::Piece(const RawPiece rawPiece) noexcept
    : m_RawPiece{ rawPiece } 
{}

Piece::Piece(const PieceType type, const bool isWhite) noexcept
    : m_RawPiece((0x8 & isWhite) | (0x7 & type))
{}

auto Piece::GetPieceType() const noexcept -> PieceType
{
    return static_cast<PieceType>(m_RawPiece & 0x7);
}

auto Piece::IsWhite() const noexcept -> bool
{
    return m_RawPiece & 0x8;
}
