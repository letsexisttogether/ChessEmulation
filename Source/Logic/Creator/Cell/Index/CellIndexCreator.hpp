#pragma once

#include "Logic/Board/Cell/Index/BoardCellIndex.hpp"

class CellIndexCreator
{
public:
    CellIndexCreator() = delete;
    CellIndexCreator(const CellIndexCreator&) = default;
    CellIndexCreator(CellIndexCreator&&) = default;

    CellIndexCreator(const BoardCellIndex& start, const BoardCellIndex& step,
            const BoardCellIndex& lowest, const BoardCellIndex& highest);

    ~CellIndexCreator() = default;

    BoardCellIndex CreateIndex() noexcept(false);

    CellIndexCreator& operator = (const CellIndexCreator&) = default;
    CellIndexCreator& operator = (CellIndexCreator&&) = default;

private:
    void ChangeNextIndex() noexcept(false);

    bool CheckFileBoundries() const noexcept;
    bool CheckRankBoundries() const noexcept;
    
private:
    BoardCellIndex m_NextIndex;

    const BoardCellIndex m_Step;

    const BoardCellIndex m_Start;

    const BoardCellIndex m_Lowest;
    const BoardCellIndex m_Highest;
};
