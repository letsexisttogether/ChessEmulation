#pragma once

#include "Logic/Board/Cell/Index/BoardCellIndex.hpp"

class BoardCell;

class WalkThrougher
{
public:
    WalkThrougher() = delete;
    WalkThrougher(const WalkThrougher&) = default;
    WalkThrougher(WalkThrougher&&) = default;
    
    WalkThrougher(const BoardCell& initial, const BoardCell& final,
        const BoardCellIndex& boundries);

    ~WalkThrougher() = default;

    const BoardCellIndex& GetNext() noexcept;

    bool IsEndReached() const noexcept;

    bool IsInBoundries() const noexcept;

    void Reset() noexcept;

private:
    const BoardCellIndex m_Start;
    const BoardCellIndex m_End;
    const BoardCellIndex m_Boundries;

    BoardCellIndex m_Index;
    BoardCellIndex m_Step{};
};
