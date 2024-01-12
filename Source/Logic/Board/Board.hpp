#pragma once

#include <unordered_set>

#include "Logic/Board/Cell/BoardCell.hpp"

class Board : public Drawable
{
public: 
    using CellSet = std::unordered_set<BoardCell, 
          BoardCell::IndexHash, BoardCell::IndexEqual>;

public:
    Board() = default;
    Board(const Board&) = default;
    Board(Board&&) = default;

    Board(CellSet&& cells);

    ~Board() = default;

    void AddCell(BoardCell&& cell) noexcept;
    
    Board& operator = (const Board&) = delete;
    Board& operator = (Board&&) = delete;
    
    const BoardCell& operator [] (const BoardCellIndex& index) const noexcept(false);
    BoardCell& operator [] (const BoardCellIndex& index) noexcept(false);

private:
	CellSet m_Cells{};
};
 