#include "KnightMove.hpp"

#include "Logic/Board/Board.hpp"

KnightMove::KnightMove(const DefaultMove& defaultMove)
    : BasicMove{ defaultMove }
{}

MoveEffect KnightMove::Try(const Board& board, 
    const BoardCell& initial, const BoardCell& final) 
    const noexcept(false)
{
    if (IsBasicAdhered(initial, final) 
        && IsUnderDistance(initial, final))
    {
        return DefinePossibleMoveEffect(initial, final);
    }

    return MoveEffect::NONE;
}

bool KnightMove::IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) const noexcept
{
    const DefaultMove possibleMove = initial - final;

    return m_DefaultMove == possibleMove; 
}

BasicMove* KnightMove::Clone() const noexcept
{
    return new KnightMove{ *this };
}
