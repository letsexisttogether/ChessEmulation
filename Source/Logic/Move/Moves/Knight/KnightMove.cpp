#include "KnightMove.hpp"
#include "Logic/Match/Match.hpp"

KnightMove::KnightMove(const DefaultMove& defaultMove)
    : BasicMove{ defaultMove }
{}

MoveEffect KnightMove::Try(const Match& match) 
    const noexcept 
{
    const Board& board = match.GetBoard();

    const GameObserver& gameObserver = match.GetGameObserver();

    const BoardCell& initial = gameObserver.GetInitial();
    const BoardCell& final = gameObserver.GetFinal();
    
    if (IsBasicAdhered(match) && IsUnderDistance(initial, final))
    {
        return DefinePossibleMoveEffect(match);
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
