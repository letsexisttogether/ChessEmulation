#include "Logic/Move/Moves/DefaultMove/MoveDirection.hpp"
#include "Spawn/CellIndex/BoardCellIndexSpawner.hpp"

BoardCellIndexSpawner::BoardCellIndexSpawner(const BoardCellIndex& starIndex, 
    const BoardCellIndex& endIndex, const MoveDirection direction)
    : m_CurrentIndex{ starIndex }, m_EndIndex{ endIndex },
    m_AdditionIndex{ 1, 1 }, m_Direction{ direction }
{
    if (direction == MoveDirection::DOWN_RIGHT 
        || direction == MoveDirection::DOWN_LEFT
        || direction == MoveDirection::DOWN)
    {
        m_AdditionIndex.SetRank(-1);
    }

    if (direction == MoveDirection::UP_LEFT 
        || direction == MoveDirection::DOWN_LEFT 
        || direction == MoveDirection::LEFT)
    {
        m_AdditionIndex.SetFile(-1);
    }
}

BoardCellIndex BoardCellIndexSpawner::SpawnIndex() noexcept(false)
{
    BoardCellIndex index{ m_CurrentIndex };

    m_CurrentIndex += m_AdditionIndex;

    return index;
}

bool BoardCellIndexSpawner::IsDone() const noexcept
{
    return m_CurrentIndex == m_EndIndex;
}
