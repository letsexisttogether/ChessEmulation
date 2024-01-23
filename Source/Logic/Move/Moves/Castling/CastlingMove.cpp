#include "CastlingMove.hpp"

#include "Logic/Match/Match.hpp"

CastlingMove::CastlingMove(const DefaultMove& defaultMove)
    : KnightMove{ defaultMove }
{}

MoveEffect CastlingMove::Try(const Match& match) 
    const noexcept 
{
    return BasicMove::Try(match);
}

BasicMove* CastlingMove::Clone() const noexcept
{
    return new CastlingMove{ *this };
}

MoveEffect CastlingMove::DefinePossibleMoveEffect(const Match& match) 
    const noexcept(false)
{
    const GameObserver::CellReferencePair cellPair
    { 
        match.GetGameObserver().GetCellPair() 
    };

    const BoardCell& initial = cellPair.first;
    const BoardCell& final = cellPair.second;

    if (!IsSameSide(initial, final))
    {
        return MoveEffect::NONE;
    }

    return MoveEffect::CASTLE;
}

bool CastlingMove::IsBasicAdhered(const Match& match) const noexcept
{
    const GameObserver& gameObserver = match.GetGameObserver();

    if (gameObserver.IsMoveBeingMade())
    {
        return false;
    }

    const BoardCell& initial = gameObserver.GetInitial();
    const BoardCell& final = gameObserver.GetFinal();

    return !(initial.GetPiece().WasMoved()) 
        && !(final.GetPiece().WasMoved());
}

