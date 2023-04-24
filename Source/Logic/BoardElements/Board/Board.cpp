#include "Board.hpp"

#include <algorithm>

Board::Board(CellSet&& cells)
    : m_Cells{ std::move(cells) }
{}

const BoardCell& Board::operator[] (const CellIndex& index) const noexcept(false)
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

    // Const is experemental here
    return *it;
}