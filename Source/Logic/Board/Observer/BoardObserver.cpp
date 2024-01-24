#include "BoardObserver.hpp"

#include "Logic/Board/Board.hpp"

#include <algorithm>
#include <stdexcept>
#include <iostream>

void BoardObserver::SetBoard(Board& board) noexcept(false)
{
    m_Board = &board;

    for (const BoardCell& cell : m_Board->GetCells())
    {
        if (!cell.IsFree())
        {
            AddCell(cell);
        }
    }
}

void BoardObserver::AddCell(const BoardCell& cell) noexcept(false)
{
    cell.CheckPiece();

    const Piece& piece = cell.GetPiece();
    const PieceSide side = piece.GetSide();
    const PieceType type = piece.GetType();

    IndexContainer& container = GetIndices(side);
    container.emplace(type, cell.GetIndex());
}

void BoardObserver::UpdateCell(const BoardCellIndex& oldIndex,
    const BoardCell& newCell)
{
    newCell.CheckPiece();

    const PieceSide side = newCell.GetPiece().GetSide();
    const PieceType type = newCell.GetPiece().GetType();

    auto iter = FindIndex(oldIndex, side);

    iter->second = newCell.GetIndex();
}

void BoardObserver::DeleteCell(const PieceSide side, 
        const PieceType type) noexcept(false)
{
    auto iter = FindIndex(side, type);

    IndexContainer& cells = GetIndices(side);

    cells.erase(iter);
}

BoardCell& BoardObserver::GetCell(const PieceSide side, 
    const PieceType type) noexcept(false)
{
    const auto iter = FindIndex(side, type);

    BoardCell& cell = (*m_Board)[iter->second];

    cell.CheckPiece();

    return cell;
}

BoardObserver::IndexContainer& 
    BoardObserver::GetIndices(const PieceSide side)
{
    if (side == PieceSide::WHITE)
    {
        return m_WhitePieces;
    }

    return m_BlackPieces;
}

BoardObserver::IndexContainer::iterator
    BoardObserver::FindIndex(const PieceSide side, 
    const PieceType type) noexcept(false)
{
    CheckBoard();

    IndexContainer& indices = GetIndices(side);

    auto iter = indices.find(type);

    if (iter == indices.end())
    {
        throw std::runtime_error
        {
            "BoardObserver: Such a piece is dead by now"
        };
    }

    return iter;
}

BoardObserver::IndexContainer::iterator 
    BoardObserver::FindIndex(const BoardCellIndex& index, 
    const PieceSide side) noexcept(false)
{
    IndexContainer& indices = GetIndices(side);

    auto iter = std::find_if(indices.begin(), indices.end(), 
        [=] (const auto& element)
        {
            return element.second == index; 
        });

    if (iter == indices.end())
    {
        throw std::runtime_error
        {
            "BoardObserver: Such a piece is dead by now"
        };
    }

    return iter;
}

void BoardObserver::CheckBoard() const noexcept(false)
{
    if (!m_Board)
    {
        throw std::runtime_error
        {
            "BoardObserver: The board is not specified"
        };
    }
}
