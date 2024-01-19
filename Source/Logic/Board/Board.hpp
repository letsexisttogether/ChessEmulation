#pragma once

#include <unordered_set>

#include "Graphic/Sprite/Sprite.hpp"
#include "Logic/Board/Cell/BoardCell.hpp"

class Board : public Sprite 
{
public: 
    using CellSet = std::unordered_set<BoardCell, 
          BoardCell::IndexHash, BoardCell::IndexEqual>;

public:
    Board() = default;
    // Change later 
    Board(const Board&) = default;
    Board(Board&&) = default;

    Board(CellSet&& cells);
    Board(CellSet&& cells, const TexturePointer texture,
        const Position position);

    ~Board() = default;

    void AddCell(BoardCell&& cell) noexcept(false);
    
    Board& operator = (const Board&) = delete;
    Board& operator = (Board&&) = delete;
    
    const BoardCell& operator [] (const BoardCellIndex& index) 
        const noexcept(false);
    BoardCell& operator [] (const BoardCellIndex& index) 
        noexcept(false);

private:
	CellSet m_Cells{};
};
 