#pragma once

#include <vector>
#include <unordered_set>

#include "Logic/BoardElements/BoardCell/BoardCell.hpp"

class Board
{
public:
    Board() = delete;
    Board(const Board&) = delete;
    Board(Board&&) = delete;

    Board(std::unordered_set<BoardCell, BoardCell::IndexHash, BoardCell::IndexEqual>&& cells);\

    ~Board() = default;

    Board& operator = (const Board&) = delete;
    Board& operator = (Board&&) = delete;
    

private:
    BoardCell& GetCell(const std::pair<uint8_t, char>& index);

private:
	std::unordered_set<BoardCell, BoardCell::IndexHash, BoardCell::IndexEqual> m_Cells;
};
 