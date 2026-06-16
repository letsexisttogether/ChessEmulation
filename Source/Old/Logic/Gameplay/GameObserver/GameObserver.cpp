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
        throw std::runtime_error
        { 
            "GameObserver: The move is now being made" 
        };
    }

    const BoardCell& firstRef = *m_CellPair.first;
    const BoardCell& secondRef = *m_CellPair.second;

    return { firstRef, secondRef };
}

BoardCell* GameObserver::GetInitial() noexcept
{
    return m_CellPair.first;
}

const BoardCell& GameObserver::GetInitial() 
    const noexcept(false)
{
    const BoardCell* initial = m_CellPair.first;

    if (!initial)
    {
        throw std::runtime_error
        { 
            "GameObserver: The initial cell was not set" 
        };
    }

    return *initial;
}

BoardCell* GameObserver::GetFinal() noexcept
{
    return m_CellPair.second;
}

const BoardCell& GameObserver::GetFinal() 
    const noexcept(false)
{
    const BoardCell* final = m_CellPair.second;

    if (!final)
    {
        throw std::runtime_error
        { 
            "GameObserver: The final cell was not set" 
        };
    }

    return *final;
}

void GameObserver::SetCell(BoardCell* cell) noexcept
{
    if (!m_CellPair.first)
    {
        if (!cell->IsFree())
        {
            m_CellPair.first = cell;
        }
    }
    else if (!m_CellPair.second)
    {
        m_CellPair.second = cell;
    }
}

void GameObserver::ClearCells() noexcept
{
    ClearInitial();
    ClearFinal();
}

void GameObserver::ClearInitial() noexcept
{
    m_CellPair.first = nullptr;
}
void GameObserver::ClearFinal() noexcept
{
   m_CellPair.second = nullptr;
}
    
bool GameObserver::IsMoveBeingMade() const noexcept
{
    return m_CellPair.first && m_CellPair.second;
}
