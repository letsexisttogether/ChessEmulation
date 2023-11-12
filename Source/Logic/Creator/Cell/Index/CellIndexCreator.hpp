#pragma once

#include "Logic/Board/Cell/Index/BoardCellIndex.hpp"
#include "Logic/Creator/Consecutive/ConsecutiveCreator.hpp"

class CellIndexCreator : public ConsecutiveCreator<BoardCellIndex>
{
public:
    CellIndexCreator() = delete;
    CellIndexCreator(const CellIndexCreator&) = default;
    CellIndexCreator(CellIndexCreator&&) = default;

    CellIndexCreator(const BoardCellIndex& start, const BoardCellIndex& step,
            const BoardCellIndex& lowest, const BoardCellIndex& highest);

    ~CellIndexCreator() = default;

    CellIndexCreator& operator = (const CellIndexCreator&) = default;
    CellIndexCreator& operator = (CellIndexCreator&&) = default;

protected:
    void ChangeNextInstance() noexcept(false) override;

    bool CheckColumnBoundries() const noexcept override;
    bool CheckRowBoundries() const noexcept override;
};
