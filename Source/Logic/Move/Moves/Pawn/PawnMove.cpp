#include "PawnMove.hpp"

#include <iostream>

#include "Logic/Board/Board.hpp"

PawnMove::PawnMove(const DefaultMove& defaultMove, 
    const DefaultMove& maximumStartMove)
    : BasicMove{ defaultMove }, 
    m_MaximumStartMove{ maximumStartMove }
{}

BasicMove* PawnMove::Clone() const noexcept
{
    return new PawnMove{ *this };
}

MoveEffect PawnMove::DefinePossibleMoveEffect(const BoardCell& initial,
    const BoardCell& final) const noexcept(false)
{
    if (BasicMove::DefinePossibleMoveEffect(initial, final) 
        != MoveEffect::NONE)
    {
        return MoveEffect::PIECE_TRANSFER;
    }

    return MoveEffect::NONE;
}

bool PawnMove::IsUnderDistance(const BoardCell& initial, 
    const BoardCell& final) const noexcept
{
    const DefaultMove possibleMove = initial - final;

    const bool isAllowedByDefault = (m_DefaultMove == possibleMove);

    const bool isStarMove = (!initial.GetPiece().WasMoved()
        && m_MaximumStartMove == possibleMove);

    return isAllowedByDefault || isStarMove;
}

