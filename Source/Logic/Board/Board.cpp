#include "Board.hpp"
#include "Logic/Gameplay/SideHolder/PieceSideHolder.hpp"

#include <algorithm>
#include <stdexcept>
#include <iostream>

Board::Board(Board&& board)
    : Sprite{ std::move(board) }, m_Cells{ std::move(board.m_Cells) }
{
    m_Observer.SetBoard(*this);
}

Board::Board(const TexturePointer texture, const Position position)
    : Sprite{ texture, position }
{}

Board::Board(CellSet&& cells)
    : m_Cells{ std::move(cells) } 
{
    m_Observer.SetBoard(*this);
}

Board::Board(CellSet&& cells, const TexturePointer texture,
    const Position position)
    : Sprite{ texture, position }, m_Cells{ std::move(cells) }
{
    m_Observer.SetBoard(*this);
}

void Board::AddCell(BoardCell&& cell) noexcept(false)
{
    m_Observer.AddCell(cell);

    m_Cells.insert(std::move(cell));
}

Board::CellSet& Board::GetCells() noexcept
{
    return m_Cells;
}

const Board::CellSet& Board::GetCells() const noexcept
{
    return m_Cells;
}

BoardObserver& Board::GetObserver() noexcept
{
    return m_Observer;
}

bool Board::IsKingSafe(const PieceSide side) noexcept(false)
{
    const PieceSideHolder holder{ side };

    BoardCell& kingCell = m_Observer.GetCell(side, PieceType::KING);

    for (const auto& [type, index]
        : m_Observer.GetIndices(holder.GetOppositeSide()))
    {
        BoardCell& cell = operator[](index);

        std::cout << "I check the moves of\n"
            << static_cast<std::int32_t>(index.GetRank()) << ' '
            << static_cast<std::int32_t>(index.GetFile()) << '\n';
        for (Piece::MovePointer& move : cell.GetPiece().GetMoves())
        {
            if (move->IsConditionSatisfied(*this, cell, 
                kingCell, false))
            {
                return false;
            }
        }
    }

    return true;
}

const BoardCell& Board::operator[] (const BoardCellIndex& index) 
    const noexcept(false)
{
    auto findByIndexFunc = [&](const BoardCell& cell)
    {
        return cell.GetIndex() == index;
    };

    auto it = std::find_if(m_Cells.begin(), m_Cells.end(), findByIndexFunc);

    if (it == m_Cells.end())
    {
        throw std::runtime_error{ "There is not a cell with index like that" };
    }

    return *it;
}

BoardCell& Board::operator[](const BoardCellIndex& index)
{
    return const_cast<BoardCell&>(static_cast<const Board&>(*this)[index]);
}