#pragma once

#include <utility>

#include "Logic/Board/Cell/BoardCell.hpp"

class GameObserver
{
public:
    using CellPointerPair = std::pair<BoardCell*, BoardCell*>;
    using CellReferencePair = std::pair<const BoardCell&, const BoardCell&>;
    
public:
    GameObserver() = default;
    GameObserver(const GameObserver&) = default;
    GameObserver(GameObserver&&) = default;

    ~GameObserver() = default;

    const CellPointerPair& GetCellPair() noexcept;
    CellReferencePair GetCellPair() const noexcept(false);

    void SetCell(BoardCell* cell) noexcept;
    
    void ClearCells() noexcept;

    bool IsMoveBeingMade() const noexcept;

    GameObserver& operator = (const GameObserver&) = delete;
    GameObserver& operator = (GameObserver&&) = delete;

private:
    CellPointerPair m_CellPair{};
};
