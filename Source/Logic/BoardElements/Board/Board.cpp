#include "Board.hpp"

Board::Board(std::unordered_map<std::pair<std::uint8_t, char>, BoardCell>&& cells)
    : m_Cells{ std::move(cells) }
{}

BoardCell& Board::operator[](const std::pair<std::uint8_t, char>& index) noexcept(false)
{
    auto it = m_Cells.find(index);

    if (it == m_Cells.end())
    {
        throw std::runtime_error{ "There is not a cell with index like that" };
    }

    return it->second;
}