#pragma once

#include <unordered_set>

#include "Graphic/Drawable/Drawable.hpp"
#include "Logic/Board/Cell/BoardCell.hpp"
#include "Observer/BoardObserver.hpp"

class Board : public Drawable 
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

    BoardObserver& GetObserver() noexcept;

    bool IsKingSafe(const PieceSide side, 
        const bool shouldCheckKingFurther = false) 
        noexcept(false);

    bool IsInBoundries(const BoardCellIndex& index) const noexcept;
    void SetBoundires(const BoardCellIndex& boundries,
        const bool isMax = true) noexcept;

    Board& operator = (const Board&) = delete;
    Board& operator = (Board&&) = delete;
    
    const BoardCell& operator [] (const BoardCellIndex& index) 
        const noexcept(false);
    BoardCell& operator [] (const BoardCellIndex& index) 
        noexcept(false);

private:
	CellSet m_Cells{};

    BoardCellIndex m_MinBoundries{ 1, 1 };
    BoardCellIndex m_MaxBoundries{ 8, 8 };

    BoardObserver m_Observer{};
};
 