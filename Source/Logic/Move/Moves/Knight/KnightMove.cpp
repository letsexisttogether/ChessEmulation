#include "KnightMove.hpp"
#include "Logic/Match/Match.hpp"

KnightMove::KnightMove(const DefaultMove& defaultMove)
    : BasicMove{ defaultMove }
{}

MoveEffect KnightMove::Try(const Match& match) 
    const noexcept 
{
    const Board& board = match.GetBoard();

    const GameObserver::CellReferencePair cellPair
    { 
        match.GetGameObserver().GetCellPair() 
    };
    const BoardCell& initial = cellPair.first;
    const BoardCell& final = cellPair.second;
    
    if (IsUnderDistance(initial, final))
    {
        return DefinePossibleMoveEffect(match);
    }

    return MoveEffect::NONE;
}

bool KnightMove::IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) const noexcept
{
    const DefaultMove possibleMove = initial - final;

    const DefaultMove::Distance& allowedDistance = 
        m_DefaultMove.GetDistance();
    const DefaultMove::Distance& possibleMoveDistance = 
        possibleMove.GetDistance();

    const bool isDistanceTheSame = 
        (allowedDistance.first == possibleMoveDistance.first)
        && (allowedDistance.second == possibleMoveDistance.second);

    const bool isSameDirection = 
        (m_DefaultMove.GetDirection() == possibleMove.GetDirection());

    return isSameDirection && isDistanceTheSame;
}

BasicMove* KnightMove::Clone() const noexcept
{
    return new KnightMove{ *this };
}
