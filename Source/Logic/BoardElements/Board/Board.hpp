#pragma once

#include <vector>
#include <unordered_map>

#include "Logic/BoardElements/BoardCell/BoardCell.hpp"

class Board
{
public:
    Board() = delete;
    Board(const Board&) = delete;
    Board(Board&&) = delete;

    Board(std::unordered_map<std::pair<std::uint8_t, char>, BoardCell>&& cells);

    ~Board() = default;

    Board& operator = (const Board&) = delete;
    Board& operator = (Board&&) = delete;
    

    BoardCell& operator [] (const std::pair<std::uint8_t, char>& index) noexcept(false);

private:
	std::unordered_map<std::pair<std::uint8_t, char>, BoardCell> m_Cells;
};
 