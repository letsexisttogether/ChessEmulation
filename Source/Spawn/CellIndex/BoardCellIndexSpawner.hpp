#pragma once

#include <type_traits>

#include "Logic/Board/Cell/Index/BoardCellIndex.hpp"
#include "Logic/Move/Moves/DefaultMove/DefaultMove.hpp"

class BoardCellIndexSpawner
{
public:
    BoardCellIndexSpawner() = delete;
    BoardCellIndexSpawner(const BoardCellIndexSpawner&) = default;
    BoardCellIndexSpawner(BoardCellIndexSpawner&&) = default;

    BoardCellIndexSpawner(const BoardCellIndex& starIndex, 
        const BoardCellIndex& endIndex, const MoveDirection direction);

    ~BoardCellIndexSpawner() = default;

    BoardCellIndex SpawnIndex() noexcept(false);

    bool IsDone() const noexcept;
    
private:
    BoardCellIndex m_CurrentIndex;
    const BoardCellIndex m_EndIndex;

    BoardCellIndex m_AdditionIndex;
    MoveDirection m_Direction;
};
