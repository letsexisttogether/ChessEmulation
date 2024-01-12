#include "Board.hpp"

#include <algorithm>
#include <stdexcept>

Board::Board(CellSet&& cells)
    : m_Cells{ std::move(cells) }
{}

void Board::AddCell(BoardCell&& cell) noexcept
{
    m_Cells.insert(cell);
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