#include "KnightMove.hpp"
#include <iostream>

KnightMove::KnightMove(const DefaultMove& defaultMove)
    : TransferMove{ defaultMove }
{}

BasicMove* KnightMove::Clone() const noexcept
{
    return new KnightMove{ *this };
}

bool KnightMove::IsUnderDistance(const BoardCell& initial, 
    const BoardCell& final) const noexcept 
{
    const DefaultMove possibleMove = final - initial;

    return m_DefaultMove == possibleMove; 
}

bool KnightMove::IsAnyObstacles(const Board& board,
    const BoardCell& initial, const BoardCell& final) 
    const noexcept
{
    return false;
}

