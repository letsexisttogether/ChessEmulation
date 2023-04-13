#include "Board.hpp"

Board::Board(std::unordered_set<BoardCell, BoardCell::IndexHash, BoardCell::IndexEqual>&& cells)
    : m_Cells{ std::move(cells) }
{}

BoardCell& Board::GetCell(const std::pair<uint8_t, char> &index)
{
    auto it = std::find_if(m_Cells.begin(), m_Cells.end(), [&](const BoardCell& cell)
    {
        return cell.GetIndex() == index;
    });

    if (it == m_Cells.end())
    {
        throw std::runtime_error("Cell with index like that does not exist");
    }

    return *const_cast<BoardCell*>(it);
}
