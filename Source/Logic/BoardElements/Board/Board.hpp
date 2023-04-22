#pragma once

#include <vector>
#include <unordered_set>

#include "Logic/BoardElements/BoardCell/BoardCell.hpp"

class Board
{
public: 
    using CellSet = std::unordered_set<BoardCell, BoardCell::Hash, BoardCell::Equal>;

public:
    Board() = delete;
    Board(const Board&) = default;
    Board(Board&&) = default;

    Board(CellSet&& cells);

    ~Board() = default;

    Board& operator = (const Board&) = delete;
    Board& operator = (Board&&) = delete;
    

    BoardCell& operator [] (const CellIndex& index) noexcept(false);

private:
	CellSet m_Cells;
};
 