#include "KnightMove.hpp"
#include <iostream>

KnightMove::KnightMove(const DefaultMove& defaultMove)
    : TransferMove{ defaultMove }
{}


BasicMove* KnightMove::Clone() const noexcept
{
    return new KnightMove{ *this };
}

bool KnightMove::IsUnderDistance(BoardCell& initial, 
    BoardCell& final) const noexcept 
{
    const DefaultMove possibleMove = final - initial;

    return m_DefaultMove == possibleMove; 
}

bool KnightMove::IsAnyObstacles(Board& board, BoardCell& initial, 
    BoardCell& final) const noexcept
{
    return false;
}

