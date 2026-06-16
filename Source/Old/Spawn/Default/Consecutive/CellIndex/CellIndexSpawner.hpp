#pragma once

#include "Logic/Board/Cell/Index/BoardCellIndex.hpp"
#include "Spawn/Default/Consecutive/ConsecutiveSpawner.hpp"

class CellIndexSpawner : public ConsecutiveSpawner<BoardCellIndex>
{
public:
    using Super = ConsecutiveSpawner<BoardCellIndex>;

public:
    CellIndexSpawner() = delete;
    CellIndexSpawner(const CellIndexSpawner&) = default;
    CellIndexSpawner(CellIndexSpawner&&) = default;

    CellIndexSpawner(const BoardCellIndex& start, const BoardCellIndex& step,
            const BoardCellIndex& lowest, const BoardCellIndex& highest);

    ~CellIndexSpawner() = default;

    CellIndexSpawner& operator = (const CellIndexSpawner&) = delete;
    CellIndexSpawner& operator = (CellIndexSpawner&&) = delete;

protected:
    void ChangeNextInstance() noexcept(false) override;

    bool CheckColumnBoundries() const noexcept override;
    bool CheckRowBoundries() const noexcept override;
};
