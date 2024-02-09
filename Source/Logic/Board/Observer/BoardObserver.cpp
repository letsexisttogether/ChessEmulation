#include "BoardObserver.hpp"

#include "Logic/Board/Board.hpp"

#include <iostream>
#include <algorithm>
#include <stdexcept>

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

    std::cout << "AddCell() start\n";

    const Piece& piece = cell.GetPiece();
    const PieceSide side = piece.GetSide();
    const PieceType type = piece.GetType();


    IndexContainer& container = GetIndices(side);
    container.emplace(type, cell.GetIndex());

    std::cout << "AddCell() end\n";
}

void BoardObserver::UpdateCell(const BoardCellIndex& oldIndex,
    const BoardCell& newCell) noexcept(false)
{
    newCell.CheckPiece();

    const PieceSide side = newCell.GetPiece().GetSide();
    const PieceType type = newCell.GetPiece().GetType();

    auto iter = FindIndex(oldIndex, side);

    iter->second = newCell.GetIndex();
}

void BoardObserver::DeleteCell(const BoardCellIndex& index, 
    const PieceSide side) noexcept(false)
{
    std::cout << "DeleteCell() start\n";

    auto iter = FindIndex(index, side);

    IndexContainer& cells = GetIndices(side);

    cells.erase(iter);

    std::cout << "DeleteCell() end\n";
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

    std::cout << "SEARCH STARTED\n";

    auto iter = indices.find(type);

    std::cout << "SEARCH ENDED\n";

    if (iter == indices.end())
    {
        std::cerr << static_cast<std::int32_t>(side) << ' ' 
            << static_cast<std::int32_t>(type) << std::endl;

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

    std::cout << "SEARCH STARTED\n";

    auto iter = std::find_if(indices.begin(), indices.end(), 
        [=] (const auto& element)
        {
            return element.second == index; 
        });

    if (iter == indices.end())
    {
        std::cerr << static_cast<std::int32_t>(side) << std::endl;

        throw std::runtime_error
        {
            "BoardObserver: Such a piece is dead by now"
        };
    }

    std::cout << "SEARCH ENDED\n";

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
