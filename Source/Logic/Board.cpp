#include "Board.hpp"

#include <stdexcept>

Board::Board(const RawBoard& board) noexcept
    : m_Board{ board }
{}

auto Board::GetCellContent(const Rank rank, const File file)
    const -> Piece
{
    if (rank < MinRank || rank > MaxRank)
    {
        throw std::logic_error{ "Rank is out of the scope " };
    }
    if (file < MinFile || file > MaxFile)
    {
        throw std::logic_error{ "File is out of scope " };
    }
    
    const auto row = m_Board[file - MinFile];

    const auto shift = (rank - MinRank) * BytesPerCell;
    const auto rawPiece = (row >> shift) & 0xF;

    return static_cast<Piece>(rawPiece);
}
