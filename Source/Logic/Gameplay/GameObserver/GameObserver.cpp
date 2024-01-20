#include "GameObserver.hpp"

#include <stdexcept>

const GameObserver::CellPointerPair& GameObserver::GetCellPair() 
    noexcept
{
    return m_CellPair;
}

GameObserver::CellReferencePair GameObserver::GetCellPair() 
    const noexcept(false)
{
    if (!IsMoveBeingMade())
    {
        throw std::runtime_error{ "The move is now being made" };
    }

    const BoardCell& firstRef = *m_CellPair.first;
    const BoardCell& secondRef = *m_CellPair.second;

    return { firstRef, secondRef };
}

void GameObserver::SetCell(BoardCell* cell) noexcept
{
    if (!m_CellPair.first)
    {
        m_CellPair.first = cell;
    }
    else 
    {
        m_CellPair.second = cell;
    }
}

void GameObserver::ClearCells() noexcept
{
    m_CellPair.first = m_CellPair.second = nullptr;
}
    
bool GameObserver::IsMoveBeingMade() const noexcept
{
    return m_CellPair.first && m_CellPair.second;
}
