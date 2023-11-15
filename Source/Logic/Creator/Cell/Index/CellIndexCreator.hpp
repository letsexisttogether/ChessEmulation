#pragma once

#include "Logic/Board/Cell/Index/BoardCellIndex.hpp"
#include "Spawn/Default/Consecutive/ConsecutiveCreator.hpp"

class CellIndexCreator : public ConsecutiveSpawner<BoardCellIndex>
{
public:
    using Super = ConsecutiveSpawner<BoardCellIndex>;

public:
    CellIndexCreator() = delete;
    CellIndexCreator(const CellIndexCreator&) = default;
    CellIndexCreator(CellIndexCreator&&) = default;

    CellIndexCreator(const BoardCellIndex& start, const BoardCellIndex& step,
            const BoardCellIndex& lowest, const BoardCellIndex& highest);

    ~CellIndexCreator() = default;

    CellIndexCreator& operator = (const CellIndexCreator&) = delete;
    CellIndexCreator& operator = (CellIndexCreator&&) = delete;

protected:
    void ChangeNextInstance() noexcept(false) override;

    bool CheckColumnBoundries() const noexcept override;
    bool CheckRowBoundries() const noexcept override;
};
