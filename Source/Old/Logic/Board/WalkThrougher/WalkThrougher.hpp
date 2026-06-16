#pragma once

#include "Logic/Board/Cell/Index/BoardCellIndex.hpp"

class WalkThrougher
{
public:
    WalkThrougher() = delete;
    WalkThrougher(const WalkThrougher&) = default;
    WalkThrougher(WalkThrougher&&) = default;
    
    WalkThrougher(const BoardCellIndex& initial, 
        const BoardCellIndex& final, const BoardCellIndex& boundries);

    ~WalkThrougher() = default;

    const BoardCellIndex& GetNext() noexcept;

    const BoardCellIndex& GetIndex() noexcept;

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
