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
    Board(const Board&) = delete;
    Board(Board&& board);

    Board(CellSet&& cells);

    Board(const TexturePointer texture, 
        const Position position);

    Board(CellSet&& cells, const TexturePointer texture,
        const Position position);

    ~Board() = default;

    void AddCell(BoardCell&& cell) noexcept(false);

    CellSet& GetCells() noexcept;
    const CellSet& GetCells() const noexcept;

    Board& operator = (const Board&) = delete;
    Board& operator = (Board&&) = delete;
    
    const BoardCell& operator [] (const BoardCellIndex& index) 
        const noexcept(false);
    BoardCell& operator [] (const BoardCellIndex& index) 
        noexcept(false);

private:
	CellSet m_Cells{};
};
 