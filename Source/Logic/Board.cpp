#include "Board.hpp"

#include <stdexcept>

BoardCell::BoardCell(const RankType rank, const FileType file)
    : Rank{ rank }, File{ file }
{
    if (Rank < MinRank || Rank > MaxRank)
    {
        throw std::logic_error{ "[BoardCell] Rank is out of the scope " };
    }

    if (File < MinFile || File > MaxFile)
    {
        throw std::logic_error{ "[BoardCell] File is out of scope " };
    }
}

Board::Board(const RawBoard& board) noexcept : m_Board{ board } {}

auto Board::GetCellContent(const BoardCell cell) const -> Piece
{ 
    const auto& [rank, file] = cell;

    const auto row = m_Board[file - BoardCell::MinFile];

    const auto shift = (rank - BoardCell::MinRank) * BytesPerCell;
    const auto rawPiece = (row >> shift) & 0xF;

    return static_cast<Piece>(rawPiece);
}
