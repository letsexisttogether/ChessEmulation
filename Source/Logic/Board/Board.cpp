#include "Board.hpp"

#include <algorithm>
#include <stdexcept>

Board::Board(Board&& board)
    : Sprite{ std::move(board) }, m_Cells{ std::move(board.m_Cells) }
{}

Board::Board(const TexturePointer texture, const Position position)
    : Sprite{ texture, position }
{}

Board::Board(CellSet&& cells)
    : m_Cells{ std::move(cells) }
{}

Board::Board(CellSet&& cells, const TexturePointer texture,
    const Position position)
    : Sprite{ texture, position }, m_Cells{ std::move(cells) }
{}

void Board::AddCell(BoardCell&& cell) noexcept(false)
{
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

const BoardCell& Board::operator[] (const BoardCellIndex& index) const noexcept(false)
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