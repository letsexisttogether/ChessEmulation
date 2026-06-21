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


auto Board::CreateDefaultBoard() -> Board
{
    return Board
    {
        {
            0xABCDECBA,
            0x99999999, 
            0x00000000, 
            0x00000000, 
            0x00000000, 
            0x00000000, 
            0x11111111,
            0x23456432
        }
    };
}

Board::Board(const RawBoard& board) noexcept : m_Board{ board } {}

auto Board::GetCellContent(const BoardCell cell) const -> Piece
{ 
    const auto& [rank, file] = cell;

    const auto row = m_Board[file - BoardCell::MinFile];

    const auto shift = (rank - BoardCell::MinRank) * BytesPerCell;
    const auto rawPiece = (row >> shift) & PieceMask;

    return static_cast<Piece>(rawPiece);
}

auto Board::Move(const BoardCell fromCell, const BoardCell toCell) -> void
{
    const auto& [fromRank, fromFile] = fromCell;
    const auto& [toRank, toFile] = toCell;

    auto& fromRow = m_Board[fromFile - BoardCell::MinFile];
    const auto fromShift = (fromRank - BoardCell::MinRank) * BytesPerCell;
    const auto fromRawPiece = (fromRow >> fromShift) & PieceMask;

    auto& toRow = m_Board[toFile - BoardCell::MinFile];
    const auto toShift = (toRank - BoardCell::MinRank) * BytesPerCell;

    toRow &= ~(PieceMask << toShift);
    toRow |= fromRawPiece << toShift;

    fromRow &= ~(PieceMask << fromShift);
}
