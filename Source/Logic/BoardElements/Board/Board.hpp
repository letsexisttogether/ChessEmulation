#pragma once

#include <vector>
#include <unordered_set>

#include "Logic/BoardElements/BoardCell/BoardCell.hpp"

class Board
{
public: 
    using CellSet = std::unordered_set<BoardCell, BoardCell::IndexHash, BoardCell::IndexEqual>;

public:
    Board() = delete;
    Board(const Board&) = delete;
    Board(Board&&) = delete;

    Board(CellSet&& cells);

    ~Board() = default;

    Board& operator = (const Board&) = delete;
    Board& operator = (Board&&) = delete;
    

    BoardCell& operator [] (const BoardCell::Index& index) noexcept(false);

private:
	CellSet m_Cells;
};
 